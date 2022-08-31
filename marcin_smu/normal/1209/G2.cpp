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

const int MAX=200100;
set<int> gd[MAX];
struct node{
  int cal;
  int naj;
  int najpref;
  int najsuf;
  int pref;
  int suf;
  bool ok;
}dp[1<<19];
int t[MAX];
int n,nn,q;

void ak(int v){
  int sze = 1;
  while(v != 1){
    v /= 2;
    dp[v].naj = max(dp[v * 2].naj, dp[v*2+1].naj);
    dp[v].cal = 0;
    dp[v].ok = 0;
    dp[v].najpref = 0;
    dp[v].najsuf = 0;
    dp[v].pref = dp[v*2].pref;
    dp[v].suf = dp[v*2+1].suf;
    if(dp[v * 2].suf > sze){
      maxi(dp[v].suf,dp[v*2].suf - sze);
      maxi(dp[v].najsuf,max(dp[v*2+1].naj,dp[v*2].najsuf)); 
    }else{
      if(dp[v * 2 + 1].pref <= sze){
        if(dp[v*2].ok && dp[v*2+1].ok){
          dp[v].cal += max(dp[v*2+1].najpref,dp[v*2].najsuf);
        }
        if(!dp[v*2].ok){
          maxi(dp[v].najpref, max(dp[v*2+1].najpref,dp[v*2].najsuf));
        }
        if(!dp[v*2+1].ok){
          maxi(dp[v].najsuf, max(dp[v*2+1].najpref,dp[v*2].najsuf));
        }
      }
      dp[v].ok |= dp[v*2+1].ok;
      dp[v].cal += dp[v*2+1].cal;
      maxi(dp[v].najsuf, dp[v*2+1].najsuf);
    }
    if(dp[v * 2 + 1].pref > sze){
      maxi(dp[v].pref,dp[v*2+1].pref - sze);
      maxi(dp[v].najpref,max(dp[v*2].naj,dp[v*2+1].najpref)); 
    }else{
      dp[v].ok |= dp[v*2].ok;
      dp[v].cal += dp[v*2].cal;
      maxi(dp[v].najpref, dp[v*2].najpref);
    }
    debug(v, dp[v].cal, dp[v].naj, dp[v].najpref, dp[v].najsuf, dp[v].pref, dp[v].suf, dp[v].ok);
    sze *= 2;
  }
}

void dodaj(int i){
  int kr = SZ(gd[i]);
  if(!kr)return;
  int a = *gd[i].begin();
  if(kr == 1){
    dp[a + nn] = {1,1,0,0,0,0,true};
    ak(a + nn);
  }else{
    int b = *gd[i].rbegin();
    dp[a + nn] = {0,kr,0,kr,0,b-a,true};
    dp[b + nn] = {0,kr,kr,0,b - a,0,true};
    ak(a + nn);
    ak(b + nn);
  }
}

void us(int i){
  node empty = {0,0,0,0,0,0,false};
  int kr = SZ(gd[i]);
  if(!kr)return;
  int a = *gd[i].begin();
  if(kr == 1){
    dp[a + nn] = empty;
    ak(a + nn);
  }else{
    int b = *gd[i].rbegin();
    dp[a + nn] = empty;
    dp[b + nn] = empty;
    ak(a + nn);
    ak(b + nn);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  nn = 1;while(nn <= n) nn *= 2;
  R(i,n){
    cin >> t[i];
    gd[t[i]].insert(i);
  }
  R(i,MAX)dodaj(i);
  cout << n - dp[1].cal << "\n";
  R(i,q){
    int a,v;
    cin >> a >> v;a--;
    us(t[a]);
    gd[t[a]].erase(a);
    dodaj(t[a]);
    us(v);
    t[a] = v;
    gd[v].insert(a);
    dodaj(v);
    cout << n - dp[1].cal << "\n";
  }
}