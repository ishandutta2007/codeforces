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

const int MAX = 15;
void nope(){
  cout << "No\n";
  exit(0);
}
int n;
map<int,int> gd;
int s[MAX];
vector<PII> podz[1 << MAX];
int dp[1 << MAX];
int res1[MAX];
int res2[MAX];
void dodaj(vector<PII> t){
  debug(t);
  t.PB(t[0]);
  R(i,SZ(t)-1){
    res1[t[i].SE] = t[i].FI;
    res2[t[i + 1].SE] = t[i].SE;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  int sum = 0;
  R(i,n){
    int x;
    cin >> x;
    R(_,x){
      int pom;
      cin >> pom;
      sum += pom;
      s[i] += pom;
      gd[pom] = i;
    }
  }
  debug(sum);
  if(sum % n != 0){
    nope();
  }
  sum /= n;
  debug(sum);
  for(auto el:gd){
    int mb = 1 << el.SE;
    int ak = el.FI;
    int kt = el.SE;
    vector<PII> res;
    do{
      debug(ak,kt);
      res.PB({ak, kt});
      ak = sum - (s[kt] - ak);
      if(ak == el.FI){
        debug("ok",mb,res);
        podz[mb] = res;
        break;
      }
      auto xxx = gd.find(ak);
      if(xxx == gd.end())break;
      kt = xxx->SE;
      if(((mb >> kt) & 1))break;
      mb += 1 << kt;
    }while(1);
  }
  dp[0] = -1;
  for(int mb = 1; mb < (1 << n); mb++){
    for(int mb2 = mb; mb2; mb2 = (mb2 - 1)& mb)if(SZ(podz[mb2]) && dp[mb ^ mb2] != 0){
      dp[mb] = mb2;
      break;
    }
  }

  int ak = (1 << n)-1;
  if(dp[ak]){
    cout << "Yes\n";
    while(ak){
      int pom = dp[ak];
      dodaj(podz[pom]);
      ak ^= pom;
    }
    R(i,n){
      cout << res1[i] << " " << res2[i] + 1 << "\n";
    }
  }else{
    nope();
  }
}