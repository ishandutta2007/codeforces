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
  void run(){
    cin >> n;
    deque<int> st;
    vector<PII> res1;
    vector<int> res2;
    vector<int> t(n);
    
    R(i,n){
      cin >> t[i];
    }
    
    if(n & 1){
      cout << "-1\n";
      return;
    }
    for(int i = 0;i < n; i+=2){
      debug(i,t);
      int j = i + 1;
      while(j < n && t[j] != t[i])j++;
      if(j == n){
        cout << "-1\n";
        return;
      }
      int id = SZ(res1) * 2;
      for(int k = i + 1; k < j; k++){
        res1.PB({j + k - i + id, t[k]});
      }
      res2.PB(j - i);
      reverse(t.begin() + i + 1, t.begin() + j + 1);
    }
    cout << SZ(res1) << "\n";
    for(PII el:res1){
      cout << el.FI << " " << el.SE << "\n"; 
    }
    cout << SZ(res2) << "\n";
    for(int el:res2){
      cout << el*2 << " ";
    }
    cout << "\n";
  }
};

int32_t main(){
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