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

vector<int> zer,jed;
vector<vector<int>> res;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  string z;
  cin >> z;
  R(i,SZ(z)){
    if(z[i] == '0'){
      if(SZ(jed) == 0){
        zer.PB(SZ(res));
        res.PB(vector<int>(1,i));
      }else{
        int pom = jed.back();
        res[pom].PB(i);
        zer.PB(pom);
        jed.pop_back();
      }
    }else{
      if(SZ(zer) == 0){
        cout << "-1\n";
        return 0;
      }else{
        int pom = zer.back();
        res[pom].PB(i);
        jed.PB(pom);
        zer.pop_back();
      }
    }
  }
  if(SZ(jed)){
    cout << "-1\n";
  }else{
    cout << SZ(res) << "\n";
    R(i,SZ(res)){
      cout << SZ(res[i]) << " ";
      for(int el:res[i]){
        cout << el+1 << " ";
      }
      cout << "\n";
    }
  }
}