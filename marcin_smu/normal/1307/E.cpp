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

const int P = 1e9 + 7;
const int MAX = 5011;
int t[MAX];
int n,m;
vector<int> kr[MAX];
int res[MAX],jedz[MAX],spo[MAX];
void mul(int &a,int b){
  a = a * b % P;
}
const int inf = 1e9;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,n){
    cin >> t[i];
    t[i]--;
    jedz[t[i]]++;
  }
  R(i,n+1)spo[i] = 1;
  R(i,m){
    int co, il;
    cin >> co >> il;
    co--;
    if(il <= jedz[co])
      kr[co].PB(il);
  }
  t[n] = -1;
  R(i,n){
    sort(ALL(kr[i]));
    int przed = 0;
    int po = jedz[i];
    int iprzed = 0;
    int ipo = SZ(kr[i]);
    debug("-----------",i);
    R(j,n+1){
      debug(j,przed, po, iprzed,ipo);
      int czyza = ipo > 0 && kr[i][ipo - 1] == po;
      if(iprzed > 0 && ipo > 0 && iprzed + ipo > 2){
        if(t[j] != i){
          res[j] += 2;
          mul(spo[j], iprzed * ipo - min(iprzed, ipo));
        }else if(czyza){
          res[j] += 2;
          mul(spo[j], iprzed - (ipo <= iprzed));
        }else{
          res[j] -= inf;
        }
      }else if(iprzed > 0 || ipo > 0){
        if(t[j] != i){
          res[j] ++;
          mul(spo[j], iprzed + ipo);
        }else if(czyza){
          res[j] ++;
        }else{
          res[j] -= inf;
        }
      }else if(t[j] == i){
        res[j] -= inf;
      }
      if(j == n)break;
      if(t[j] == i){
        przed ++;
        if(iprzed < SZ(kr[i]) && kr[i][iprzed] == przed)iprzed++;
        if(czyza)ipo--;
        po--;
      }
    }
  }
  int wyn = 0;
  R(i,n+1){
    maxi(wyn, res[i]);
  }
  int wyn2 = 0;
  R(i,n+1){
    if(wyn == res[i]){
      wyn2 += spo[i];
    }
  }
  cout << wyn << " " << wyn2 % P << "\n";
}