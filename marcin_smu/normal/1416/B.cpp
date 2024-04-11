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

struct Sol{
  int n;
  vector<vector<int>> out;
  vector<int> t;
  void rusz(int a,int b,int c){
    debug(a,b,c);
    assert(c % (a+1) == 0);
    out.PB({a+1,b+1,c/(a+1)});
    t[a] -= c;
    t[b] += c;
    debug(t);
  }
  void run(){
    cin >> n;
    t.resize(n);
    int sum = 0;
    R(i,n){
      cin >> t[i];
      sum += t[i];
    }
    if(sum % n != 0){
      cout << "-1\n";
      return;
    }
    sum/=n;
    R(_,2){
      vector<PII> p;
      bool cz = 0;
      R(i,n)if(i && t[i]){
        p.PB({((i + 1 - t[i]) % (i+1) + i + 1) % (i+1), i});
      }
      sort(ALL(p));
      R(i,SZ(p)){
        if(t[0] >= p[i].FI){
          rusz(0, p[i].SE, p[i].FI);
          rusz(p[i].SE, 0, t[p[i].SE]);
        }else{
          if(_ == 1){
            cout << "-1\n";
            return;
          }
          cz = 1;
          for(int j = n - 1; j >= 0; j--){
            if(t[j] >= i){
              rusz(j, 0, t[j] / (j + 1) * (j + 1));
            }
          }
        }
      }
      if(!cz)break;
    }
    R(i,n)if(i){
      rusz(0, i, sum);
    }
    cout << SZ(out) << "\n";
    R(i,SZ(out)){
      R(j,3){
        cout << out[i][j] << " ";
      }
      cout << "\n";
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