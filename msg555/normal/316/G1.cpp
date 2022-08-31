#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct suffix_array {
suffix_array(const char* S) : N(strlen(S)) {
  vector<int> V;
  for(int i = 0; i < N; i++) V.push_back(S[i]);
  init(V);
}

suffix_array(const vector<int>& VV) : N(VV.size()) {
  vector<int> V(VV);
  init(V);
}

/* Get longest common prefix between two suffix-indicies. */
int lcp(int si, int sj) {
  if(sj < si) swap(si, sj);
  if(si == sj) return N - SA[si];
  int len = sj - si;
  int buck = 31 - __builtin_clz(len);
  return min(LCP_MRQ[buck][si], LCP_MRQ[buck][sj - (1 << buck)]);
}

/* Return <j, l> s.t. s[j] = c and s+j+1 shares the longest prefix with s+i.
 * Returns <0, 0> if no such index exists. */
pair<int, int> backstep(int i, int c) {
  typeof(BACK_START.begin()) it = BACK_START.find(c);
  if(it == BACK_START.end()) return make_pair(0, 0);
  int pi = it->second; ++it;
  int pj = it == BACK_START.end() ? N : it->second;
  
  int si = RA[i];
  int p = lower_bound(BACK_LIST.begin() + pi, BACK_LIST.begin() + pj, si) -
                  BACK_LIST.begin();
  pair<int, int> r(-1, -1);
  for(int k = p - 1; k <= p; k++) {
    if(k < pi || pj <= k) continue;
    int sj = BACK_LIST[k];
    r = max(r, make_pair(1 + lcp(si, sj), SA[sj] - 1));
  }
  return make_pair(r.second, r.first);
}

/* Returns the <index, match length> of the suffix with the longest shared
 * prefix with K.  Ties broken arbitrarily. */
template<typename T>
pair<int, int> find(const T* K, int KN) {
  int ind = 0, len = 0;
  for(int i = KN - 1; i >= 0; i--) {
    pair<int, int> res = backstep(ind, K[i]);
    ind = res.first;
    len = min(len + 1, res.second);
  }
  return make_pair(ind, len);
}

/* Figure out what range of ordered suffixes match the prefix s[i:i+dep).  Range
 * is of [) form in terms of suffix-indicies. */
pair<int, int> range(int i, int dep) {
  pair<int, int> sr(RA[i], RA[i]);
  for(int j = 31 - __builtin_clz(N + 1); j >= 0; j--) {
    int su = sr.first - (1 << j);
    int sv = sr.second + (1 << j);
    if(su >= 0 && lcp(su, sr.first ) >= dep) sr.first  = su;
    if(sv <= N && lcp(sv, sr.second) >= dep) sr.second = sv;
  }
  ++sr.second;
  return sr;
}

int N;
vector<int> SA;
vector<int> RA;

private:
void compress(vector<int>& V, vector<int>& C) {
  copy(V.begin(), V.end(), C.begin());
  sort(C.begin(), C.end());
  typeof(C.begin()) cend = unique(C.begin(), C.end());
  for(int i = 0; i < N; i++) {
    V[i] = lower_bound(C.begin(), cend, V[i]) - C.begin() + 1;
  }
  V.push_back(0); C.push_back(0);
}

void compute_sa(vector<int>& V, vector<int>& C) {
  vector<int> T(N + 1);
  for(int i = 0; i <= N; i++) SA.push_back(i);
  for(int ski = 0; V[SA[N]] < N; ski = ski ? ski << 1 : 1) {
    fill(C.begin(), C.end(), 0);
    for(int i = 0; i < ski; i++) T[i] = N - i;
    for(int i = 0, p = ski; i <= N; i++) if(SA[i] >= ski) T[p++] = SA[i] - ski;
    for(int i = 0; i <= N; i++) C[V[i]]++;
    for(int i = 1; i <= N; i++) C[i] += C[i - 1];
    for(int i = N; i >= 0; i--) SA[--C[V[T[i]]]] = T[i];
    
    T[SA[0]] = 0;
    for(int j = 1; j <= N; j++) {
      int a = SA[j];
      int b = SA[j - 1];
      T[a] = T[b] + (a + ski >= N || b + ski >= N ||
                     V[a] != V[b] || V[a + ski] != V[b + ski]);
    }
    V.swap(T);
  }
}

