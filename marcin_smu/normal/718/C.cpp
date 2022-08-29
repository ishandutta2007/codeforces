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
const int MAX = (1<<18) + 100;
const int P = 1e9 + 7;
struct fib{
  int a,b,c;
  fib():a(1),b(0),c(1){};
  void sum(fib x,fib y){
    a = x.a + y.a;
    if(a >= P)a-=P;
    b = x.b + y.b;
    if(b >= P)b-=P;
    c = x.c + y.c;
    if(c >= P)c-=P;
  }
  void razy(fib &x){
    int aa = (a * x.a + b * x.b) % P;
    int bb = (a * x.b + b * x.c) % P;
    int cc = (b * x.b + c * x.c) % P;
    a = aa;
    b = bb;
    c = cc;
  }
  void print(){
    debug(a,b,c);
  }
}dp[MAX],gl,il[MAX],jeden;
int n,m,nn;
int l, r;
void add(int nr,int po,int ko){
  if(r <= po || ko <= l)return;
  if(l <= po && ko <= r){
    il[nr].razy(gl);
    dp[nr].razy(gl);
    return;
  }
  add(nr*2, po, (po + ko) / 2);
  add(nr*2+1, (po+ko)/2, ko);
  dp[nr].sum(dp[nr*2],dp[nr*2+1]);
  dp[nr].razy(il[nr]);
}
fib summ(int nr,int po,int ko){
  if(r <= po || ko <= l){
    fib res;
    res.a = res.b = res.c = 0;
    return res;
  }
  if(l <= po && ko <= r){
    return dp[nr];
  }
  fib res;
  res.sum(
    summ(nr*2,po,(po+ko)/2),
    summ(nr*2+1,(po+ko)/2,ko)
    );
  res.razy(il[nr]);
  return res;
}
fib pot(fib a, int w){
  fib res;
  while(w){
    if(w&1){
      res.razy(a);
    }
    w/=2;
    a.razy(a);
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  nn=1;while(nn <= n)nn*=2;
  jeden.a = 0;
  jeden.b = 1;
  jeden.c = 1;
  R(i,n){
    int pom;
    cin >> pom;
    dp[i+nn] = pot(jeden, pom);
  }
  for(int i = nn-1;i>0;i--){
    dp[i].sum(dp[i*2], dp[i*2+1]);
  //  dp[i].print();
  }
  R(i,m){
    int z;
    cin >> z >> l >> r;
    l--;
    if(z == 1){
      int x;
      cin >> x;
      gl = pot(jeden, x);
      add(1,0,nn);
    }else{
      fib res = summ(1,0,nn);
      cout << res.b << endl;
    }
  }
}