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

const int MAX = 300100;
vector<int> d[MAX];
vector<vector<int>> res;
vector<int> st;
int vis[MAX];
int nope[MAX];
int n,m,k;
int gl[MAX];
void dfs(int nr,int par){
  st.PB(nr);
  debug(nr,par,st);
  vis[nr] = 1;
  if(SZ(st) * k >= n){
    cout << "PATH\n";
    cout << SZ(st) << "\n";
    for(int el:st){
      cout << el+1 << " ";
    }
    cout << "\n";
    exit(0);
  }
  for(int el:d[nr]){
    if(vis[el] == 0){
      gl[el] = gl[nr] + 1;
      dfs(el, nr);
    }
  }
  if(!nope[nr]){
    vector<int> xxx;
    for(int el:d[nr]){
      vector<int> pom;
      if(vis[el] == 1 && el != par){
        if((gl[nr] - gl[el] + 1) % 3 != 0){
          vector<int> cyc;
          for(int i = SZ(st) - 1; st[i] != el; i--){
            cyc.PB(st[i]);
          }
          cyc.PB(el);
          for(int xx:cyc){
            nope[xx] = 1;
          }
          res.PB(cyc);
          goto end;
        }else{
          xxx.PB(gl[el]);
        }
      }
    }
    debug(xxx);
    if(SZ(xxx) >= 2){
      vector<int> cyc;
      cyc.PB(nr);
      if(xxx[0] > xxx[1])swap(xxx[0],xxx[1]);
      for(int i = xxx[0]; i <= xxx[1]; i++){
        cyc.PB(st[i]);
      }
      debug(cyc);
      res.PB(cyc);
    }
    end:;
    if(SZ(res) == k){
      cout << "CYCLES\n";
      for(auto& x:res){
        cout << SZ(x) << "\n";
        for(int xx:x){
          cout << xx + 1 << " ";
        }
        cout << "\n";
      }
      exit(0);
    }
  }
  vis[nr] = 2;
  st.pop_back();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> k;
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  dfs(0, -1);
  assert(0);
}