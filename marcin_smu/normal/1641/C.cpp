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

int n,q,nn;
vector<int> dp;

const int inf = 1e9;
void dodaj(int gd,int val){
  gd += nn;
  while(gd){
    mini(dp[gd], val);
    gd/=2;
  }
}
int get(int l,int r){
  function<int(int,int,int)> rec = [&](int v,int po,int ko) -> int{
    if(l >= ko || po >= r)return inf;
    if(l <= po && ko <= r){
      return dp[v];
    }
    return min(rec(v * 2, po, (po + ko)/ 2),
      rec(v * 2 + 1, (po + ko)/ 2, ko));
  };
  return rec(1,0,nn);
};
set<int> secik;
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  nn = 1;while(nn <= n)nn *= 2;
  dp.resize(nn * 2, inf);
  R(i,n){
    secik.insert(i);
  }
  secik.insert(-1);
  secik.insert(n);
  R(i,q){
    int typ;
    cin >> typ;
    if(typ == 0){
      int l,r,x;
      cin >> l >> r >> x;
      l--;
      if(x){
        dodaj(l, r);
      }else{
        auto xxx = secik.lower_bound(l);
        while(*xxx < r){
          secik.erase(xxx++);
        }
      }
    }else{
      int v;
      cin >> v;v--;
      auto xxx = secik.find(v);
      if(xxx == secik.end()){
        cout << "NO\n";
      }else{
        xxx++;
        int nast = *xxx;
        xxx--;xxx--;
        int pop = *xxx;
        if(get(pop + 1, v + 1) <= nast){
          cout << "YES\n";
        }else{
          cout << "N/A\n";
        }
      }
    }
  }
}