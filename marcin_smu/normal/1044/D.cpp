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

int q;
map<int,int> skal;
vector<int> f;
vector<int> war;
vector<int> siz;
int ile;
int get_id(int x){
  auto xxx = skal.find(x);
  if(xxx != skal.end())return xxx->SE;
  skal[x] = ile;
  ile++;
  return ile-1;
}
PII find(int x){
  if(f[x] == x){
    return {x,0ll};
  }else{
    PII res = find(f[x]);
    res.SE ^= war[x];
    return res;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> q;
  f.resize(q * 2);
  war.resize(q * 2);
  siz.resize(q * 2,1);
  R(i,2*q)f[i] = i;
  int last = 0;
  R(i,q){
    int typ,l,r;
    cin >> typ >> l >> r;
    l ^= last;
    r ^= last;
    if(l > r)swap(l,r);
    r++;
    l = get_id(l);
    r = get_id(r);
    debug(typ,l,r);
    PII x = find(l);
    PII y = find(r);
    int res = -1;
    debug(x,y);
    if(x.FI == y.FI){
      res = x.SE ^ y.SE;
    }
    debug(res);
    if(typ == 1){
      int res2;
      cin >> res2;
      res2 ^= last;
      if(res == -1){
        debug("union",x.FI, y.FI);
        if(siz[x.FI] > siz[y.FI])swap(x,y);
        f[x.FI] = y.FI;
        war[x.FI] = x.SE ^ y.SE ^ res2;
        siz[y.FI] += siz[x.FI];
      }
    }else{
      cout << res << "\n";
      if(res == -1){
        last = 1;
      }else{
        last = res;
      }
    }
  }
}