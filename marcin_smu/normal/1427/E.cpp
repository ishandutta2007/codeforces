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

struct op{
  int a,b;
  bool plus;
};
vector<op> res;
int xo(int a,int b){
  res.PB({a,b,0});
  return a^b;
}

vector<int> lnz;

bool dodaj(int a,int b){
  int pom = SZ(res);
  res.PB({a,b,1});
  int x = a+b;
  for(int el:lnz){
    if((el ^ x) < x){
      x = xo(x,el);
    }
  }
  if(x == 0){
    res.resize(pom);
    return 0;
  }else{
    if(x == 1){
      cout << SZ(res) << "\n";
      for(auto el:res){
        cout << el.a << (el.plus ? " + " : " ^ ") << el.b << "\n";
      }
      exit(0);
    }
    lnz.PB(x);
    return 1;
  }
}


void szu(){
  sort(ALL(lnz));reverse(ALL(lnz));
  for(int i = SZ(lnz) - 1; i >= 0; i--){
    for(int j = SZ(lnz) - 1; j >= i; j--){
      if(dodaj(lnz[i],lnz[j]))return;
    }
  }
  assert(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int x;
  cin >> x;
  lnz.PB(x);
  while(1)szu();
}