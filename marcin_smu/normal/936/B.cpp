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

const int MAX = 201000;

int n,m;

vector<int> d2[MAX];
int vis[MAX];
void draw(int x){
  vis[x] = 1;
  for(int ak:d2[x]){
    if(vis[ak] == 1){
      cout << "Draw\n";
      exit(0);
    }
    if(vis[ak] == 0){
      draw(ak);
    }
  }
  vis[x] = 2;
}

int deg[MAX];
int cz[MAX][2];

vector<int> res;
vector<int> d[MAX];
vector<int> todo;
int s;
bool dfs(int x,int y){
  if(cz[x][y])return 0;
  cz[x][y] = 1;
  if(x == s && y == 1){ //??
    res.PB(x);
    return 1;
  }
  for(int ak:d[x]){
    if(dfs(ak,!y)){
      res.PB(x);
      return 1;
    }
  }
  return 0;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,n){
    cin >> deg[i];
    R(j,deg[i]){
      int x;
      cin >> x;
      x--;
      d[x].PB(i);
      d2[i].PB(x);
    }
  }
  cin >> s;
  s--;
  R(i,n){
    if(deg[i] == 0){
      if(dfs(i,0)){
        cout << "Win\n";
        for(int el:res){
          cout << el+1 << " ";
        }
        cout << "\n";
        return 0;
      }
    }
  }
  draw(s);
  cout << "Lose\n";
  
//   R(i,SZ(todo)){
//     int ak = todo[i];
//     for(int )
//   }
}