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

const int P = 998244353;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
void mul(int &a,int b){
  a = a * b % P;
}

int n,m,k;
vector<int> licz(vector<int>& zaj){
  vector<int> a;
  vector<int> b(1,1);
  debug(zaj);
  R(i,SZ(zaj)){
    if(zaj[i]){
      a.clear();
    }else{
      vector<int> c = b;
      if(SZ(a) == SZ(b))b.PB(0);
      R(j,SZ(a)){
        add(b[j+1],a[j]);
      }
      swap(c,a);
    }
    debug(a,b);
  }
  return b;
}
const int MAX = 4001;
int dwu[MAX][MAX];
int sil[MAX];
int licz2(vector<int>& zaj){
  int res = 0;
  for(int el:zaj){
    if(el == 0)res ++;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  R(i,MAX)R(j,i+1){
    if(j == 0){
      dwu[i][j] = 1;
    }else{
      dwu[i][j] = dwu[i-1][j];
      add(dwu[i][j], dwu[i-1][j-1]);
    }
  }
  sil[0] = 1;
  R(i,MAX-1){
    sil[i+1] = sil[i] * (i + 1) % P;
  }
  
  
  cin >> n >> m >> k;
  vector<int> zajn(n);
  vector<int> zajm(m);
  R(i,k)R(_,2){
    int x,y;
    cin >> x >> y;
    x--;y--;
    zajn[x] = 1;
    zajm[y] = 1;
  }
  vector<int> a = licz(zajn);
  vector<int> b = licz(zajm);
  int ila = licz2(zajn);
  int ilb = licz2(zajm);
  debug(a,b,ila,ilb);
  int res = 0;
  R(i,SZ(a))R(j,SZ(b)){
    if(ila < 2 * i + j)continue;
    if(ilb < i + 2 * j)continue;
    int mn = a[i];
    mul(mn, b[j]);
    mul(mn, dwu[ila - 2 * i][j]);
    mul(mn, dwu[ilb - 2 * j][i]);
    mul(mn, sil[i]);
    mul(mn, sil[j]);
    debug(i,j,mn);
    add(res, mn);
  }
  cout << res << "\n";
}