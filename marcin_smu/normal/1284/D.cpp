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
vector<int> coef;
int licz(vector<PII> t){
  vector<int> p(n),k(n);
  R(i,n)p[i] = k[i] = i;
  sort(ALL(p), [&](int a,int b){
    return t[a].FI < t[b].FI;
  });
  sort(ALL(k), [&](int a,int b){
    return t[a].SE < t[b].SE;
  });
  int sum = 0;
  int hash = 0;
  int j = 0;
  R(i,n){
    while(j < n && t[p[j]].FI < t[k[i]].SE){
      sum += coef[p[j]];
      j++;      
    }
    hash += sum * coef[k[i]];
    sum -= coef[k[i]];
  }
  return hash;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  srand(time(0));
  cin >> n;
  coef.resize(n);
  vector<PII> p(n),s(n);
  R(i,n){
    coef[i] = ((rand()*1ll) << 32) + ((rand()*1ll) << 16) + rand();
    cin >> p[i].FI >> p[i].SE; p[i].FI--;
    cin >> s[i].FI >> s[i].SE; s[i].FI--;
  }
  if(licz(p) == licz(s)){
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }
}