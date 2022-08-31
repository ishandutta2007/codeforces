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

int n,k;
vector<int> t;
int bil;
void print(){
  int zap = bil / k;
  debug(t);
  int res = 0;
  R(_,zap){
    vector<int> kt(n);
    R(i,n)kt[i] = i;
    sort(ALL(kt), [&](int a,int b){
      return t[a] > t[b];
    });
    cout << "? ";
    R(i,k){
      cout << kt[i] + 1 << " ";
      t[kt[i]]--;
    }
    cout << endl;
#ifndef LOCAL
    int pom;
    cin >> pom;
    res ^= pom;
#endif
  }
#ifdef LOCAL
  R(i,n)assert(t[i] == 0);
#endif
  cout << "! " << res << "\n";
  exit(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  if(n % 2 == 1 && k % 2 == 0){
    cout << "-1" << endl;
    return 0;
  }
  t.resize(n,1);
  bil = n;
  if(bil % k == 0){
    print();
  }
  while(1){
    R(i,n){
      t[i] += 2;
      bil += 2;
      if(bil % k == 0 && bil / k >= t[i]){
        print();
      }
    }
  }
}