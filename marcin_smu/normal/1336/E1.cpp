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

const int P = 998244353;

void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}


int n,m;
vector<int> a,b;
int pol;
vector<int> lnz;
vector<int> res;

void bt0(int id,int mb){
  if(id == SZ(lnz)){
    res[__builtin_popcountll(mb)]++;
    return;
  }
  bt0(id+1,mb);
  bt0(id+1,mb ^ lnz[id]);
}

// void bt1(int id,int mb){
//   if(id == pol){
//     a[mb]++;
//   }
//   bt1(id+1,mb);
//   bt1(id+1,mb ^ lnz[id]);
// }
// 
// void bt2(int id,int mb){
//   if(id == SZ(lnz)){
//     b[mb & (1 << pol) + 1]
//   }
// }

const int C = 17;
int dp[60][1<<C];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
 cerr << fixed << setprecision(6);
  cin >> n >> m;
  res.resize(m+1);
  int mn = 1;
  int zle = (1ll << m) - 1;
  R(i,n){
    int pom;
    cin >> pom;
    for(int el:lnz){
      if((el&-el) & pom){
        pom ^= el;
      }
    }
    if(pom == 0){
      add(mn,mn);
    }else{
      for(int &el:lnz){
        if((pom&-pom) & el){
          el ^= pom;
        }
      }
      lnz.PB(pom);
      zle -= pom&-pom;
    }
  }
  
  if(__builtin_popcountll(zle) <= C){
    vector<int> kt;
    R(i,m)if((zle >> i)&1){
      kt.PB(i);
    }
    debug(kt);
    dp[0][0] = 1;
    for(int el:lnz){
      int pom = 0;
      R(i,SZ(kt))if((el >> kt[i]) & 1){
        pom += 1ll << i;
      }
      debug(pom);
      for(int i = SZ(lnz)-1;i>= 0;i--){
        R(mb,1ll << SZ(kt)){
          add(dp[i + 1][mb ^ pom], dp[i][mb]);
        }
      }
    }
    R(i,SZ(lnz) + 1)R(mb,1ll << SZ(kt)){
      debug(i,mb,dp[i][mb]);
      add(res[i + __builtin_popcountll(mb)], dp[i][mb]);
    }
  }else{
    bt0(0,0);
    
//     sort(ALL(lnz));
//     pol = (SZ(lnz) + 1) / 2;
//     bt1(0,0);
//     bt2(pol,0);
  }
  R(i,m +1){
    cout << res[i] * mn % P << " ";
  }
  cout << "\n";
}