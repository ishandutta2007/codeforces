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

int n,r1,r2,r3,d;
__int128_t inf = 1e30;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> r1 >> r2 >> r3 >> d;
  __int128_t s1,s2,s3;
  {
    int pom;
    cin >> pom;
    __int128_t ca = pom * r1 + r3;
    __int128_t cb = min(pom * r1 + r3, min(r1 * (pom + 2),r1 + r2));
    s1 = ca ,s2 = cb, s3 = cb;
  } 
  R(i,n-2){
    int pom;
    cin >> pom;
    __int128_t ca = pom * r1 + r3;
    __int128_t cb = min(pom * r1 + r3, min(r1 * (pom + 2),r1 + r2));
    
    __int128_t n1 = min(s1 + ca + d, min(s3, s1) + cb + 3 * d);
    __int128_t n2 = min(s1 + cb + d, s2 + cb + 2 * d);
    __int128_t n3 = s1 + cb + d;
    s1 = n1;
    s2 = n2;
    s3 = n3;
    debug((int)s1,(int)s2,(int)s3);
  }
  
  int pom;
  cin >> pom;
  __int128_t ca = pom * r1 + r3;
  __int128_t cb = min(pom * r1 + r3, min(r1 * (pom + 2),r1 + r2));
  __int128_t  res = inf;
  mini(res, s1 + ca + d);
  mini(res, s1 + cb + 3 * d);
  mini(res, s2 + ca + 2 * d);
  mini(res, s2 + cb + 4 * d);
  mini(res, s3 + cb + 3 * d);
  cout << (int)res << "\n";
}