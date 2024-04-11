#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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

const int MAX = 2e5 + 100;
const int P = 1e9 + 7;
int sil[MAX];
int od[MAX];
int pow(int a,int w = P-2){
  int r = 1;
  while(w){
    if(w&1){
      r = r * a % P;
    }
    w /= 2;
    a = a * a % P;
  }
  return r;
}
int licz(int a,int b){
  if(a < 0)return 0;
  debug("licz",a,b,sil[a+b] * od[a] % P * od[b] % P);
  return sil[a+b] * od[a] % P * od[b] % P;
}
int szuf(int a,int b){
  if(b < 0)return 0;
  debug(a,b,sil[a + b -1] * od[a-1] % P * od[b] % P);
  return sil[a + b -1] * od[a-1] % P * od[b] % P;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  sil[0] = 1;
  R(i,MAX-1){
    sil[i+1] = (i+1) * sil[i] % P;
  }
  R(i,MAX) od[i] = pow(sil[i]);
  
  int f,w,h;
  cin >> f >> w >> h;
  if(w == 0){
    cout << "1\n";
    return 0;
  }
  int all = licz(f,w);
  int like = 0;
  for(int poz = 1;poz <= f+1;poz++){
    debug("-----------", poz);
    like = (like + licz(f - poz + 1, poz) * szuf(poz, w-poz*(h+1) )) % P; 
  }
  debug(all);
  cout << like * pow(all) % P << "\n";
  
}