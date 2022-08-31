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

const int P = (1ll << 31) - 1;
int base;
int mul(int a,int b){
  int pom = a * b;
  int res = (pom >> 31) + (pom & P);
  if(res >= P)res -= P;
  return res;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
struct info{
  int h;
  int dl;
  int ones;
  int pocz;
  bool operator==(info x){
    return h == x.h && dl == x.dl && ones == x.ones && pocz == x.pocz;
  }
  friend ostream& operator<<(ostream& out, info m){
    if(m.pocz){
      out << 1;
    }
    return out << "(" << m.h << "," << m.dl << ")" << m.ones;
  }

};
const int MAX = (1 << 18);
int pp[MAX];
info lacz(info a,info b){
  info res = a;
  if(b.dl == 0){
    res.ones += b.ones;
    return res;
  }
  if(b.pocz)res.ones++;
  if(res.ones&1){
    if(res.dl){
      res.h = mul(res.h, base);
      add(res.h, 1);
      res.dl++;
    }else{
      res.pocz = 1;
    }
    res.ones--;
  }
  res.h = mul(res.h, pp[b.dl]);
  add(res.h, b.h);
  res.dl += b.dl;
  res.ones += b.ones;
  return res;
}
info dp[MAX * 2];
int n,q;
int nn;
string t;

info get(int po,int ko){
  info res = {0,0,0,0};
  debug(po,ko);
  function<void(int,int,int)> rec = [&](int nr,int be,int en){
    if(po >= en || be >= ko)return;
    if(po <= be && en <= ko){
      debug(dp[nr]);
      res = lacz(res, dp[nr]);
      return;
    }
    rec(nr * 2, be, (be + en)/2);
    rec(nr * 2 + 1, (be + en)/2, en);
  };
  rec(1,0,nn);
  debug(res);
  return res;
}

int32_t main() {
  srand(time(0));
  base = rand();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> t >> q;
  pp[0] = 1;
  R(i,MAX - 1){
    pp[i+1] = mul(pp[i], base);
  }
  nn = 1;while(nn < n)nn *= 2;
  R(i,n){
    if(t[i] == '0'){
      dp[i + nn] = {0,1,0,0};
    }else{
      dp[i + nn] = {0,0,1,0};
    }
  }
  for(int i = nn - 1; i; i--){
    dp[i] = lacz(dp[i*2], dp[i*2 + 1]);
  }
  R(i,q){
    int a,b,l;
    cin >> a >> b >> l;a--;b--;
    if(get(a, a + l) == get(b, b + l)){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }
}