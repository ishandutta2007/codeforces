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

int n;
int wyn[4][2];
int gl = 0;
int pom[4] = {0,0,0,0};
int zap(int a){
  cout << "?";
  pom[gl] = a;
  R(i,2){
    cout << " " << pom[i]+1;
  }
  R(i,2){
    cout << " " << n - pom[i + 2];
  }
  pom[gl] = 0;
  cout << endl;
  int res;
  cin >> res;
  return res;
}
int szu(int x){
  int po = 0, ko = n;
  while(po + 1 != ko){
    int m = (po+ko)/2;
    if(zap(m) >= x)
      po = m;
    else
      ko = m;
  }
  return po;
}
// vector<int> out;
bool spr(int a,int b,int c,int d){
  a++;
  b++;
  c = n - c;
  d = n - d;
  if(a > c || b > d)return 0;
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  int res;
  cin >> res;
  return res;
}
void wys(int a,int b,int c,int d){
  a++;
  b++;
  c = n - c;
  d = n - d;
  cout << " " << a  << " " << b << " " << c << " " << d;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,4){
    gl = i;
    R(j,2)
      wyn[i][j] = szu(j+1);
  }
  R(i,2)R(j,2)R(k,2)R(l,2){
    if(spr(wyn[0][i],wyn[1][j],wyn[2][k],wyn[3][l])&&
       spr(wyn[0][!i],wyn[1][!j],wyn[2][!k],wyn[3][!l])){
      cout << "!";
      wys(wyn[0][i],wyn[1][j],wyn[2][k],wyn[3][l]);
      wys(wyn[0][!i],wyn[1][!j],wyn[2][!k],wyn[3][!l]);
      cout << endl;
      return 0;
    }
  }
//   for(int el:out){
//     cout << " " << el;
//   }
//   cout << endl;
}