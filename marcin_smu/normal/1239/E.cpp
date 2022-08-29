#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

const int MAX = 60;
int n;
int t[MAX];
int dwu[MAX][MAX];
vector<vector<PII>> licz1(int po,int ko){
  int k = ko - po;
  vector<int> sum(1 << k);
  vector<int> il(1 << k);
  R(mb,1 << k){
    R(i,k)if((mb >> i)&1){
      sum[mb] = sum[mb - (1 << i)] + t[po + i];
      il[mb] = il[mb - (1 << i)] + 1;
      break;
    }
  }
  vector<vector<PII>> kt(k+1);
  R(i,k+1){
    kt[i].reserve(dwu[k][i]);
  }
  R(mb,1 << k){
    kt[il[mb]].PB({sum[mb],mb});
  }
  R(i,k){
    sort(ALL(kt[i]));
  }
  return kt;
}
PII szu(int a,vector<PII> &gd){
  int po = -1, ko = SZ(gd);
  while(po + 1 != ko){
    int m = (po + ko) / 2;
    if(gd[m].FI < a){
      po = m;
    }else{
      ko = m;
    }
  }
  if(ko == SZ(gd))return {1e9, -1};
  return gd[ko];
}
int naj = 1e9;
int naja = -1, najb = -1;
int summ = 0;
vector<vector<PII>> b;
void licz2(int po,int ko){
  int k = ko - po;
  vector<int> sum(1 << k);
  vector<int> il(1 << k);
  R(mb,1 << k){
    R(i,k)if((mb >> i)&1){
      sum[mb] = sum[mb - (1 << i)] + t[po + i];
      il[mb] = il[mb - (1 << i)] + 1;
      break;
    }
    PII xx = szu(summ - sum[mb], b[n-1-il[mb]]);
    if(xx.FI + sum[mb] < naj){
      naj = xx.FI + sum[mb];
      naja = mb;
      najb = xx.SE;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  R(i,MAX)R(j,i+1){
    if(j==0){
      dwu[i][j] = 1;
    }else{
      dwu[i][j] = dwu[i-1][j-1] + dwu[i-1][j];
    }
  }
  cin >> n;
  R(i,n * 2){
    cin >> t[i];
    summ += t[i];
    t[i] *= 2;
  }
  sort(t,t+2*n);
  summ -= t[0] / 2;
  summ -= t[1] / 2;

  b = licz1(n+1, 2*n);
  licz2(2,n+1);
  debug(naj,naja,najb);
  vector<int> resa,resb;
  resa.PB(t[0]);
  resb.PB(t[1]);
  R(i,n-1)if((naja >> i)&1){
    resa.PB(t[i+2]);
  }else{
    resb.PB(t[i+2]);
  }
  R(i,n-1)if((najb >> i)&1){
    resa.PB(t[i+n+1]);
  }else{
    resb.PB(t[i+n+1]);
  }
  sort(ALL(resa));
  sort(ALL(resb));
  reverse(ALL(resb));
  debug(naj,resa,resb,naja,najb);
  R(i,n){
    cout << resa[i] / 2 << " ";
  }
  cout << "\n";
  R(i,n){
    cout << resb[i]  / 2 << " ";
  }
  cout << "\n";
  
}