void compute_lcp(const vector<int>& OV) {
  LCP_MRQ.push_back(vector<int>(N));
  int len = 0;
  for(int i = 0; i < N; i++, len = max(0, len - 1)) {
    int si = RA[i];
    int j = SA[si - 1];
    for(; i + len < N && j + len < N && OV[i + len] == OV[j + len]; len++);
    LCP_MRQ[0][si - 1] = len;
  }
  for(int i = 1; 1 << i <= N; i++) {
    LCP_MRQ.push_back(vector<int>());
    const vector<int>& plcp = LCP_MRQ[i - 1];
    for(int j = 0; j + (1 << i) <= N; j++) {
      LCP_MRQ[i].push_back(min(plcp[j], plcp[j + (1 << i - 1)]));
    }
  }
}

void compute_backsteps(const vector<int>& OV) {
  int add = 0;
  for(int i = 0; i < OV.size(); i++) ++BACK_START[OV[i]];
  for(typeof(BACK_START.begin()) it = BACK_START.begin();
      it != BACK_START.end(); it++) {
    add += it->second;
    it->second = add;
  }
  BACK_LIST.resize(N);
  for(int si = N; si >= 0; si--) {
    int i = SA[si] - 1;
    if(i >= 0) BACK_LIST[--BACK_START[OV[i]]] = si;
  }
}

void init(vector<int>& V) {
  vector<int> OV(V);
  vector<int> C(N);
  compress(V, C);
  compute_sa(V, C);
  RA.resize(N + 1);
  for(int i = 0; i <= N; i++) RA[SA[i]] = i;
  compute_lcp(OV);
  compute_backsteps(OV);
}
  
vector<vector<int> > LCP_MRQ;
map<int, int> BACK_START;
vector<int> BACK_LIST;
};

int LO[20];
int HI[20];
int SLO[20];
int SHI[20];
int M;
string S;
string T[20];
vector<int> CSUM[20];

int find_m(suffix_array& sa, int p, int x, int occ) {
  int lo = x;
  int hi = M + 1;
  while(lo < hi) {
    int md = (lo + hi) / 2;

    pair<int, int> rn = sa.range(x, md - x + 1);
    if(CSUM[p][rn.second] - CSUM[p][rn.first] <= occ) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  return lo;
}

int main() {
  cin >> S;
  M = S.size();

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
    S += '?';
    SLO[i] = S.size();
    SHI[i] = SLO[i] + T[i].size();
    S += T[i];
    cin >> LO[i] >> HI[i];
  }

  suffix_array sa(S.c_str());
  for(int i = 0; i < N; i++) CSUM[i].push_back(0);
  for(int i = 0; i <= S.size(); i++) {
    for(int j = 0; j < N; j++) {
      CSUM[j].push_back(CSUM[j][i]);
      if(SLO[j] <= sa.SA[i] && sa.SA[i] < SHI[j]) {
        CSUM[j][i + 1]++;
      }
    }
  }

  vector<pair<int, pair<int, int> > > res;
  for(int i = 0; i < M; i++) {
    int mnln = i;
    int mxln = M;
    for(int j = 0; j < N; j++) {
      mnln = max(mnln, find_m(sa, j, i, HI[j]));
      if(LO[j] != 0) {
        mxln = min(mxln, find_m(sa, j, i, LO[j] - 1));
      }
    }
    if(mnln < mxln) {
      res.push_back(make_pair(sa.RA[i], make_pair(mnln - i, mxln - i)));
    }
  }
  sort(res.begin(), res.end());

  long long result = 0;
  for(int i = 0; i < res.size(); i++) {
    int lp = i + 1 < res.size() ? sa.lcp(res[i].first, res[i + 1].first) : 0;
    result += max(lp, res[i].second.second) - max(lp, res[i].second.first);
  }

  cout << result << endl;
  return 0;
}