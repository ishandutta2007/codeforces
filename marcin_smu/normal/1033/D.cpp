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

int pot(int a,int deg){
  int res = 1;
  R(_,deg){
    res *= a;
  }
  return res;
}
int sqr(int n,int deg){
  int war = pow(n,1./deg);
  while(pot(war,deg) < n)war++;
  while(pot(war,deg) > n)war--;
  return war;
}

struct liczba{
  int kr;
  int war;
  bool zlo;
  void pob(){
    cin >> war;
    kr = 1;
    zlo = 1;
    for(int i = 4; i >= 2; i--){
      int pom = sqr(war,i);
      if(pot(pom,i) == war){
        zlo = 0;
        kr = i;
        war = pom;
        break;
      }
    }
    debug(war,kr,zlo);
    assert(war >= 2);
  }
};
vector<liczba> x;
void dodaj(liczba ak){
  R(i,SZ(x)){
    if(x[i].war == ak.war){
      x[i].kr += ak.kr;
      return;
    }
    
    if(ak.war % x[i].war == 0){
      x[i].kr += ak.kr;
      ak.war /= x[i].war;
      ak.zlo = 0;
    //  debug(x[i].war,ak.war);
      dodaj(ak);
      return;
    }
    if(x[i].war % ak.war == 0){
      x[i].war /= ak.war;
      x[i].zlo = 0;
      ak.kr += x[i].kr;
    }
    int pom = __gcd(x[i].war,ak.war);
    if(pom != 1){
      x[i].war /= pom;
      x[i].zlo = 0;
      ak.war /= pom;
      ak.zlo = 0;
      liczba ak2 = {x[i].kr + ak.kr, pom, false};
      dodaj(ak2);
      dodaj(ak);
      return;
    }
  }
  x.PB(ak);
}
const int P = 998244353;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  R(i,n){
    liczba ak;
    ak.pob();
    dodaj(ak); 
  }
  int res = 1;
  for(auto el:x){
    debug(el.war, el.kr, el.zlo);
    res = res * (1 + el.kr) % P;
    if(el.zlo){
      res = res * (1 + el.kr) % P;
    }
  }
  cout << res << "\n";
}