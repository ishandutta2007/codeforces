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

void nie(){
  cout << "0\n";
  exit(0);
}

const int MAX = 200100;
int w[MAX],h[MAX],c[MAX];
int n;
map<int,int> rw,rh;
// int nww(int a,int b){
//   
// }
int get(int i){
  int x = c[i];
  int pom = rw[w[i]];
  if(x % pom != 0)return -1;
  x /= pom;
  pom = rh[h[i]];
  if(x % pom != 0)return -1;
  return x / pom;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    cin >> w[i] >> h[i] >> c[i];
  }
  R(_,2){
    int res = c[0];
    for(int i = 1;i < n; i++){
      if(w[i] == w[0]){
        res = __gcd(c[i],res);
      }
    }
    for(int i = 0; i < n; i++){
      if(w[i] == w[0]){
        rh[h[i]] = c[i] / res;
      }
    }
    R(i,n)swap(w[i],h[i]);
    swap(rw,rh);
  }
  int pom = get(0);
  if(n != SZ(rw) * SZ(rh) || pom == -1){
    nie();
  }
  R(i,n)if(get(i) != pom)nie();
  int res = 0;
  int i = 1;
  for(;i * i < pom; i++){
    if(pom % i == 0)res+=2;
  }
  if(i * i == pom)res++;
  cout << res << "\n";
  
  
}