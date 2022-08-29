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

vector<PII> res;
vector<int> p;
void ruch(int a,int b){
  res.PB({a,b});
  p[a] *= -1;
  p[b] *= -1;
  swap(p[a],p[b]);
}
void rob(vector<int> a,vector<int> b){
  ruch(a[0],b[0]);
  R(i,SZ(a))if(i)ruch(a[i],b[0]);
  R(i,SZ(b))if(i)ruch(b[i],a[0]);
  ruch(a[0],b[0]);
}
void rob2(vector<int> a){
  if(SZ(a) == 2){
    int inny = 0;
    while(inny == a[0] || inny == a[1])inny ++;
    ruch(a[0],inny);
    ruch(a[1],inny);
    ruch(a[0],inny);
  }else{
    ruch(a[0], a[1]);
    ruch(a[1], a[2]);
    ruch(a[0], a[2]);
    for(int i = 3;i < SZ(a); i++)
      ruch(a[1], a[i]);
    ruch(a[0], a[1]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  p.resize(n);
  R(i,n){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> cykl;
  vector<int> vis(n);
  R(i,n)if(!vis[i]){
    int ak = i;
    vector<int> c;
    do{
      vis[ak] = 1;
      c.PB(ak);
      ak = p[ak];
    }while(ak != i);
    if(SZ(c) > 1)cykl.PB(c);
  }
  debug(cykl);
  R(i,SZ(cykl) / 2){
    rob(cykl[i*2], cykl[i*2 + 1]);
  }
  if(SZ(cykl) & 1){
    rob2(cykl.back());
  }
  debug(res);
#ifdef LOCAL
  R(i,n){
    assert(p[i] == i);
  }
#endif
  cout << SZ(res) << "\n";
  for(PII el:res){
    cout << el.FI +1 << " " << el.SE + 1 << "\n";
  }
}