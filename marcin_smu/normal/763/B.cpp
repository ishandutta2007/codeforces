#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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

const int MAX = 5e5 + 7;
//~ vector<int> d[MAX];
//~ vector<int> res;
//~ vector<int> vis;
int n;
PII x[MAX],y[MAX];
//~ void dfs(int a,int kol){
  //~ if(vis[a])return;
  //~ vis[a] = 1;
  //~ res[a] = kol;
  //~ for(int el:d[a])dfs(el,kol-1);
//~ }
//~ vector<int> licz(){
  //~ map<int, vector<pair<PII,int>>> mapa;
  //~ R(i,n)d[i].clear();
  //~ res.clear();
  //~ res.resize(n);
  //~ vis.clear();
  //~ vis.resize(n);
  //~ R(i,n){
    //~ mapa[x[i].FI].PB({{y[i].FI,1},i});
    //~ mapa[x[i].FI].PB({{y[i].SE,-1},i});    
    //~ mapa[x[i].SE].PB({{y[i].FI,1},i});
    //~ mapa[x[i].SE].PB({{y[i].SE,-1},i});
  //~ }
  //~ for(auto &xxx:mapa){
    //~ auto &v = xxx.SE;
    //~ vector<int> ak;
    //~ for(PII el:v){
      //~ if(el.FI.SE == -1){
        //~ ak.erase(el.SE);
      //~ }else{
        //~ ak.PB(el.SE);
      //~ }
      //~ if(SZ(ak) == 2){
        //~ d[ak[0]].PB(ak[1]);
        //~ d[ak[1]].PB(ak[0]);
      //~ }
    //~ }
  //~ }
  //~ R(i,n)dfs(i);
  //~ return res;
//~ }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    cin >> x[i].FI >> y[i].FI;
    cin >> x[i].SE >> y[i].SE;
  }
  cout << "YES\n";
  R(i,n)
    cout << ((x[i].FI&1) * 2 + (y[i].FI&1) + 1) << "\n"; 
  //~ }
  //~ VI a = licz();
  //~ R(i,n){
    //~ swap(x[i],y[i]);
  //~ }
  //~ VI b = licz();
  //~ R(i,n){
    //~ cout << a[i] * 2 + b[i] << "\n";
  //~ }
}