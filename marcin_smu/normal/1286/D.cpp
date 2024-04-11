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
int mul(int a,int b){
  return a * b % P;
}
int n;

struct event{
  int i;
  int l,m;
  int kl,kr;
};

int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = r * a % P;
    }
    a = a * a % P;
    w/=2;
  }
  return r;
}
vector<vector<vector<int>>> dp;
int pom[2][2];
void lacz(vector<vector<int>> &a,vector<vector<int>> &b, vector<vector<int>> &c){
  R(i,2)R(j,2)pom[i][j] = 0;
  R(i,2)R(j,2)R(k,2)pom[i][k] += b[i][j] * c[j][k]; 
  R(i,2)R(j,2)a[i][j] = pom[i][j] % P;
}

int nn;
vector<vector<int>> get(int po,int ko){
//   debug(po,ko);
//   for(int i = po;i < ko; i++){
//     cerr << "    " << dp[i + nn] << "\n";
//   }
//   cerr << "\n";
  vector<vector<int>> res(2,vector<int>(2));
  res[0][0] = res[1][1] = 1;
  function<void(int,int,int)> rec = [&](int v,int be, int en){
    if(be >= ko || po >= en)return;
    if(po <= be && en <= ko){
      lacz(res,res,dp[v]);
      return;
    }
    rec(v * 2, be, (be + en) / 2);
    rec(v * 2 + 1, (be + en) / 2, en);
  };
  rec(1,0,nn);
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  vector<int> x(n),v(n),p(n);
  R(i,n){
   cin >> x[i] >> v[i] >> p[i];
  }
  vector<event> evs;
  R(i,n-1){
    evs.PB({i,x[i+1] - x[i], v[i] + v[i+1], 0,1});
    if(v[i] > v[i+1]){
      evs.PB({i,x[i+1] - x[i], v[i] - v[i+1], 0, 0});
    }
    if(v[i] < v[i+1]){
      evs.PB({i,x[i+1] - x[i], v[i+1] - v[i], 1, 1});
    }      
  }
  sort(ALL(evs),[](event a,event b){
    return a.l * b.m < b.l * a.m;
  });
  int res = 0;
  nn = 1;
  while(nn <= n * 2)nn *= 2;
  dp.resize(nn * 2, vector<vector<int>>(2,vector<int>(2)));
  R(i,n){
    dp[i*2 + nn][0][0] = p[i];
    dp[i*2 + nn][1][1] = 100 - p[i];
    R(j,2)R(k,2)dp[i*2 + 1 + nn][j][k] = 1;
  }
  for(int i = nn - 1; i; i--){
    lacz(dp[i],dp[i*2],dp[i*2 + 1]);
  }
//   debug(dp);
  for(auto el:evs){
    debug(el.i, el.l, el.m, el.kl, el.kr);
    vector<vector<int>> left = get(0, el.i * 2 + 1);
    vector<vector<int>> right = get(el.i * 2 + 2, n * 2 - 1);
    debug(left,right);
    int a = 0,b = 0;
    R(i,2){
      add(a,left[i][el.kl]);
      add(b,right[el.kr][i]);
    }
    debug(a,b);
//     debug(a,b,el.l,el.m);
    add(res,mul(mul(a,b),mul(el.l,pot(el.m,P-2))));
    int ak  = nn + el.i * 2 + 1;
    dp[ak][el.kl][el.kr] = 0;
    do{
      ak /= 2;
      lacz(dp[ak],dp[ak * 2],dp[ak*2+1]);
    }while(ak != 1);
  }
  debug(res);
  int odw100 = 1;
  while(odw100 % 100 != 0)odw100 += P;
  odw100 /= 100;
  R(i,n){
    res = mul(res, odw100);
  }
  cout << res << "\n";
}