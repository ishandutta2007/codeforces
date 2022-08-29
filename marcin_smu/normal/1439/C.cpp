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
vector<int> m;
vector<int> ma;
vector<int> sum;
vector<int> lazy;

void ust(int x,int war,int sze){
  lazy[x] = war;
  sum[x] = war * sze;
  m[x] = war;
  ma[x] = war;
}
void licz(int v){
  m[v] = min(m[v * 2], m[v*2 + 1]); 
  ma[v] = max(ma[v * 2], ma[v*2 + 1]); 
  sum[v] = sum[v*2] + sum[v * 2 + 1];
}
void touch(int v,int sze){
  if(lazy[v]){
    ust(v*2,lazy[v],sze);
    ust(v*2+1,lazy[v],sze);
    lazy[v] = 0;
  }

}
int licz(int x,int kasa){
  function<int(int,int,int)> sumpref = [&](int v,int po,int ko){
    if(po >= x)return 0ll;
    if(ko <= x)return sum[v];
    touch(v,(ko - po) / 2);
    return sumpref(v*2, po, (po + ko) /2) + sumpref(v * 2 + 1, (po + ko)/2,ko);
  };
  kasa += sumpref(1,0,nn);
  debug(kasa);
  int ak = 1;
  int sze = nn;
  while(ak < nn){
    sze/=2;
    touch(ak,sze);
    if(sum[ak * 2] > kasa){
      ak *= 2;
    }else{
      kasa -= sum[ak * 2];
      ak *= 2;
      ak ++;
    }
  }
  int gd = ak - nn;
  debug(gd);
  if(gd >= n)return n - x;
  int pom = gd - x;
  ak = 1;
  sze = nn;
  while(ak < nn){
    sze/=2;
    touch(ak,sze);
    if(m[ak * 2] <= kasa){
      ak *= 2;
    }else{
      ak *= 2;
      ak ++;
    }
  }
  int gd2 = ak - nn;
  if(gd2 >= n)return pom;
  return licz(gd2, kasa) + pom;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  nn = 1;
  while(nn <= n)nn*=2;
  m.resize(nn * 2);
  ma.resize(nn * 2);
  sum.resize(nn * 2);
  lazy.resize(nn * 2);
  R(i,n){
    cin >> m[nn + i];
    sum[nn+i] = ma[nn+i] = m[nn + i];
  }
  for(int i = nn - 1; i >= 0; i--){
    licz(i);
  }
  R(i,q){
    int t;
    cin >> t;
    if(t == 1){
      int x,y;
      cin >> x >> y;
      function<void(int,int,int)> rec = [&](int v,int po,int ko){
        if(po >= x || m[v] >= y)return;
        if(ko <= x && ma[v] <= y){
          debug(v,y,po,ko);
          ust(v, y, ko - po);
          return;
        }
        touch(v,(ko - po) / 2);
        rec(v*2, po, (po + ko) /2);
        rec(v*2+1, (po + ko)/2,ko);
        licz(v);
      };
      rec(1,0,nn);
    }else{
      int x;
      int kasa;
      cin >> x >> kasa;
      cout << licz(x-1,kasa) << "\n";
    }
  }
}