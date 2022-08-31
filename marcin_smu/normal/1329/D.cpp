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

// #define TEST 

const int ALFA = 'z' - 'a' + 1;
struct Sol{
  int n,s;
  string z;
  vector<int> dp;
  
  void dod(int x,int il){
    debug("dod",x,il);
    for(x++;x <= n + 1; x+=x&-x){
      dp[x] += il;
    }
  }
  int sum(int x){
    int res = 0;
    for(x++;x;x-=x&-x){
      res += dp[x];
    }
    return res;
  }
  vector<int> nast;
  vector<int> pop;
  vector<vector<int>> gd;
  vector<int> zle;
  vector<int> ile;
  
  void dodaj(int a,int b){
    if(a != -1){
      nast[a] = b;
    }
    if(b != n){
      pop[b] = a;
    }
    debug(a,b);
    if(a != -1 && b != n && z[a] != z[b]){
      gd[(int)z[a]].PB(a);
      gd[(int)z[b]].PB(a);
    }
  }
  vector<PII> wyn;
  void rusz(int a,int b){
    debug("rusz",a,b);
    int a2 = a - sum(a);
    int b2 = b - sum(b-1);
    debug(a2,b2);
    wyn.PB({a2,b2});
    dod(b, b2-a2);
  }
  
  bool probuj(int x,int val){
    if(zle[x] == 0 || nast[x] == n || zle[nast[x]] == 0 || z[x] == z[nast[x]])return 0;
    if(z[x] != val && z[nast[x]] != val)return 0;
    zle[x] = 0;
    zle[nast[x]] = 0;
    ile[(int)z[x]]--;
    ile[(int)z[nast[x]]]--;
    dodaj(pop[x], nast[nast[x]]);
    rusz(x+1,nast[x]+1);
    return 1;
  }
  void run(){
    cin >> z;
#ifdef TEST
    string z2 = z;
#endif
    n = SZ(z);
    dp.resize(n + 2);
    pop.resize(n, -1);
    nast.resize(n, n);
    zle.resize(n);
    ile.resize(ALFA);
    gd.resize(ALFA);
    R(i,n)z[i] -= 'a';
    int ost = -1;
    R(i,n-1){
      if(z[i] == z[i+1]){
        zle[i] = 1;
        ile[(int)z[i]]++;
        dodaj(ost,i);
        ost = i;
      }
    }
    while(1){
      int naj = 0;
      R(i,ALFA){
        if(ile[naj] < ile[i]){
          naj = i;
        }
      }
      debug(naj,ile[naj]);
      if(ile[naj] == 0)break;
      while(SZ(gd[naj])){
        int ak = gd[naj].back();
        gd[naj].pop_back();
        if(probuj(ak,naj)){
          goto ok;
        }
      }
      break;
      ok:;
    }
    debug("koniec");
    int ILE = 0;
    R(i,ALFA){
      if(ile[i] != 0)ILE ++;
    }
    assert(ILE <= 1);
    R(i,n){
      if(zle[i]){
        rusz(0,i+1);
      }
    }
    rusz(0,n);
    cout << SZ(wyn) << "\n";
    for(PII el:wyn){
#ifdef TEST
      assert(el.FI < el.SE);
      for(int i = el.FI;i < el.SE - 1;i++){
        assert(z2[i] != z2[i + 1]);
      }
      z2 = z2.substr(0,el.FI) + z2.substr(el.SE);
#endif
      cout << el.FI + 1 << " " << el.SE << "\n";
    }
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}