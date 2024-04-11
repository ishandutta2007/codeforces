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

const int MAX = 3e6 + 10;
int n,res[MAX];
map<int,int> il;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    int pom;
    cin >> pom;
    il[pom]++;
  }
  vector<PII> t;
  for(auto x:il){
    t.PB(x);
  }
  int sum = 0;
  int m = SZ(t);
  int dob = 0;
  R(i,m){
    if(t[i].FI * t[i].FI < MAX)
      res[t[i].FI * t[i].FI] -= t[i].SE * (t[i].SE + 1) / 2;
    else
      dob -= t[i].SE * (t[i].SE + 1) / 2;
    int j = i;
    int reszta = n - sum;
    while(j < m && t[j].FI * t[i].FI < MAX){
      res[t[j].FI * t[i].FI] += t[j].SE * t[i].SE;
      reszta -= t[j].SE;
      j++;
    }
    dob += reszta * t[i].SE;
    sum += t[i].SE;
  }
  res[MAX-1] += dob;
  for(int i = MAX-2;i > 0;i--){
    res[i] += res[i+1];
  }
  int q;
  cin >> q;
  while(q--){
    int pom;
    cin >> pom;
    cout << res[pom]*2 << "\n";
  }
}