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

const int MAX = 50001;
struct d3{
  int a,b,c,id;
  bool operator<(d3 pom){
    if(a != pom.a)return a < pom.a;
    if(b != pom.b)return b < pom.b;
    return c < pom.c;
  }
};
int n;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  vector<d3> t(n);
  R(i,n){
    cin >> t[i].a >> t[i].b >> t[i].c;
    t[i].id = i + 1;
  }
  sort(ALL(t));
  vector<d3> pom;
  R(i,SZ(t))if(i != SZ(t) - 1 && t[i].a == t[i+1].a && t[i].b == t[i+1].b){
    cout << t[i].id << " " << t[i+1].id << "\n";
    i++;
  }else{
    pom.PB(t[i]);
  }
  t.clear();
  swap(t,pom);
  R(i,SZ(t))if(i != SZ(t) - 1 && t[i].a == t[i+1].a){
    cout << t[i].id << " " << t[i+1].id << "\n";
    i++;
  }else{
    pom.PB(t[i]);
  }
  t.clear();
  swap(t,pom);
  R(i,SZ(t))if(i != SZ(t)){
    cout << t[i].id << " " << t[i+1].id << "\n";
    i++;
  }
}