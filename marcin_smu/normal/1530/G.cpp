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

vector<int> komp(string x){
  vector<int> res;
  res.PB(0);
  for(char el:x){
    if(el == '1'){
      res.PB(0);
    }else{
      res.back()++;
    }
  }
  return res;
}
struct Sol{
  int n,k;
  string a,b;
  vector<PII> res;
  vector<int> koma;
  void ruch(int pocz,int ile){
    debug(pocz,ile,koma);
    int sum = pocz;
    R(i,pocz + 1)sum += koma[i];
    int l = -1, r = -1;
    if(ile < 0){
      l = sum + ile; 
    }else{
      l = sum;
    }
    R(i,k-1){
      sum += koma[i + pocz + 1];
    }
    sum += k;
    if(ile > 0){
      r = sum + ile;
    }else{
      r = sum;
    }
    debug(l,r);
    res.PB({l,r});
    koma[pocz] += ile;
    koma[pocz + k] -= ile;
    reverse(koma.begin() + pocz + 1, koma.begin() + pocz + k);
  }
  
  
  void kanon(){
    for(int i = SZ(koma) - k - 1; i >= 0;i--){
      ruch(i, koma[i + k]);
    }
    if(k % 2){
      R(i,k - 1){
        debug("------------", koma);
        ruch(1, 0);
        ruch(0, koma[k]);
      }
    }else{
      R(i,k - 1){
        debug("------------", koma);
        ruch(1, -koma[1]);
        ruch(0, koma[k]);
      }
    }
    debug("---koniec----", koma);
    
  }
  
  
  void wys(){
    cout << SZ(res) << "\n";
    for(PII el:res){
      cout << el.FI + 1 << " " << el.SE << "\n";
    }
#ifdef LOCAL
    assert(SZ(res) <= 4 * n);
    cerr << "\n";
    for(PII el:res){
      reverse(a.begin() + el.FI, a.begin() + el.SE);
      int pom = 0;
      for(int i = el.FI; i < el.SE; i++){
        pom += a[i] == '1';
      }
      assert(pom == k);
    }
    assert(a == b);
#endif
  }
  void run(){
    cin >> n >> k >> a >> b;
    if(a == b){
      cout << "0\n";
      return;
    }
    koma = komp(a);
    vector<int> komb = komp(b);
    if(k == 0 || SZ(koma) != SZ(komb) || SZ(koma) <= k){
      cout << "-1\n";
      return;
    }
    
    if(k % 2 == 0){
      int sum1 = 0;
      R(i,SZ(koma)){
        if(i & 1){
          sum1 += koma[i] - komb[i];
        }
      }
      if(sum1 != 0){
        debug(sum1);
        cout << "-1\n";
        return;
      }
    }
    
    if(SZ(koma) == k + 1){
      R(i,2){
        bool czok = 1;
        for(int j = 1; j < k; j++){
          if(koma[j] != komb[j])czok = 0;
        }
        if(czok){
          ruch(0,komb[0] - koma[0]);
          ruch(0,0);
          wys();
          return;
        }
        ruch(0,0);
      }
      cout << "-1\n";
      return;
    }
    kanon();
    vector<PII> pomres;
    swap(pomres,res);
    swap(koma,komb);
    kanon();
    reverse(ALL(res));
    swap(res, pomres);
    for(auto el:pomres){
      res.PB(el);
    }
    wys();
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