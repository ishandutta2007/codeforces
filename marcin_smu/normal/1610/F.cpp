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
vector<int> a,b;
vector<vector<int>> d1,d2;
vector<int> out;
vector<int> gd1,gd2;
vector<int> vis;

bool dfs(int i,int last){
  int ak = i;
  int x = 0;
  while(1){
    if(last == 1 || last == -1){
      for(;gd1[ak] < SZ(d1[ak]);gd1[ak]++){
        int pom = d1[ak][gd1[ak]];
        if(out[pom] == 0){
          if(a[pom] == ak){
            out[pom] = 1;
            ak = b[pom];
          }else{
            out[pom] = 2;
            ak = a[pom];
          }
          vis[a[pom]]++;
          vis[b[pom]]++;
          x = 1;
          last = 1;
          goto ok;
        }
      }
    }
    if(last == 2 || last == -1 || (SZ(d1[ak]) + SZ(d2[ak])) % 2 == 0){
      for(;gd2[ak] < SZ(d2[ak]);gd2[ak]++){
        int pom = d2[ak][gd2[ak]];
        if(out[pom] == 0){
          if(a[pom] == ak){
            out[pom] = 1;
            ak = b[pom];
          }else{
            out[pom] = 2;
            ak = a[pom];
          }
          vis[a[pom]]++;
          vis[b[pom]]++;
          x = 1;
          last = 2;
          goto ok;
        }
      }
    }
    if((SZ(d1[ak]) + SZ(d2[ak])) % 2 == 0){
      for(;gd1[ak] < SZ(d1[ak]);gd1[ak]++){
        int pom = d1[ak][gd1[ak]];
        if(out[pom] == 0){
          if(a[pom] == ak){
            out[pom] = 1;
            ak = b[pom];
          }else{
            out[pom] = 2;
            ak = a[pom];
          }
          vis[a[pom]]++;
          vis[b[pom]]++;
          x = 1;
          last = 1;
          goto ok;
        }
      }
    }
    
    break;
    ok:;
  }
  return x;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  a.resize(m);
  b.resize(m);
  out.resize(m);
  d1.resize(n);
  d2.resize(n);
  gd1.resize(n);
  gd2.resize(n);
  vis.resize(n);
  vector<int> c(m);
  R(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;b[i]--;
    if(c[i] == 1){
      d1[a[i]].PB(i);
      d1[b[i]].PB(i);
    }else{
      d2[a[i]].PB(i);
      d2[b[i]].PB(i);
    }
  }
  int res = 0;
  R(i,n)if(SZ(d1[i]) & 1)res++;
  cout << res << "\n";
  
  R(i,n)if((SZ(d1[i]) + SZ(d2[i]) - vis[i]) & 1){
    if(SZ(d1[i]) & 1)
      dfs(i,1);
    else
      dfs(i,2);
  }
  R(i,n)while(dfs(i,-1));
  for(int el:out)cout << el;
  cout << "\n";
  
}