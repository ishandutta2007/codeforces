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

struct info{
  int wys;
  int znim;
  int przed1; // zjedzony
  int przed2; // niezjeodzny
};
const int inf = 1e16;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<int> h(n),b(n);
  R(i,n){
    cin >> h[i];
  }
  R(i,n){
    cin >> b[i];
  }
  vector<info> st;
  R(i,n){
    int res = -inf;
    while(!st.empty() && st.back().wys > h[i]){
      maxi(res, st.back().znim);
      maxi(res, st.back().przed1);
      maxi(res, st.back().przed2);
      st.pop_back();
    }
    if(st.empty()){
      maxi(res, 0ll);
      st.PB({h[i], res + b[i], -inf, res});
    }else{
      maxi(res, st.back().znim);
      maxi(res, st.back().przed1);
      int res2 = max(st.back().znim,st.back().przed1);
      debug(res2);
      st.PB({h[i], res + b[i], res2, res});
    }
    
#ifdef LOCAL
    debug(i);
    for(auto el:st){
      cout << el.wys << " " << el.znim << " " << el.przed1 << " " << el.przed2 << "\n";
    }
#endif
  }
  cout << max(st.back().znim,st.back().przed1) << "\n";
}