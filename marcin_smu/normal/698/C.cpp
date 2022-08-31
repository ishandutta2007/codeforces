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

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int n,k;
LD in[21],pr[1<<21];
LD dp[1<<21];
LD res[21];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  int nn = n;
  R(i,n){
    cin >> in[i];
    if(in[i] < 1e-6)
      nn--;
  }
  mini(k,nn);
  dp[0] = 1;
  pr[0] = 0;
  for(int mb = 1; mb < (1 << n); mb++){
    R(i,n)if((mb >> i)&1)if(in[i]){
      pr[mb] = in[i] + pr[mb - (1 << i)];
      dp[mb] += dp[mb - (1 << i)] * in[i] / (1 - pr[mb - (1 << i)]);
    }
    if(__builtin_popcount(mb) == k){
      R(i,n)if((mb >> i)&1){
        res[i] += dp[mb];
      }
    }
  }
  R(i,n){
    cout << res[i] << "\n";
  }
}