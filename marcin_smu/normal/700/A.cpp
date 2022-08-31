#include <bits/stdc++.h>

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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int n,l,v1,v2,k;
// LD t;
// LD get_l(){
//   return l - t * v1;
// }
int x;
LD res;
bool spr(LD t){
  LD a = v1 * t;
  LD b = l - v1 * t;
  res = t + b / v2;
  return (2 * x * b - l) / v2 < res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> l >> v1 >> v2 >> k;
  x = (n+k-1)/ k;
  if(x == 1){
    cout << (LD)l / v2 << endl;
    return 0;
  }
  debug(x);
  LD po = 0,ko = 1e16;
  while((ko - po) > 1e-8){
    LD m = (po + ko)/2;
    if(spr(m))
      ko = m;
    else
      po = m;
  }
  cout << res << endl;
//   debug(x);
//   LD b = l / (v2 + 2*(x-1)*v1);
//   LD a = b * 2*(x-1);
//   debug(a,b);
//   cout << a + b << endl;
  /*
  if(x == 1){
    cout << LD(l) / v2 << endl;
  }else{
  }
  while(1){
    n -= k;
    t += get_l()/v2;
    if(n <= 0){
      cout << t << endl;
      return 0;
    }
    t += get_l()/(v1+v2);
  }*/
}