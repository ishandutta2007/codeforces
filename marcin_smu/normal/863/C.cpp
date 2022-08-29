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

pair<int,int> t[3][3];
int kk[3][3];
pair<int,int> res;
int ta[3][3],tb[3][3];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int k,a,b;
  cin >> k >> a >> b;
  a--;b--;
  R(i,3)R(j,3){
    cin >> ta[i][j];
    ta[i][j]--;
  }
  R(i,3)R(j,3){
    cin >> tb[i][j];
    tb[i][j]--;
  }
  while(k){
    t[a][b] = res;
    kk[a][b] = k;
    if((a + 1) % 3 == b)res.FI++;
    if((b + 1) % 3 == a)res.SE++;
    k--;
    int aa = a;
    a = ta[a][b];
    b = tb[aa][b];
    debug(a,b,res.FI,res.SE);
    if(kk[a][b] != 0){
      int il = kk[a][b] - k;
      int pom = k / il;
      debug(il,pom);
      res.FI += (res.FI - t[a][b].FI) * pom;
      res.SE += (res.SE - t[a][b].SE) * pom;
      k -= il * pom;
    }
  }
  cout << res.SE << " " << res.FI << "\n";
}