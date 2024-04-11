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

struct Sol{
  int n;
  string s,t;
  vector<int> d;
  vector<int> f;
  int find(int a){
    return f[a] == a ? a : f[a] = find(f[a]);
  }
  bool uni(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b)return 0;
    f[a] = b;
    return 1;
  }
  void run(){
    cin >> n >> s >> t;
    f.resize(20);
    d.resize(20);
    R(i,20){
      f[i] = i;
    }
    for(char& x:s){
      x -= 'a';
    }
    for(char& x:t){
      x -= 'a';
    }
    int res = 0;
    R(i,n){
      d[s[i]] |= 1 << t[i];
      if(uni(s[i],t[i])){
        res++;
      }
    }
    vector<int> dp(1 << 20, -100);
    dp[0] = 0;
    int naj = 0;
    R(i, 1 << 20)if(dp[i] >= 0){
      maxi(naj, dp[i]);
      R(j,20)if(((i>>j) & 1) == 0){
        if((d[j] & i) == 0){
          dp[i | (1 << j)] = dp[i] + 1;
        }
      }
    }
    cout << res + 20 - naj << "\n";
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}