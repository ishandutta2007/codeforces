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

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
string kier = "LRDU"; 
struct Sol{
  vector<vector<int>> t;
  vector<vector<int>> typ;
  vector<int> vis;
  vector<vector<int>> d;
  vector<int> s;
  vector<vector<int>> res;
  vector<string> resk;
  int get(int a,int b){
    return a * m + b;
  }
  void add_edge(int a,int b){
    d[a].PB(b);
    d[b].PB(a);
  }
  
  bool dfs(int v){
    if(vis[v])return 0;
    vis[v] = 1;
    for(int el:d[v]){
      if(s[el] == -1 || dfs(s[el])){
        s[v] = el;
        s[el] = v;
        return 1;
      }
    }
    return 0;
  }
  
  void sko(){
    bool x = 1;
    while(x){
      x = 0;
      R(i,n*m)vis[i] = 0;
      R(i,n)R(j,m)if(typ[i][j] == 2){
        int id = get(i,j);
        if(s[id] == -1 && dfs(id)){
          x = 1;
        }
      }
    }
  }
  int n,m;
  void run(){
    cin >> n >> m;
    t.resize(n,vector<int>(m));
    typ.resize(n,vector<int>(m));
    res.resize(n,vector<int>(m));
    
    resk.resize(n,string(m,'?'));
    d.resize(n * m);
    s.resize(n * m, -1);
    vis.resize(n * m);
    
    R(i,n)R(j,m){
      cin >> t[i][j];
    }
    R(i,n)R(j,m)R(k,4){
      int ni = i + dx[k];
      int nj = j + dy[k];
      if(ni >= 0 && ni < n && nj >= 0 && nj < m){
        debug(i,j,ni,nj);
        if(t[i][j] > t[ni][nj]){
          typ[i][j] |= 1;
        }else if(t[i][j] == t[ni][nj]){
          typ[i][j] |= 2;
        }
      }
    }
    debug(typ);
    R(i,n)R(j,m){
      if(typ[i][j] == 0){
        cout << "NO\n";
        return;
      }
    }
    R(i,n-1)R(j,m){
      if(typ[i][j] == 2 && typ[i+1][j] == 2 && t[i][j] == t[i+1][j]){
        add_edge(get(i,j),get(i+1,j));
      }
    }
    R(i,n)R(j,m-1){
      if(typ[i][j] == 2 && typ[i][j+1] == 2 && t[i][j] == t[i][j+1]){
        add_edge(get(i,j),get(i,j+1));
      }
    }
    sko();
    R(i,n-1)R(j,m){
      if(typ[i][j] + typ[i+1][j] == 5 && t[i][j] == t[i+1][j]){
        add_edge(get(i,j),get(i+1,j));
      }
    }
    R(i,n)R(j,m-1){
      if(typ[i][j] + typ[i][j+1] == 5 && t[i][j] == t[i][j+1]){
        add_edge(get(i,j),get(i,j+1));
      }
    }
    sko();
    R(i,n)R(j,m){
      if(typ[i][j] == 2 && s[get(i,j)] == -1){
        cout << "NO\n";
        return;
      }
    }
    R(i,n)R(j,m){
      if(s[get(i,j)] == -1){
        R(k,4){
          int ni = i + dx[k];
          int nj = j + dy[k];
          if(ni >= 0 && ni < n && nj >= 0 && nj < m){
            if(t[i][j] > t[ni][nj]){
              res[i][j] =  t[i][j] - t[ni][nj];
              resk[i][j] = kier[k];
              break;
            }
          }
        }
      }else{
        R(k,4){
          int ni = i + dx[k];
          int nj = j + dy[k];
          if(ni >= 0 && ni < n && nj >= 0 && nj < m){
            if(s[get(i,j)] == get(ni,nj)){
              res[i][j] = t[i][j] / 2;
              res[ni][nj] = (t[i][j] + 1) / 2;
              resk[i][j] = kier[k];
              break;
            }
          }
        }
      }  
    }
    cout << "YES\n";
    R(i,n){
      R(j,m)cout << res[i][j] << " ";
      cout << "\n";
    }
    
    R(i,n){
      R(j,m)cout << resk[i][j] << " ";
      cout << "\n";
    }
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}