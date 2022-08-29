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
const int MAX = 201000;
int n,m,q;
int p[MAX],t[MAX],ost[MAX];
vector<int> a,r;
vector<int> zloz(vector<int>& x,vector<int>& y){
  vector<int> res(m + 1);
  R(i,m + 1){
    res[i] = y[x[i]];
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> q;
  R(i,n){
    int pom;
    cin >> pom;
    pom--;
    p[pom] = i;
    ost[i] = m;
  }
  R(i,m){
    int pom;
    cin >> pom; pom--;
    t[i] = p[pom];
    cerr << t[i] << " ";
  }
  cerr << "\n";
  a.resize(m + 1,m);
  for(int i = m-1; i>=0; i--){
    a[i] = ost[(t[i] + 1) % n]; 
    ost[t[i]] = i;
  }
  debug(a);
  r.resize(m + 1);
  R(i,m+1)r[i] = i;
  
  int w = n - 1;
  while(w){
    if(w & 1){
      r = zloz(a,r);
    }
    a = zloz(a,a);
    w/=2;
  }
  debug(r);
  for(int i = m - 1; i >= 0; i--){
    if(r[i + 1] < r[i])
      r[i] = r[i + 1];
  }
  string res(q,'0');
  R(i,q){
    int po,ko;
    cin >> po >> ko;
    po--;ko--;
    debug(po,ko,r[po]);
    if(r[po] <= ko){
      res[i] = '1';
    }
  }
  cout << res << "\n";
}