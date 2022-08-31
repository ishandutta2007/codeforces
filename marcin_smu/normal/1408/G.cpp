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

int P = 998244353;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
int mul(int a,int b){
  return a * b % P;
}
vector<int> f;
vector<vector<int>> res;
vector<int> ile;
int find(int a){
  return a == f[a] ? a : f[a] = find(f[a]);
}

void uni(int a,int b){
  a = find(a);
  b = find(b);
  if(a == b){
    ile[a]++;
    debug(ile[a]);
    if(ile[a] == SZ(res[a]) * (SZ(res[a]) - 1) / 2){
      res[a][0] = 1;
    }
    return;
  }
  vector<int> pom(SZ(res[a]) + SZ(res[b]));
  R(i,SZ(res[a]))R(j,SZ(res[b])){
    add(pom[i+j + 1], mul(res[a][i],res[b][j]));
  }
  
  if(SZ(pom) == 2)
    pom[0] = 1;
  
  debug(res[a],res[b],pom);
  
  swap(res[b],pom);
  res[a].clear();
  ile[b] += ile[a] + 1;
  f[a] = b;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<pair<int,PII>> ed;
  vector<vector<int>> t(n,vector<int>(n));
  R(i,n)R(j,n){
    cin >> t[i][j];
    if(i < j){
      ed.PB({t[i][j], {i,j}});
    }
  }
  sort(ALL(ed));
  f.resize(n);
  res.resize(n,{1});
  ile.resize(n);
  R(i,n){
    f[i] = i;
  }
  for(auto el:ed){
    uni(el.SE.FI,el.SE.SE);
  }
  R(i,n)if(f[i] == i){
    for(int el: res[i]){
      cout << el << " ";
    }
    cout << "\n";
  }
}