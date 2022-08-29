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

int n;
string z;
const int inf = 1e9;
int res;
int s10;
int s01;
int s11a;
int s11b;
void licz(int x){
  debug("-----------",x);
  if(x > 0){
    res = -inf;
    return;
  }
  int w00 = 0, w10 = -inf, w01 = -inf, w11 = -inf;
  int ak = 0;
  R(i,n){
    debug(ak,w00,w10,w01,w11);
    if(z[i] == '('){
      ak++;
      if(w10 < w00){
        s10 = i;
        w10 = w00;
      }
      if(w11 < w01){
        s11a = s01;
        s11b = i;
        w11 = w01;
      }
    }else{
      ak--;
      if(w01 < w00){
        w01 = w00;
        s01 = i;
      }
      if(w11 < w10){
        w11 = w10;
        s11a = s10;
        s11b = i;
      }
    }
    
    if(ak - 2 == x) w10 ++;
    if(ak == x){w00 ++; w11++;}
    if(ak + 2 == x) w01 ++;
    
    if(ak - 2 < x) w10 = -inf;
    if(ak < x){
      w00 = -inf;
      w11 = -inf;
    }
    if(ak + 2 < x){
      w01 = -inf;
    }
  }
  debug(w00);
  if(w11 < w00){
    w11 = w00;
    s11a = 0;
    s11b = 0;
  }
  res = w11;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> z;
  int mi = 0;
  int ak = 0;
  R(i,n){
    if(z[i] == '('){
      ak++;
    }else{
      ak--;
    }
    mini(mi,ak);
  }
  if(ak != 0){
    cout << "0\n1 1\n";
    return 0;
  }
  debug(ak,mi);
  int out = -1;
  int a=-1,b=-1;
  for(int i = -2;i<=2;i++){
    licz(mi + i);
    if(res > out){
      out = res;
      a = s11a + 1;
      b = s11b + 1;
    }
  }
  cout << out << "\n" << a << " " << b << "\n";
  
}