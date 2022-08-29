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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const int MAX = 711;
const int P = 1e9 + 7;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w&1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}
int jed[MAX];
int dp1[10][MAX];
int dp2[10][MAX];
// int sil[MAX];
// int odw[MAX];
int newt[MAX][MAX];
int poty[11][MAX];
int odwy[11][MAX];
string x;
int ile[10];
// int dwu(int a,int b){
//   return sil[a] * odw[b] % P * odw[a - b] % P;
// }
int licz(int dl){
  int res = 0;
  int wie = 0;
  for(int cyf = 9;cyf;cyf--){
    debug(jed[ile[cyf]]);
    R(i,dl + 1){
      add(res, jed[ile[cyf]] * cyf % P * poty[10][wie + i] % P *
        newt[dl][i] % P * poty[10 - cyf][i] % P * poty[cyf][dl - i] % P);
    }
    add(res, poty[10][wie] * dp2[cyf][dl] % P);
    debug(poty[10][wie] * dp2[cyf][dl] % P);
    wie += ile[cyf];
  }
  debug("----");
  R(i,10)cerr << ile[i] << " ";
  cerr << "\n";
  debug(dl, res);
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  jed[0] = 0;
  R(i,11){
    poty[i][0] = 1;
    R(j,MAX-1){
      poty[i][j+1] = poty[i][j] * i % P; 
    }
    R(j,MAX){
      odwy[i][j] = pot(poty[i][j], P - 2);
    }
  }
//   sil[0] = 1;
  R(i,MAX-1){
    jed[i+1] = (jed[i] * 10 + 1) % P;
//     sil[i+1] = sil[i] * (i+1) % P;
  }
//   R(i,MAX){
//     odw[i] = pot(sil[i], P - 2);
//   }
  R(i,MAX)R(j,i+1){
    if(j == 0){
      newt[i][j] = 1;
    }else{
      newt[i][j] = newt[i-1][j];
      add(newt[i][j], newt[i-1][j-1]);
    }
  }
  R(cyf,10){
    dp1[cyf][0] = 1;
    R(i,MAX-1){
      dp1[cyf][i+1] = dp1[cyf][i] * (cyf + 10 * (10 - cyf - 1)) % P;
    }
  }
  R(cyf,10){
    R(i,MAX)R(j,MAX){
      if(i + j >= MAX)break;
      add(dp2[cyf][i + j], dp1[cyf][i] * jed[j] % P * cyf % P * newt[i + j][j] % P);
    }
  }
  cin >> x;
  for(char &el:x)el -= '0';
  
  int res = 0;
  R(i,SZ(x)){
    R(j,x[i]){
      ile[j]++;
      add(res,licz(SZ(x) - i - 1));
      ile[j]--;
    }
    ile[(int)x[i]]++;
  }
  add(res,licz(0));
  cout << res << "\n";
}