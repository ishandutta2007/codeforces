#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 200100;
int n;
PII t[MAX];
int id = 1;
int dp[MAX];
void add(int x){
  for(;x <= id;x+=x&-x){
    dp[x]++;
  }
}
int sum(int x){
  int res = 0;
  for(;x;x-=x&-x){
    res += dp[x];
  }
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  map<int,int> scal;
  R(i,n){
    cin >> t[i].FI >> t[i].SE;
    scal[t[i].FI] = 0;
  }
  for(auto& el:scal){
    el.SE = id;
    id++;
  }
  R(i,n){
    t[i].FI = scal[t[i].FI];
  }
  sort(t,t+n,[](PII x,PII y){
    if(x.SE != y.SE){
      return x.SE > y.SE;
    }
    return x.FI < y.FI;
  });
  int res = 0;
  set<int> secik;
  R(i,n){
    if(i && t[i] == t[i-1])continue;
    if(secik.insert(t[i].FI).SE)add(t[i].FI);
    int przed = sum(t[i].FI - 1);
    if(i != n-1 && t[i].SE == t[i+1].SE){
      debug(przed,sum(t[i+1].FI - 1));
      res += (przed + 1) * (sum(t[i+1].FI - 1) - przed);
    }else{
      res += (przed + 1) * (SZ(secik) - przed);
    }    
    debug(res,SZ(secik));
  }
  cout << res << "\n";
}