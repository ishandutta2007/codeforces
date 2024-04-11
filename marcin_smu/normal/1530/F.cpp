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

const int P = 31607;
int mul(int a,int b){
  return a * b % P;
}
int n;
vector<vector<int>> t;
vector<vector<int>> used;
int res = 0;
vector<int> war;
int odw[P];
void bt(int kt,int ile, int p){
  if(kt == 0)debug(ile, p, war);
  if(kt == n){
//     int pp = p;
//     R(i,4){
//       cerr << pp << " ";
//       pp *= 2;
//       pp %= P;
//     }
//     cerr << "\n";
    R(i,n)p = mul(p, 1 - war[i]);
//     debug(res, p * 16 % P);
    if(ile & 1){
      res += p;
    }else{
      res -= p;
    }
//     debug(res);
//     debug(res * 16 % P);
    return;
  }
  bt(kt + 1, ile, p);
  R(i,n){
    used[kt][i]++;
    if(used[kt][i] == 1){
      p = mul(p, t[kt][i]);
      war[i] = mul(war[i], odw[t[kt][i]]);
    }
  }
  bt(kt + 1, ile + 1, p);
  R(i,n){
    if(used[kt][i] == 1){
      war[i] = mul(war[i], t[kt][i]);
    }
    used[kt][i]--;
  }
  
}

int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = mul(r, a);
    }
    w/=2;
    a = mul(a,a);
  }
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  R(i,P){
    odw[i] = pot(i, P - 2);
  }
  
  cin >> n;
  t.resize(n,vector<int>(n));
  used.resize(n,vector<int>(n));
  war.resize(n);
  R(i,n){
    R(j,n){
      cin >> t[i][j];
      t[i][j] = mul(t[i][j], odw[10000]);
    }
  }
  int p = 1;
  res = 1;
  R(a,2){
    R(b,2){
      R(i,n)war[i] = 1;
      R(i,n)R(j,n)if(!used[i][j]){
        war[j] = mul(war[j], t[i][j]);
      }
      
      bt(0, a + b, p);
      
      R(i,n){
        if(!used[i][i]){
          p = mul(p,t[i][i]);
          used[i][i] = 1;
        }
      }
    }
    p = 1;
    R(i,n){
      used[i][i] = 0;
    }
    R(i,n){
      p = mul(p, t[i][n - i - 1]);
      used[i][n - i - 1] = 1;
    }
  }
  res %= P;
  res += P;
  res %= P;
  cout << res << "\n";
}