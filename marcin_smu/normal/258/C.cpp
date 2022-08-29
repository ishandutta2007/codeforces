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

const int MAX = 100100;
const int P = 1e9 + 7;
int n;
int t[MAX];
vector<int> pom[MAX];
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w&1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n)cin >> t[i];
  sort(t,t+n);
  int res = 0;
  int ak = 1;
  R(i,n){
    while(ak <= t[i]){
      for(int j = 1; j*ak < MAX; j++){
        pom[j*ak].PB(i);
      }
      int xx = 1;
      R(i,SZ(pom[ak])-1){
        xx *= pot(i+1, pom[ak][i+1] - pom[ak][i]);
        xx %= P;
      }
      res += (pot(SZ(pom[ak]), n - i) - pot(SZ(pom[ak])-1,n-i)) * xx % P;
      res %= P;
      ak++;
    }
    
  }
  cout << (res % P + P) % P << "\n";
}