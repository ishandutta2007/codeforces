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

const int inf= 1e9;
struct Sol{
  int n,m,k;
  vector<int> deg;
  vector<vector<int>> d;
  unordered_set<int> kra;
  vector<int> klika;
  void spr(vector<int> &x){
    if(SZ(klika))return;
    R(i,SZ(x))R(j,i){
      if(kra.find(x[i]*n + x[j]) == kra.end())return;
    }
    klika = x;
  }
  void tnij(int i){
    if(deg[i] > k-1)return;
    if(deg[i] == k-1){
      vector<int> sa;
      for(int el:d[i]){
        if(deg[el] <= inf / 2){
          sa.PB(el);
        }
      }
      sa.PB(i);
      spr(sa);
    }
    deg[i] = inf;
    for(int el:d[i]){
      deg[el]--;
    }
    for(int el:d[i]){
      tnij(el);
    }
  }
  void run(){
    cin >> n >> m >> k;
    d.resize(n);
    deg.resize(n);
    R(i,m){
      int a,b;
      cin >> a >> b;
      a--;b--;
      d[a].PB(b);
      d[b].PB(a);
      deg[a]++;
      deg[b]++;
      kra.insert(a * n + b);
      kra.insert(b * n + a);
    }
    R(i,n)tnij(i);
    if(SZ(klika)){
      cout << "2\n";
      for(int el:klika){
        cout << el +  1 << " ";
      }
      cout << "\n";
      return;
    }
    vector<int> res;
    R(i,n)if(deg[i] < inf / 2){
      res.PB(i);
    }
    if(res.empty()){
      cout << "-1\n";
    }else{
      cout << "1 " << SZ(res) << "\n";
      for(int el:res){
        cout << el + 1 << " ";
      }
      cout << "\n";
    }
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}