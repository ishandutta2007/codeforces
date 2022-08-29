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

const int MAX = 2001;
PII pkt[MAX];
int cz[MAX];
string s;
int n;
int kt = 0;
int il_wek(int a, int b){
  return (pkt[a].FI - pkt[kt].FI) * (pkt[b].SE - pkt[kt].SE) -
         (pkt[b].FI - pkt[kt].FI) * (pkt[a].SE - pkt[kt].SE);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n)cin >> pkt[i].FI >> pkt[i].SE;
  cin >> s;
  vector<int> res;
  R(i,n){
    if(pkt[i] < pkt[kt]){
      kt = i;
    }
  }
  R(i,n-2){
    res.PB(kt);
    cz[kt] = 1;
    int nast = -1;
    R(j,n)if(!cz[j]){
      if(nast == -1 || ((il_wek(nast,j) < 0) ^ (s[i] == 'R')))
        nast = j;
    }
    kt = nast;
  }
  res.PB(kt);
  debug(kt);
  cz[kt] = 1;
  R(i,n)if(!cz[i]){
    res.PB(i);
  }
  for(int el:res){
    cout << el + 1 << " ";
  }
  cout << "\n";
}