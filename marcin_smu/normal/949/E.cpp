#include <bits/stdc++.h>

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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

#ifdef LOCAL
const int MAX = 7;
#else
const int MAX = 21;
#endif
int n;
int ma[MAX][MAX];
int mi[MAX][MAX];
int dp[MAX];
void pob(){
  int a;
  cin >> a;
  a *= 2;
  R(i,MAX){
    for(int j = i - 1; j>=0; j--){
      int X = (1 << (i - j - 1));
      int ak = (a >> (j + 1)) & (X - 1);
      if((a >> j) & 1) ak++;
      if((a >> i) & 1){
        if(ak != X){
          maxi(mi[j][i], ((~ak) &  (X - 1))+1);
        }
      }else{
        if(ak == X){
          mini(ma[j][i], -1ll);
        }else{
          mini(ma[j][i], (~ak) & (X - 1));
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  R(i,MAX)R(j,i){
    ma[j][i] = (1 << (i - j - 1)) - 1;
  }
  cin >> n;
  R(i,n){
    pob();
  }
  R(i,MAX)dp[i] = -1e9;
  dp[0] = 0;
  R(i,MAX){
    R(j,i){
      debug(j,ma[j][i],mi[j][i]);
      if(ma[j][i] >= mi[j][i]){
        
        maxi(dp[i], dp[j] + 1);
      }
    }
    debug(i,dp[i]);
  }
  int i = MAX-1;
  vector<int> res;
  while(i){
    R(j,i){
      if(ma[j][i] >= mi[j][i] && dp[i] == dp[j] + 1){
        int pom = mi[j][i];
        R(k,i-j-1){
          if((pom >> k) & 1){
            res.PB(-(1 << (j + k)));  
          }else{
            res.PB(1 << (j + k));
          }
        }
        i = j;
        break;
      }
    }
  }
  cout << SZ(res) << "\n";
  for(int el:res){
    cout << el << " ";
  }
  cout << "\n";
}