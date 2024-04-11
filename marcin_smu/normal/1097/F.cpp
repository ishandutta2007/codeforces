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

#ifdef LOCAL
const int MAX = 10;
#else
const int MAX = 7001;
#endif
typedef bitset<MAX> bs;
bs nad[MAX],pod[MAX];
bs war[100100];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  R(i,MAX)if(i){
    int kw = 0;
    for(int j = 2; j * j <= i; j++){
      if(i % (j * j) == 0)kw = 1;
    }
    for(int j = 1; j * i < MAX; j++){
      if(kw == 0)
        nad[j][i * j] = 1;
      pod[i * j][i] = 1;
    }
  }
  int n;
  cin >> n;
  cin >> n;
  R(_,n){
    int typ,x,v;
    cin >> typ >> x >> v;
    if(typ == 1){
      war[x] = pod[v];
    }else if(typ == 2){
      int z;
      cin >> z;
      war[x] = war[v] ^ war[z];
    }else if(typ == 3){
      int z;
      cin >> z;
      war[x] = war[v] & war[z];
    }else{
      cout << ((war[x] & nad[v]).count()&1);
    }
    debug(war[x]);
  }
  cout << "\n";
}