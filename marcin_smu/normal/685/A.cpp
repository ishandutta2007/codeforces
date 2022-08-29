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

int dlugosc(int n){
  if(n == 0)return 0;
  return 1 + dlugosc(n/7);
}

void dod(int a,int b,vector<int> &c){
  int mask = 0;
  R(i,b){
    int pom = (a % 7);
    if((mask >> pom)&1)return;
    mask += 1 << pom;
    a/=7;
  }
  c.PB(mask);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n,m;
  cin >> n >> m;
  int w1 = dlugosc(max(n-1,1ll));
  int w2 = dlugosc(max(m-1,1ll));
  if(w1 + w2 > 7){
    cout << "0\n";
    return 0;
  }
  vector<int> p1,p2;
  R(i,n)
    dod(i,w1,p1);
  R(i,m)
    dod(i,w2,p2);
  int res = 0;
  for(int a:p1)for(int b:p2){
    if((a & b) == 0)
      res++;
  }
  cout << res << "\n";
}