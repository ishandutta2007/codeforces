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

vector<vector<int>> d;
vector<int> pre,post;
int id = 0;
vector<int> par;
void dfs(int v,int oj){
  par[v] = oj;
  pre[v] = id;
  id ++;
  R(i,SZ(d[v])){
    if(d[v][i] == oj){
      swap(d[v][i], d[v].back());
      i--;
      d[v].pop_back();
    }else{
      dfs(d[v][i],v);
    }
  }
  post[v] = id;
}

vector<int> dp,ak;
int nn = 1;
void licz(int nr){
  if(ak[nr] == 0){
    if(nr >= nn){
      dp[nr] = 1;
    }else{
      dp[nr] = dp[nr*2] + dp[nr*2+1];
    }
  }else{
    dp[nr] = 0;
  }
}
int n,q;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  d.resize(n);
  pre.resize(n);
  post.resize(n);
  par.resize(n);
  vector<int> p;
  R(i,n)p.PB(i);
   random_shuffle(ALL(p));
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    a = p[a];
    b = p[b];
    d[a].PB(b);
    d[b].PB(a);
  }
  dfs(0,-1);
  debug(pre,post);
  while(nn <= n)nn *= 2;
  dp.resize(nn * 2);
  ak.resize(nn * 2);
  R(i,nn){
    if(i < n){
      dp[i + nn] = 1;
    }else{
      ak[i + nn] = 1;
    }
  }
  for(int i = nn-1;i >= 1;i--){
    dp[i] = dp[i*2] + dp[i*2 + 1];
  }
  debug(dp[1]);
  set<PII> secik;
  R(i,q){
    int a,b;
    cin >> a >> b;
    a--;b--;
    a = p[a];
    b = p[b];
    if(pre[a] > pre[b])swap(a,b);
    int mn = 1;
    auto xxx = secik.find({a,b});
    if(xxx != secik.end()){
      secik.erase({a,b});
      mn = -1;
    }else{
      secik.insert({a,b});
    }
    vector<PII> prze;
    if(post[a] <= pre[b]){
      prze.PB({0,pre[a]});
      prze.PB({post[a],pre[b]});
      prze.PB({post[b],n});
    }else{
      int po = 0,ko = SZ(d[a]);
      debug(d[a]);
      while(1){
        int m = d[a][(po + ko) / 2];
        debug(pre[m], pre[b],post[m], post[b]);
        if(pre[m] <= pre[b]){
          if(post[m] >= post[b]){
            prze.PB({pre[m],pre[b]});
            prze.PB({post[b],post[m]});
            break;
          }else{
            po = (po + ko) / 2;
          }
        }else{
          ko = (po + ko) / 2;
        }
      }
    }
    int po;
    int ko;
    function<void(int,int,int)> add = [&](int nr,int beg,int en){
      if(beg >= ko || po >= en)return;
      if(po <= beg && en <= ko){
        ak[nr] += mn;
        licz(nr);
        return;
      }
      add(nr * 2, beg, (beg + en) / 2);
      add(nr * 2 + 1, (beg + en) / 2, en);
      licz(nr);
    };
    debug(prze,mn);
    for(PII el:prze){
      po = el.FI;
      ko = el.SE;
      add(1,0,nn);
    }
    cout << dp[1] << "\n";
  }
}