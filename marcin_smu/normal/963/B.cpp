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

const int MAX = 201001;
vector<int> d1[MAX],d2[MAX];;
int n;
int dfs1(int a,int par){
  int siz = 1;
  for(int el:d1[a])if(el!=par){
    int pom = dfs1(el,a);
    if(pom & 1){
      debug(el,a);
      d2[el].PB(a);
    }else{
      debug(a,el);
      d2[a].PB(el);
    }
    siz += pom;
  }
  return siz;
}
bool cz[MAX];
void dfs2(int a){
  if(cz[a])return;
  cz[a] = 1;
  for(int el:d2[a]){
    dfs2(el);
  }
  cout << a + 1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  if(n % 2 == 0){
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  R(i,n){
    int a;
    cin >> a;
    if(a){
      a--;
      d1[a].PB(i);
      d1[i].PB(a);
    }
  }
  dfs1(0,-1);
  R(i,n){
    dfs2(i);
  }
}