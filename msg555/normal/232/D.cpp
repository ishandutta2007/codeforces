#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 200010

#define BMAXN (1 << 18)
int BT[BMAXN];

void bit_add(int x, int v) {
  for(int i = x | BMAXN; i < (BMAXN << 1); i += i & -i) {
    BT[i ^ BMAXN] += v;
  }
}

int bit_get(int x) {
  int ret = BT[0];
  for(int i = x; i; i &= i - 1) ret += BT[i];
  return ret;
}

/* Precompute in O(N Log N) time the MRQ array for [A,A+AN). */
int MRQ[20][MAXN];
void mrq_prep(int* A, int AN) {
  for(int i = 0; i < AN; i++) MRQ[0][i] = A[i];
  for(int i = 1; 1 << i <= AN; i++) {
    for(int j = 0; j + (1 << i) <= AN; j++) {
      MRQ[i][j] = min(MRQ[i - 1][j], MRQ[i - 1][j + (1 << i - 1)]);
    }
  }
}

/* Query the min value in the range [a,b). */
int mrq_query(int a, int b) {
  int len = b - a;
  int buck = 31 - __builtin_clz(len);
  return min(MRQ[buck][a], MRQ[buck][b - (1 << buck)]);
}

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
 * the longest common suffix between the suffix starting at i and the suffix
 * starting at i - 1.  Runs in O(N) time.
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

/* Figure out what range of ordered suffixes match the prefix s[x:x+dep).  Range
 * is of [) form. */
pair<int, int> sa_range(int x, int dep) {
  pair<int, int> r(REVSA[x], REVSA[x] + 1);
  for(int i = 31 - __builtin_clz(AN + 1); i >= 0; i--) {
    int u = r.first - (1 << i);
    int v = r.second + (1 << i);
    if(u >= 0  && mrq_query(u, r.first)  >= dep) r.first  = u;
    if(v <= AN && mrq_query(r.second - 1, v - 1) >= dep) r.second = v;
  }
  return r;
}

int B[MAXN];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> B[i];
  N--;

  vector<int> VS;
  A[N] = 0x7FFFFFFF;
  for(int i = 0; i < N; i++) {
    A[i] = B[i + 1] - B[i];
    A[N + i + 1] = -A[i];
    VS.push_back(A[i]);
    VS.push_back(-A[i]);
  }
  VS.push_back(A[N]);
  sort(VS.begin(), VS.end());
  VS.resize(unique(VS.begin(), VS.end()) - VS.begin());

  AN = 2 * N + 1;
  for(int i = 0; i < AN; i++) {
    A[i] = lower_bound(VS.begin(), VS.end(), A[i]) - VS.begin();
  }

  suffix_array(A, AN);
  compute_reverse_sa();
  compute_lcp();
  mrq_prep(LCP + 1, AN);

  int M; cin >> M;
  vector<pair<pair<int, pair<int, int> >, pair<int, int> > > R;
  for(int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    int sz = v - u + 1;
    pair<int, int> rng = sa_range(u, sz - 1);
    R.push_back(make_pair(make_pair(u - sz, make_pair(i, 1)), rng));
    R.push_back(make_pair(make_pair(v, make_pair(i, -1)), rng));
    R.push_back(make_pair(make_pair(N, make_pair(i, 1)), rng));
  }
  sort(R.begin(), R.end());

  int j = 0;
  vector<int> ans(M, 0);
  memset(BT, 0, sizeof(BT));
  for(int i = 0; i < R.size(); i++) {
    for(; j <= R[i].first.first; j++) {
      bit_add(REVSA[N + 1 + j] + 1, 1);
    }
    int ind = R[i].first.second.first;
    int mul = R[i].first.second.second;
    pair<int, int> rng = R[i].second;
    ans[ind] += mul * (bit_get(rng.second) - bit_get(rng.first));
  }

  for(int i = 0; i < M; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}