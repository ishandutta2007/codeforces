#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

#define MOD 1000000007

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

int N;
vector<int> SA;
vector<int> RA;

void compress(vector<int>& V, vector<int>& C) {
  copy(V.begin(), V.end(), C.begin());
  sort(C.begin(), C.end());
  auto cend = unique(C.begin(), C.end());
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
  LCP = vector<int>(N);
  int len = 0;
  for(int i = 0; i < N; i++, len = max(0, len - 1)) {
    int si = RA[i];
    int j = SA[si - 1];
    for(; i + len < N && j + len < N && OV[i + len] == OV[j + len]; len++);
    LCP[si - 1] = len;
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
}
  
vector<int> LCP;
};

#define MAXN 500000

int slen[MAXN];
int sind[MAXN][3];
int R[MAXN];

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  s1 += '!';
  s2 += '@';
  string s = s1 + s2 + s3;
  suffix_array sa(s.c_str());

  int spos = 0;
  int ind[3] = {0, 0, 0};
  for(int i = 0; i <= sa.N; i++) {
    int lcp = i == sa.N ? 0 : sa.LCP[i];
    if(lcp > slen[spos]) {
      spos++;
      slen[spos] = sa.LCP[i];
      memcpy(sind[spos], ind, sizeof(ind));
    }

    int type = -1;
    if(sa.SA[i] < s1.size()) {
type = 0;
      ind[0]++;
    } else if(sa.SA[i] < s1.size() + s2.size()) {
type = 1;
      ind[1]++;
    } else {
type = 2;
      ind[2]++;
    }
    //cout << lcp << ", " << sa.SA[i] << ", " << type << endl;

    while(lcp < slen[spos]) {
      int r = 1;
      for(int j = 0; j < 3; j++) {
        r = (1ll * r * (ind[j] - sind[spos][j])) % MOD;
      }
      R[slen[spos]] = (R[slen[spos]] + r) % MOD;
      if(lcp > slen[spos - 1]) {
        slen[spos] = lcp;
      } else {
        spos--;
      }
      R[slen[spos]] = (R[slen[spos]] + MOD - r) % MOD;
    }
  }

  int mx = min(s1.size() - 1, min(s2.size() - 1, s3.size()));
  for(int i = mx; i > 0; i--) {
    R[i - 1] = (R[i - 1] + R[i]) % MOD;
  }
  for(int i = 1; i <= mx; i++) {
    if(i > 1) cout << ' ';
    cout << R[i];
  }
  cout << endl;

  return 0;
}