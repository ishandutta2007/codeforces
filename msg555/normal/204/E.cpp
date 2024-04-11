#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 210000

int AN;
int A[3 * MAXN + 100];
int cnt[MAXN + 1]; // Should be >= 256
int SA[MAXN + 1];

/* Used by suffix_array. */
void radix_pass(int* A, int AN, int* R, int RN, int* D) {
  memset(cnt, 0, sizeof(int) * (AN + 1));
  int* C = cnt + 1;
  for(int i = 0; i < RN; i++) ++C[A[R[i]]];
  for(int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
  for(int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
}

/* DC3 in O(N) using 20N bytes of memory.  Stores the suffix array of the string
 * [A,A+AN) into SA where SA[i] (0<=i<=AN) gives the starting position of the
 * i-th least suffix of A (including the empty suffix).
 */
void suffix_array(int* A, int AN) {
  // Base case... length 1 string.
  if(!AN) {
    SA[0] = 0;
  } else if(AN == 1) {
    SA[0] = 1; SA[1] = 0;
    return;
  }

  // Sort all strings of length 3 starting at non-multiples of 3 into R.
  int RN = 0;
  int* SUBA = A + AN + 2;
  int* R = SUBA + AN + 2;
  for(int i = 1; i < AN; i += 3) SUBA[RN++] = i;
  for(int i = 2; i < AN; i += 3) SUBA[RN++] = i;
  A[AN + 1] = A[AN] = -1;
  radix_pass(A + 2, AN - 2, SUBA, RN, R);
  radix_pass(A + 1, AN - 1, R, RN, SUBA);
  radix_pass(A + 0, AN - 0, SUBA, RN, R);

  // Compute the relabel array if we need to recursively solve for the
  // non-multiples.
  int resfix, resmul, v;
  if(AN % 3 == 1) {
    resfix = 1; resmul = RN >> 1;
  } else {
    resfix = 2; resmul = RN + 1 >> 1;
  }
  for(int i = v = 0; i < RN; i++) {
    v += i && (A[R[i - 1] + 0] != A[R[i] + 0] ||
               A[R[i - 1] + 1] != A[R[i] + 1] ||
               A[R[i - 1] + 2] != A[R[i] + 2]);
    SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
  }

  // Recursively solve if needed to compute relative ranks in the final suffix
  // array of all non-multiples.
  if(v + 1 != RN) {
    suffix_array(SUBA, RN);
    SA[0] = AN;
    for(int i = 1; i <= RN; i++) {
      SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) :
                3 * (SA[i] - resmul) + resfix;
    }
  } else {
    SA[0] = AN;
    memcpy(SA + 1, R, sizeof(int) * RN);
  }

  // Compute the relative ordering of the multiples.
  int NMN = RN;
  for(int i = RN = 0; i <= NMN; i++) {
    if(SA[i] % 3 == 1) {
      SUBA[RN++] = SA[i] - 1;
    }
  }
  radix_pass(A, AN, SUBA, RN, R);

  // Compute the reverse SA for what we know so far.
  for(int i = 0; i <= NMN; i++) {
    SUBA[SA[i]] = i;
  }

  // Merge the orderings.
  int ii = RN - 1;
  int jj = NMN;
  int pos;
  for(pos = AN; ii >= 0; pos--) {
    int i = R[ii];
    int j = SA[jj];
    int v = A[i] - A[j];
    if(!v) {
      if(j % 3 == 1) {
        v = SUBA[i + 1] - SUBA[j + 1];
      } else {
        v = A[i + 1] - A[j + 1];
        if(!v) v = SUBA[i + 2] - SUBA[j + 2];
      }
    }
    SA[pos] = v < 0 ? SA[jj--] : R[ii--];
  }
}

char s[MAXN + 1];

/* Copies the string in s into A and reduces the characters as needed. */
void prep_string() {
  int v = AN = 0;
  memset(cnt, 0, 256 * sizeof(int));
  for(char* ss = s; *ss; ++ss, ++AN) cnt[*ss]++;
  for(int i = 0; i < AN; i++) cnt[s[i]]++;
  for(int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
  for(int i = 0; i < AN; i++) A[i] = cnt[s[i]];
}

/* Computes the reverse SA index.  REVSA[i] gives the index of the suffix
 * starting a i in the SA array.  In other words, REVSA[i] gives the number of
 * suffixes before the suffix starting at i.  This can be useful in itself but
 * is also used for compute_lcp().
 */
int REVSA[MAXN + 1];
void compute_reverse_sa() {
  for(int i = 0; i <= AN; i++) {
    REVSA[SA[i]] = i;
  }
}

/* Computes the longest common prefix between adjacent suffixes.  LCP[i] gives
 * the longest common suffix between the suffix starting at i and the next
 * smallest suffix.  Runs in O(N) time.
 */
int LCP[MAXN + 1];
void compute_lcp() {
  int len = 0;
  for(int i = 0; i < AN; i++, len = max(0, len - 1)) {
    int s = REVSA[i];
    int j = SA[s - 1];
    for(; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
    LCP[s] = len;
  }
}

int cache[MAXN];
int ID[MAXN];

void precompute(int K) {
  memset(cache, 0, sizeof(cache));

  vector<pair<int, int> > ar;
  vector<int> lft, rht;
  vector<set<int> > st;
  for(int i = 0; i <= AN; i++) {
    lft.push_back(i);
    rht.push_back(i);
    st.push_back(set<int>());
    if(ID[SA[i]]) {
      st[i].insert(ID[SA[i]]);
    }
    ar.push_back(make_pair(LCP[i], i));
  }
  sort(ar.begin(), ar.end());

  for(int i = AN; i >= 0; i--) {
    if(ar[i].first == 0) break;
    int l2 = ar[i].second;
    int r2 = rht[l2];
    int r1 = l2 - 1;
    int l1 = lft[r1];

    if(st[l1].size() < st[l2].size()) st[l1].swap(st[l2]);
    for(typeof(st[l2].begin()) it = st[l2].begin(); it != st[l2].end(); it++) {
      st[l1].insert(*it);
    }
    st[l2].clear();

    if(st[l1].size() >= K) {
      if(cache[l1] == 0) for(int j = l1; j <= r1; j++) {
        cache[j] = ar[i].first;
      }
      if(cache[l2] == 0) for(int j = l2; j <= r2; j++) {
        cache[j] = ar[i].first;
      }
    }

    lft[r2] = l1;
    rht[l1] = r2;
  }
}

int main() {
  int N, K; cin >> N >> K;
  string st;
  vector<string> vs;
  memset(ID, 0, sizeof(ID));
  for(int i = 0; i < N; i++) {
    string ss; cin >> ss;
    vs.push_back(ss);
    st += (char)127;
    for(int j = 0; j < ss.size(); j++) ID[st.size() + j] = i + 1;
    st += ss;
  }
  memcpy(s, st.c_str(), st.size());
  s[st.size()] = 0;
  s[0] = 126;

  int pos = 0;
  prep_string();
  for(int i = 0; i < vs.size(); i++) {
    A[pos] = A[0] + i;
    pos += 1 + vs[i].size();
  }

  suffix_array(A, AN);
  compute_reverse_sa();
  compute_lcp();

  if(K != 1) precompute(K);
  
  pos = 0;
  for(int i = 0; i < vs.size(); i++) {
    pos++;
    long long res = 0;
    for(int j = 0; j < vs[i].size(); j++, pos++) {
      res += K == 1 ? j + 1 : cache[REVSA[pos]];
    }
    if(i) cout << ' ';
    cout << res;
  }
  cout << endl;
}