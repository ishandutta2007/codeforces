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

const int nn = 1 << 20;
int n,m;
int sum[nn * 2 + 10];
int ma[nn * 2 + 10];

void lacz(int v){
  sum[v] = sum[v * 2] + sum[v*2+1];
  ma[v] = max(ma[v * 2] + sum[v*2+1],ma[v*2+1]);
}

void add(int v,int x){
  v += nn;
  sum[v] += x;
  if(sum[v] > 0){
    ma[v] = sum[v];
  }else{
    ma[v] = 0;
  }
  do{
    v/=2;
    lacz(v);
  }while(v!=1);
}

int szu(int lim){
  int x = 1;
  while(x < nn){
    x *= 2;
    if(ma[x + 1] > lim){
      x++;
    }else{
      lim -= sum[x + 1];
    }
  }
  return x - nn;
}

int a[nn],b[nn];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,n){
    cin >> a[i];
    add(a[i], 1);
  }
  R(i,m){
    cin >> b[i];
    add(b[i], -1);
  }
  int q;
  cin >> q;
  R(i,q){
    int z,x,val;
    cin >> z >> x >> val;x--;
    if(z == 1){
      add(a[x], -1);
      a[x] = val;
      add(a[x], 1);
    }else{
      add(b[x], 1);
      b[x] = val;
      add(b[x], -1);
    }
    if(ma[1] > 0){
      cout << szu(0) << "\n";
    }else{
      cout << "-1\n";
    }
  }
}