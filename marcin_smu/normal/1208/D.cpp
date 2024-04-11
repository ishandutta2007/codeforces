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

const int MAX = 1 << 18;
int ad[MAX * 2 + 5],mi[MAX * 2 + 5],gd[MAX* 2 + 5];
const int inf = 1e12;
int n,nn;
int res[MAX];
void lacz(int v){
  if(mi[v * 2] < mi[v * 2 + 1]){
    mi[v] = ad[v] + mi[v * 2];
    gd[v] = gd[v * 2];
  }else{
    mi[v] = ad[v] + mi[v * 2 + 1];
    gd[v] = gd[v * 2 + 1];
  }
  debug(v,mi[v],gd[v]);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
#ifdef LOCAL
  vector<int> p(n);
  R(i,n)p[i] = i + 1;
  random_shuffle(ALL(p));
  debug(p);
#endif
  nn = 1;
  while(nn <= n) nn *= 2;
  R(i,nn){
    if(i < n){
#ifdef LOCAL
      int sum = 0;
      R(j,i){
        if(p[j] < p[i])
          sum += p[j];
      }
      mi[nn + 1] = sum;
      debug(sum);
#else
      cin >> mi[nn + i];
#endif
    }else
      mi[nn + i] = inf;
    gd[nn + i] = i;
  }
  for(int i = nn-1; i>0;i--)lacz(i);
  for(int i = 1;i <= n; i++){
    debug(gd[1]);
    int pom = gd[1];
    res[pom] = i;
    int po = pom + 1;
    int ko = nn;
    int val = -i;
    function<void(int,int,int)> add = [&](int v,int be,int en){
      if(be >= ko || po >= en)return;
      if(po <= be && en <= ko){
        debug("dodaje", v, val);
        ad[v] += val;
        mi[v] += val;
        return;
      }
      add(v * 2, be, (be + en)/2);
      add(v * 2 + 1, (be + en)/2, en);
      lacz(v);
    };
    add(1,0,nn);
    po = pom;
    ko = pom+1;
    val = inf;
    add(1,0,nn);    
  }
  R(i,n){
    cout << res[i] << " ";
  }
  cout << "\n";
}