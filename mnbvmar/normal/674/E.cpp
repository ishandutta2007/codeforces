#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif

const int MaxQ = 500005;
const int K = 70;

LD probabNot[MaxQ][K];
int parent[MaxQ];
int nverts = 1;

void update(int v) {
  probabNot[v][0] = 0;
  LD veryold, old;
  
  for (int k = 1; k < K; k++) {
    int p = parent[v];
    if (!p) { return; }
    
    old = probabNot[p][k];
    
    if (k == 1) {
      probabNot[p][k] *= 0.5 * (1 + probabNot[p][k - 1]);
    } else {
      probabNot[p][k] /= (1 + veryold);
      probabNot[p][k] *= (1 + probabNot[v][k - 1]);
    }
    debug(p, k, probabNot[p][k]);
    
    veryold = old;
    v = p;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  int Q;
  cin >> Q;
  for (int i = 0; i <= Q; i++) {
    fill(probabNot[i], probabNot[i] + K, (LD)(1));
  }
  parent[1] = 0;
  probabNot[1][0] = 0;
  
  for (int i = 0; i < Q; i++) {
    int type, v;
    cin >> type >> v;
    debug(type, v);
    
    if (type == 1) {
      nverts++;
      parent[nverts] = v;
      update(nverts);
    } else {
      LD result = 0;
      for (int j = 1; j < K; j++) {
        result += (1 - probabNot[v][j]);
      }
      cout << result << "\n";
    }
  }
}