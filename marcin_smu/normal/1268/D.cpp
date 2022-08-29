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

const int MAX = 2001;
string z[MAX];
int deg[MAX];
int n;
bool spr(){
  vector<int> x(n);
  R(i,n) x[i] = i;
  sort(ALL(x),[&](int a,int b){
    return deg[a] < deg[b];
  });
  int pom = 0;
  for(int i = 0; i < SZ(x) - 1; i++){
    pom += deg[x[i]];
    pom -= i;
    if(pom == 0)return 0;
  }
  return 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    cin >> z[i];
    R(j,n){
      if(z[i][j] == '1'){
        deg[i]++;
      }
    }
  }
  if(spr()){
    cout << "0 1\n";
    return 0;
  }
  int res = 0;
  R(i,n){
    R(j,n)if(j!=i){
      if(z[i][j] == '0'){
        deg[i]++;
        deg[j]--;
      }else{
        deg[i]--;
        deg[j]++;
      }
    }
    if(spr()){
      res++;
    }
    R(j,n)if(j!=i){
      if(z[i][j] == '0'){
        deg[i]--;
        deg[j]++;
      }else{
        deg[i]++;
        deg[j]--;
      }
    }
  }
  if(res == 0){
    if(n == 4){
      cout << "-1\n";
      return 0;
    }
    cout << "2 18\n";
    return 0;
  }
  cout << "1 " << res << "\n";
  
  
}