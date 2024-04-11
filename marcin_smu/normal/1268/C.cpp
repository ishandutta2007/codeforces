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

template<class T> ostream &operator<<(ostream& os, set<T> V) {
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

const int MAX = 200100;
int n;
int dp[MAX];
void add(int x){
  for(x++;x <= n;x+=x&-x){
    dp[x]++;
  }
}
int sum(int x){
  int res = 0;
  for(x++;x;x -= x&-x){
    res += dp[x];
  }
  return res;
}
int res[MAX];
int t[MAX];

int prze(int a,int b){
  debug(a,b,sum(a),sum(b));
  return b - a - sum(b) + sum(a);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    int pom;
    cin >> pom;
    pom--;
    res[pom] = pom - sum(pom);
    add(pom);
    t[pom] = i;
  }
  R(i,n+1){
    dp[i] = 0;
  }
  set<int> l,r;
  int wyn = 0;
  int inv = 0;
  int sr = -1;
  R(i,n){
    int x = t[i];
    inv += res[i];
    int xx = sum(x);
    add(x);
    
    debug(x, xx, i - xx);
    wyn -= min(xx, i - xx);
    debug(wyn,sr,i);
    if(i & 1){
      if(sr > x)swap(sr,x);
      wyn += prze(sr,x);
      l.insert(sr);
      r.insert(x);
    }else{
      if(i){
        int sr1 = *l.rbegin();
        int sr2 = *r.begin();
        debug(sr1,sr2,x);
        if(x < sr1){
          l.erase(sr1);
          l.insert(x);
          wyn += prze(x,sr1);
          sr = sr1;
        }else if (x < sr2){
          sr = x;
        }else{
          r.erase(sr2);
          r.insert(x);
          wyn += prze(sr2,x);
          sr = sr2;
        }
      }else{
        sr = x;
      }
    }
    assert(SZ(l) == SZ(r));
    debug(wyn,inv);
    debug(i,l,r);
    cout << wyn + inv << " ";
    cerr << "\n\n";
  }
  cout << "\n";
}