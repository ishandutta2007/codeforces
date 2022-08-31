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

struct Euler {
  struct Edge {
    int nei, nr;
    int kier;
  };
  vector<vector<Edge>> slo;
  vector<int> ans, used, deg, beg;
  int e_num, n;
  Euler() : e_num(0), n(0) {}
  void AddEdge(int a, int b) {
    e_num++;
    if (a > n || b > n) {
      n = max(a, b);
      slo.resize(n + 2);
      deg.resize(n + 2);
      beg.resize(n + 2);
    }
    used.PB(0);
    slo[a].PB({b, e_num, 1});
    slo[b].PB({a, e_num, 0});
    deg[a]++;
    deg[b]++;
  }
  vector<int> FindEuler(int x) { // if used many times, please clear ans, beg, used
    used.PB(0);
    assert(SZ(used) > e_num);
//     RE (i, n) {
//       if (deg[i] % 2 == 1) {
//         return vector<int>();
//       }
//     }
    Go(x);
    return ans;
  }
private:
  void Go(int v) {
   // debug(v);
    while (beg[v] < SZ(slo[v])) {
      Edge& e = slo[v][beg[v]];
      beg[v]++;
      int nei = e.nei;
      if (used[e.nr]) { continue; }
      used[e.nr] = 1;
      Go(nei);
      if(e.kier == 0){
        ans.PB(e.nr * 2 - 1);
        ans.PB(e.nr * 2);
      }else{
        ans.PB(e.nr * 2);
        ans.PB(e.nr * 2 - 1);
      }
    }
  }
};

const int MAX = 1 << 19;
int f[MAX*2];
int find(int a){
  return f[a] == a ? a : f[a] = find(f[a]);
}
int XXX;
void uni(int a,int b){
  a = find(a);
  b = find(b);
  if(a == b)return;
  f[a] = b;
  XXX++;
}
int a[MAX],b[MAX];
int d[MAX*2];
int n,m;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> m;
  R(i,m){
    cin >> a[i] >> b[i];
  }
  int res = 20;
  while(1){
    n = 1 << res;
    R(i,n){
      f[i] = i;
      d[i] = 0;
    }
    XXX = 0;
    R(i,m){
      int aa = a[i] & ((1 << res)-1);
      int bb = b[i] & ((1 << res)-1);
      uni(aa,bb);
      d[aa]++;
      d[bb]++;
    }
    bool ok = 1;
    R(i,n){
      if(d[i] & 1)ok = 0;
      if(d[i])XXX--;
    }
    if(XXX != -1) ok = 0;
    if(ok){
      cout << res << "\n";
      Euler x;
      R(i,m){
        int aa = a[i] & ((1 << res)-1);
        int bb = b[i] & ((1 << res)-1);
        x.AddEdge(aa + 1, bb + 1);
      }
      R(i,n){
        if(d[i]){
          vector<int> wyn = x.FindEuler(i + 1);
          for(int el:wyn){
            cout << el << " ";
          }
          cout << "\n";
          return 0;
        }
        
      }
    }
    res--;
  }
}