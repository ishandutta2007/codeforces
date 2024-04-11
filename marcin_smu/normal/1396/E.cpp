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


void nope(){
  cout << "NO\n";
  exit(0);
}

const int MAX = 100010;
vector<PII> d[MAX];
int n,k;
int siz[MAX];
int minres = 0;
int maxres = 0;
vector<pair<int,PII*>> maks;
void dfs(int v,int oj){
  siz[v] = 1;
  for(PII &el:d[v])if(el.FI != oj){
    dfs(el.FI,v);
    siz[v] += siz[el.FI];
    if(siz[el.FI] & 1){
      el.SE ++;
      minres ++;
    }
    maxres += min(siz[el.FI], n - siz[el.FI]);
    maks.PB({min(siz[el.FI], n - siz[el.FI]),&el});
  }
}
vector<int> kt[MAX];
vector<PII> res;
void lacz(int a,int b){
  if(SZ(kt[a]) < SZ(kt[b]))swap(kt[a],kt[b]);
  for(int el:kt[b]){
    kt[a].PB(el);
  }
  vector<int> pusty;
  swap(kt[b],pusty);
}
void get(int v,int oj,int need){
  set<PII> secik;
  kt[v].PB(v);
  secik.insert({1, v});
  int all = 1;
  for(PII &el:d[v])if(el.FI != oj){
    get(el.FI, v, el.SE);
    if(el.SE){
      all += el.SE;
      secik.insert({el.SE, el.FI});
    }
  }
  while(all != need){
    PII el1 = *secik.rbegin();
    secik.erase(el1);
    PII el2 = *secik.rbegin();
    secik.erase(el2);
    res.PB({kt[el1.SE].back(), kt[el2.SE].back()});
    kt[el1.SE].pop_back();
    kt[el2.SE].pop_back();
    el1.FI--;
    el2.FI--;
    if(el1.FI){
      secik.insert({el1});
    }
    if(el2.FI){
      secik.insert({el2});
    }
    all -= 2;
  }
  for(PII el:secik){
    if(el.SE != v){
      lacz(v,el.SE);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB({b,0});
    d[b].PB({a,0});
  }
  dfs(0,-1);
  debug(k,minres,maxres);
  if(minres % 2 != k % 2 || minres > k || maxres < k)nope();
  cout << "YES\n";
  sort(ALL(maks));
  debug(SZ(maks));
  R(i,n-1){
    if(maks[i].FI & 1)
      maks[i].FI--;
  }
  int ile = (k - minres) / 2;
  bool xxx = 0;
  int kazdy = 0;
  R(i,n-1){
    int ak;
    if(xxx){
      ak = kazdy;
    }else{
      int pom = maks[i].FI / 2;
      if(pom * (n - i - 1) <= ile)
        ak = pom;
      else{
        xxx = 1;
        ak = kazdy = ile / (n - i - 1);
      }
    }
    maks[i].SE->SE += ak * 2;
    debug(maks[i].SE->SE);
    ile -= ak;
  }
  for(int i = n - 2;i >= 0;i--){
    if(ile && maks[i].SE->SE % 2 == 0 && maks[i].SE->SE / 2 < maks[i].FI / 2){
      maks[i].SE->SE +=2;
      ile--;
    }
  }
  for(int i = n - 2;i >= 0;i--){
    if(ile && maks[i].SE->SE % 2 == 1 && maks[i].SE->SE / 2 < maks[i].FI / 2){
      maks[i].SE->SE +=2;
      ile--;
    }
  }
  get(0,-1, 0);
  for(PII el:res){
    cout << el.FI+1 << " " << el.SE+1 << "\n";
  }
}