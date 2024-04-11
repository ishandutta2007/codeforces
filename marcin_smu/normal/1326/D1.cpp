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

string licz(string z){
  string z2 = z;
  reverse(ALL(z2));
  z += '#';
  z += z2;
  int n = SZ(z);
  vector<int> kmp(n);
  int t = 0;
  for(int i = 1; i < n; i++){
    while(t && z[t] != z[i]) t = kmp[t-1];
    kmp[i] = t += z[t] == z[i];
  }
  debug(z,kmp);
  return z.substr(0,kmp[n-1]);
}

struct Test{
  string z;
  int n;
  void run(){
    cin >> z;
    n = SZ(z);
    int ak = 0;
    while(ak < n && z[ak] == z[n-ak-1])ak++;
    if(ak == n){
      cout << z << "\n";
      return;
    }
    auto xxx = z.substr(0,ak);
    cout << xxx;
    
    string pom = z.substr(ak,n-ak*2);
    string pref = licz(pom);
    reverse(ALL(pom));
    string suf = licz(pom);
    debug(pref,suf);
    if(SZ(pref) > SZ(suf)){
      cout << pref;
    }else{
      cout << suf;
    }
    reverse(ALL(xxx));
    cout << xxx << "\n";
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
    Test test;
    test.run();
  }   
}