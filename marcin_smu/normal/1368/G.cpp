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

int n,m;
vector<string> t;
string kier = "UDLR";
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int get(int i,int j){
//   debug(i,j);
  if(i < 0 || i >= n || j < 0 || j >= m)return -1;
  return i * m + j;
}
vector<int> korz;
vector<vector<int>> d;
void add_edge(int a,int b){
  debug("add_edge",a,b);
  if(a != -1 && b != -1){
    d[a].PB(b);
  }else{
    korz[b] = 1;
  }
}
vector<int> pre,post;
int o;
void dfs(int a){
  pre[a] = o;o++;
  for(int el:d[a]){
    dfs(el);
  }
  post[a] = o;
}

struct odc{
  int po,ko;
  int znak;
};
vector<vector<odc>> zap;
vector<int> dp;
vector<int> all;
int nn;
void ak(int nr,int sze){
  if(dp[nr]){
    all[nr] = sze;
  }else{
    if(nr >= nn){
      all[nr] = 0;
    }else{
      all[nr] = all[nr*2] + all[nr*2+1];
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  t.resize(n);
  d.resize(n * m);
  korz.resize(n * m);
  R(i,n){
    cin >> t[i];
    R(j,m){
      R(k,4)if(t[i][j] == kier[k]){
//         debug(i,j,k);
        add_edge(get(i - dx[k] * 2,j - dy[k] * 2), get(i,j));
      }
    }
  }
  pre.resize(n * m);
  post.resize(n * m);
  R(_,2){
    o = 0;
    R(i,n)R(j,m){
      if((i + j) % 2 == _ && korz[get(i,j)])
        dfs(get(i,j));
    }
  }
  debug(korz,pre,post);
  zap.resize(n * m / 2 + 1);
  R(i,n)R(j,m){
    if((i + j) % 2 == 0){
      int id = get(i,j);
      int id2 = -1;
      R(k,4)if(t[i][j] == kier[k]){
        id2 = get(i - dx[k],j - dy[k]);
      }
      debug(id,id2);
      zap[pre[id]].PB({pre[id2],post[id2],1});      
      zap[post[id]].PB({pre[id2],post[id2],-1});
    }
  }
  
  nn = 1;
  while(nn <= n * m / 2) nn *= 2;
  dp.resize(nn * 2);
  all.resize(nn * 2);
  int res = 0;
  debug(nn);
  
  R(i,n*m / 2){
    for(auto el:zap[i]){
      function<void(int,int,int)> rec = [&](int nr,int po,int ko){
        if(po >= el.ko || el.po >= ko)return;
        if(el.po <= po && ko <= el.ko){
          if(el.znak == 1){
            dp[nr]++;
          }else{
            dp[nr]--;
          }
          ak(nr, ko - po);
          return;
        }
        rec(nr * 2, po, (po+ko) / 2);
        rec(nr * 2+1, (po + ko)/2, ko);
        ak(nr, ko - po);
      };
      rec(1,0,nn);
    }
    debug(all, dp);
    res += all[1];
  }
  cout << res << "\n";
}