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

const int MAX = 50;
string z[MAX];
const int P = 1e9 + 33;
int t[MAX];
int ss[MAX],iss = 0;
int n;
int dfs(int i){
  if(ss[i] != -1)return 0;
  int res = 1;
  ss[i] = iss;
  R(j,n){
    if(z[i][j] == 'A'){
      res += dfs(j);
    }
  }
  return res;
}
const int MAX2 = (1 << 23) + 5;
int nz[MAX2],ak[MAX2];
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a += P;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  int res = n;
  R(i,n){
    cin >> z[i];
    ss[i] = -1;
  }
  int out = 0;
  R(i,n){
    if(ss[i] == -1){
      int pom = dfs(i);
      debug(pom);
      if(pom == 1){
        ss[i] = -1;
        out++;
      }else{
        iss++;
      }
    }
  }
  debug(iss);
  if(iss == 0){
    cout << n - 1 << "\n";
    return 0;
  }
  R(i,n)R(j,n)if(z[i][j] == 'X' && ss[i] != -1 && ss[j] != -1){
    if(ss[i] == ss[j]){
      cout << "-1\n";
      return 0;
    }
    t[ss[i]] |= 1 << ss[j];
  }
  nz[0] = 1;
  n = iss;
  R(i, 1 << n){
    R(j, n)if((i >> j) & 1){
      if(nz[i - (1 << j)] && (t[j] & i) == 0){
        nz[i] = 1;
      }
      break;
    }
  }
  R(i,n)R(mb, 1 << n)if((mb >> i) & 1){
    nz[mb] += nz[mb - (1 << i)];
  }
  R(mb, 1 << n)ak[mb] = nz[mb];
  while(1){
    int pom = 0;
    R(i,1 << n){
      if(__builtin_popcount(i) & 1){
        add(pom,ak[i]); 
      }else{
        sub(pom,ak[i]);
      }
    }
    if(pom != 0){
      cout << res << "\n";
      return 0;
    }
    R(i,1 << n){
      ak[i] = ak[i] * nz[i] % P;
    }
    res++;
  }
}