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
#define MAX 1001001
int n,m,nn;
int io=0,pre[MAX],post[MAX];
bool odw[MAX];
vector<int> d[MAX];
void dfs(int a){
  if(odw[a])return;
  odw[a] = 1;
  pre[a] = io;
  io++;
  for(int ak:d[a])dfs(ak);
  post[a] = io;
};
int dp[MAX],il[MAX],res[MAX];
struct event{
  int y,x1,x2;
  bool co;
  void add(int nr,int po,int ko){
    if(po >= x2 || ko <= x1)return;
    if(x1 <= po && ko <= x2){
      il[nr] += co ? 1 : -1;
    }else{
      add(nr*2,po,(po+ko)/2);
      add(nr*2+1,(po+ko)/2,ko);
    }
    if(il[nr])
      dp[nr] = ko - po;
    else
      dp[nr] = dp[nr*2] + dp[nr*2+1];
  }
  void go(){
    add(1,0,nn-1);
  }
};
vector<event> events;
void add(int x1,int x2,int y1,int y2){
  events.PB({y1,x1,x2,1});
  events.PB({y2,x1,x2,0});
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  nn = 1;while(nn <= n)nn*=2;
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  dfs(0);
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    add(pre[a],post[a],pre[a],post[a]);
    add(pre[a],post[a],pre[b],post[b]);
    add(pre[b],post[b],pre[b],post[b]);
    add(pre[b],post[b],pre[a],post[a]);
  }
  events.PB({(int)1e9,0,0,false});
  sort(ALL(events),[](const event& a, const event& b){
    return a.y < b.y;
  });
  int j = 0;
  R(i,n){
    while(events[j].y == i){
      events[j].go();
      j++;
    }
    res[i] = max(dp[1]-1,0ll);
  }
  R(i,n)
    cout << res[pre[i]] << "\n";
}