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

const int MAX = 200100;
int n,m,k;
vector<int> d[MAX];
int a[MAX],b[MAX],cz[MAX],deg[MAX];
int us[MAX];
int res;
void dfs(int nr){
  if(us[nr])return;
  if(deg[nr] >= k)return;
  us[nr] = 1;
  res--;
  for(int el:d[nr]){
    if(!cz[el]){
      cz[el] = 1;
      deg[a[el]]--;
      deg[b[el]]--;
      dfs(a[el]);
      dfs(b[el]);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> k;
  R(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    d[a[i]].PB(i);
    d[b[i]].PB(i);
    deg[a[i]]++;
    deg[b[i]]++;
  }
  res = n;
  R(i,n)dfs(i);  
  vector<int> out;
  for(int i = m-1; i >= 0;i--){
    out.PB(res);
    if(!cz[i]){
      cz[i] = 1;
      deg[a[i]]--;
      deg[b[i]]--;
      dfs(a[i]);
      dfs(b[i]);
    }
  }
  reverse(ALL(out));
  for(int el:out){
    cout << el << "\n";
  }
}