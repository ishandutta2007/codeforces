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

string s,t;
struct hash{
  int P;
  vector<int> pp;
  vector<int> h;
  int n;
  int mul(int a,int b){
    return a * b % P;
  }
  void add(int &a,int b){
    a += b;
    if(a >= P)
      a -= P;
  }
  int buduj(int p,int base, string& z){
    P = p;
    n = SZ(z);
    pp.resize(n + 1);
    h.resize(n + 1);
    pp[0] = 1;
    h[0] = 0;
    R(i,n){
      pp[i+1] = mul(pp[i], base);
      h[i+1] = mul(h[i], base);
      add(h[i+1], z[i]);
    }
    return h[n];
  }
  
  int get(int a,int dl){
    int res = h[a + dl] - mul(h[a], pp[dl]);
    if(res < 0)res += P;
    return res;
  }
  
  bool spr(int dl0,int dl1){
    int ak = 0;
    int xx = 0;
    int h0 = -1;
    int h1 = -1;
    R(i,SZ(s)){
      if(s[i] == 0){
        if(h0 == -1){
          h0 = get(ak, dl0);
        }
        ak += dl0;
        xx = mul(xx, pp[dl0]);
        add(xx, h0);
      }else{
        if(h1 == -1){
          h1 = get(ak, dl1);
        }
        ak += dl1;
        xx = mul(xx, pp[dl1]);
        add(xx, h1);
      }
      
    }
    debug(dl0,dl1,xx,h0,h[n]);
    return xx == h[n] && h0 != h1; 
  }
}h1,h2;
int il0 = 0,il1 = 0;
int res;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> s >> t;
  h1.buduj(1e9 + 7, 1000, t);
  h2.buduj(1e9 + 9, 51321351, t);
  R(i,SZ(s)){
    char& el = s[i];
    el -= '0';
    if(el == 0){
      il0++;
    }else{
      il1++;
    }
  }
  R(dl0, SZ(t)){
    if(dl0 == 0)continue;
    int pom = SZ(t) - dl0 * il0;
    if(pom <= 0 || pom % il1 != 0)continue;
    if(h1.spr(dl0, pom / il1) && 
      h2.spr(dl0, pom / il1)){
      res ++;
    }
  }
  cout << res << "\n";
}