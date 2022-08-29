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
template<class T> ostream &operator<<(ostream& os, set<T> V) {
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
  set<int> secik;
  vector<int> prev,next;
  vector<int> t;
  void run(){
    int n;
    cin >> n;
    prev.resize(n);
    next.resize(n);
    t.resize(n);
    R(i,n){
      prev[i] = i-1;
      next[i] = i+1;
      cin >> t[i];
    }
//     if(n == 1){
//       if(t[0] == 1){
//         cout << "1 1\n";
//       }else{
//         cout << "0\n";
//       }
//       return;
//     }
    prev[0] = n-1;
    next[n-1] = 0;
    if(__gcd(t[n-1], t[0]) == 1){
      secik.insert(0);
    }
    R(i,n - 1){
      if(__gcd(t[i], t[i+1]) == 1){
        secik.insert(i + 1);
      }
    }
    debug(secik);
    debug(prev,next);
    int ost = 0;
    vector<int> res;
    while(SZ(res) < n){
      if(secik.empty())break;
      auto xxx = secik.upper_bound(ost);
      if(xxx == secik.end()){
        xxx = secik.begin();
      }
      int pom = *xxx;
      debug(pom);
      ost = next[pom];
      res.PB(pom);
      secik.erase(pom);
      secik.erase(next[pom]);
      next[prev[pom]] = next[pom];
      prev[next[pom]] = prev[pom];
      if(__gcd(t[prev[pom]], t[next[pom]]) == 1){
        secik.insert(next[pom]);
      }
    }
    cout << SZ(res) << " ";
    for(int el:res){
      cout << el + 1 << " ";
    }
    cout << "\n";
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