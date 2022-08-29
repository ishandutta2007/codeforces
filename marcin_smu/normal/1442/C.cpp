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
const int P = 998244353;
const int C = 21;
int n,m;
vector<vector<int>> d;
vector<vector<int>> drev;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
struct xx{
  int kr;
  int rev;
  bool operator<(const xx pom)const{
    if(rev > C || pom.rev > C){
      if(rev != pom.rev)
        return rev < pom.rev;
      else
        return kr < pom.kr;
    }
    int a = (1 << rev) + kr;
    int b = (1 << pom.rev) + pom.kr;
    if(a != b)
      return a < b;
    return rev < pom.rev;
  }
  
  bool operator!=(const xx pom)const{
    return kr != pom.kr || rev != pom.rev;
  }
  void wys(){
    int p2 = 1;
    R(i,rev){
      add(kr,p2);
      add(p2,p2);
    }
    cout << kr << "\n";
  }
};
const xx inf = {(int)1e9, (int)1e9};
vector<vector<xx>> odl; 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  d.resize(n);
  drev.resize(n);
  odl.resize(C,vector<xx>(n,inf));
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    drev[b].PB(a);
  }
  set<pair<xx,int>> secik;
  function<void(int,int,int)> dodaj = [&](int v,int kr,int rev){
    int pom = min(rev,C-1);
    if((rev & 1) != (pom & 1))
      pom--;
    if(xx{kr, rev} < odl[pom][v]){
      odl[pom][v] = {kr, rev};
      secik.insert({{kr, rev},v});
    }
  };
  dodaj(0,0,0);
  while(!secik.empty()){
    auto pom = *secik.begin();
    secik.erase(secik.begin());
    int rev = pom.FI.rev;
    int kr = pom.FI.kr;
    int q = min(rev,C-1);
    if((rev & 1) != (q & 1))
      q--;
    int v = pom.SE;
    if(pom.FI != odl[q][v])continue;
    if(v == n-1){
      pom.FI.wys();
      return 0;
    }
    int cza = rev & 1;
    for(int el:d[v]){
      dodaj(el, kr + 1, rev + cza);
    }
    cza = !cza;
    for(int el:drev[v]){
      dodaj(el, kr + 1, rev + cza);
    }
  }
  assert(0);
}