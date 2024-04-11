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

vector<PII> out;
void add_edge(int a,int b){
  out.PB({a,b});
}

void get_same(int po,int ko){
  if(ko - po == 1)return;
  int m = (po + ko) / 2;
  get_same(po,m);
  get_same(m,ko);
  R(i,m - po){
    add_edge(po + i, m + i);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<vector<int>> t;
  int siz = 1;
  while(n){
    if(n & siz){
      get_same(n - siz,n);
      vector<int> pom(siz);
      R(i,siz){
        pom[i] = i + n - siz;
      }
      t.PB(pom);
      n -= siz;
    }
    siz *= 2;
  }
  reverse(ALL(t));
  while(SZ(t) > 2){
    vector<int> pom;
    swap(pom,t.back());
    t.pop_back();
    if(SZ(t.back()) == SZ(pom)){
      vector<int> pom2;
      swap(pom2,t.back());
      t.pop_back();
      R(i,SZ(pom)){
        add_edge(pom[i],pom2[i]);
      }
      R(i,SZ(pom2))pom.PB(pom2[i]);
      t.PB(pom);
    }else{
      int xx = SZ(pom);
      R(i,xx){
        add_edge(pom[i], t[0].back());
        pom.PB(t[0].back());
        t[0].pop_back();
      }
      t.PB(pom);
    }
  }
  cout << SZ(out) << "\n";
  for(PII el:out){
    cout << el.FI + 1 << " " << el.SE + 1 << "\n";
  }
}