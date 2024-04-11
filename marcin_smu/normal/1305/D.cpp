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

int n;
vector<vector<int>> d;
vector<int> deg;
int ask(int a,int b){
  cout << "? " << a + 1 << " " << b + 1 << endl;
  int res;
  cin >> res;
  return res - 1;
}
vector<int> lisc;
bool dfs(int a,int oj){
  if(a == lisc[0] || a == lisc[1])return 1;
  for(int el:d[a])if(el != oj){
    if(dfs(el, a))return 1;
  }
  return 0;
}
void us(int a,int oj){
  deg[a] = 0;
  for(int el:d[a])if(el != oj){
    us(el, a);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  d.resize(n);
  deg.resize(n);
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
    deg[a]++;
    deg[b]++;
  }
  while(1){
    lisc.clear();
    R(i,n)if(deg[i] == 1)lisc.PB(i);
    int pom = ask(lisc[0],lisc[1]);
    R(i,2){
      if(pom == lisc[i]){
        cout << "! " << pom + 1 << "\n";
        return 0;
      }
    }
    if(deg[pom] == 2){
      cout << "! " << pom + 1 << "\n";
      return 0;
    }
    R(i,SZ(d[pom])){
      if(dfs(d[pom][i],pom)){
        us(d[pom][i],pom);
        d[pom][i] = d[pom].back();
        d[pom].pop_back();
        i--;
      }
    }
    deg[pom]-=2;
    
    
  }
}

/*
7
1 2
1 3
2 4
2 5
3 6
3 7
*/