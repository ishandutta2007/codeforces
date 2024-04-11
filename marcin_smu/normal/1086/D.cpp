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
string s;
const int MAX = 200010;
int dp[3][MAX];
set<int> gd[3];
void add(int kt,int x){
  gd[kt].insert(x);
  for(x++;x<=n;x+=x&-x){
    dp[kt][x]++;
  }
}
void us(int kt,int x){
  gd[kt].erase(x);
  for(x++;x<=n;x+=x&-x){
    dp[kt][x]--;
  }
}
int sum(int kt,int x){
  int res = 0;
  for(x ++; x; x-=x&-x){
    res += dp[kt][x];
  }
  return res;
}
int pref(int kt){
  int res = 1e9;
  R(i,3)if(i != kt){
    if(SZ(gd[i]))
      mini(res, *gd[i].begin());
  }
  return res;
}
int suf(int kt){
  int res = 1e9;
  R(i,3)if(i != kt){
    if(SZ(gd[i]))
      mini(res, n - *gd[i].rbegin() - 1);
  }
  return res;
}


int licz(int kt,int gorszy, int lepszy){
  if(SZ(gd[gorszy]) == 0){
    if(SZ(gd[lepszy]) == 0){
      return SZ(gd[kt]);
    }else{
      return 0;
    }
  }else{
    debug(gorszy, SZ(gd[gorszy]));
    return pref(kt) + suf(kt) + sum(kt, *gd[gorszy].rbegin()) - sum(kt, *gd[gorszy].begin());
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> s;
  for(char &el:s){
    el -= 'P';
    if(el)el--;
  }
  R(i,n){
    add(s[i], i);
  }
  R(i,m+1){
    cout << licz(0,1,2) + licz(1,2,0) + licz(2,0,1) << "\n";
    if(i == m)break;
    int id;
    char co;
    cin >> id >> co;
    id--;
    co -= 'P';if(co)co--;
    us(s[id], id);
    s[id] = co;
    add(s[id], id);
  }
  
}