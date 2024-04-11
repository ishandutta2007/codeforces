//try 11
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
     
    const int MAX = 1e6 + 5;
    int np[MAX];
    int koszt[MAX];
    int n,k;
    int ilepom[MAX],ile[MAX];
    const int inf = 1e18;
    int licz(){
      set<PII> secik;
      for(int i = 3; i<=n; i++){
        if(ile[i] == 0)
          secik.insert({koszt[i],i});
      }
      int res = 0;
      R(_,k){
        if(secik.empty())return inf;
        PII pom = *secik.begin();
        debug(pom);
        res += pom.FI;
        secik.erase(secik.begin());
        for(int j = 2; j * pom.SE <= n; j++){
          int i = j * pom.SE;
          koszt[i] -= pom.FI;
          ile[i]--;
          if(ile[i] == 0)
            secik.insert({koszt[i],i});
        }
      }
      return res;
    }
    int32_t main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout << fixed << setprecision(11);
      cerr << fixed << setprecision(6);
      cin >> n >> k;
      for(int i = 3; i <= n; i++){
        for(int j = 2; i * j <= n; j++){
          ilepom[i*j] ++;
        }
      }
      R(i,n + 1){
        koszt[i] = (i%2 ? i - 1 : inf);
        ile[i] = (i % 2 ? ilepom[i] : inf);
      }
      int res1 = licz() + 1;
      R(i,n + 1){
        koszt[i] = i - (i % 2 ? 1 : 2);
        ile[i] = ilepom[i];
      }
      int res2 = licz() + 2;
      debug(res1,res2);
      cout << min(res1,res2) << "\n";
    }