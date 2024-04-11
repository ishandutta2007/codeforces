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

const int MAX = 300100;
const int MAXX = 1 << 19;
int n;
int nn;
int p[MAX],q[MAX],gd[MAX];
int ma[MAXX * 2];
int mi[MAXX * 2];
int lazy[MAXX * 2];
int ma_pref(int ko){
  int res = -1;
  function<void(int,int,int)> rec = [&](int nr,int be,int en){
    if(be >= ko)return;
    if(en <= ko){
      if(ma[nr] > res){
        res = ma[nr];
      }
      return;
    }
    rec(nr * 2, be, (be + en)/2);
    rec(nr * 2 + 1, (be + en)/2, en);
  };
  rec(1,0,nn);
  return res;
}
void us_pref(int x){
  int ak = gd[x] + nn;
  ma[ak] = -1;
  do{
    ak/=2;
    ma[ak] = max(ma[ak * 2], ma[ak * 2 + 1]);
  }while(ak > 1);
}
int zero_suf(int po){
  function<int(int,int,int)> rec = [&](int nr,int be,int en) -> int{
    if(en <= po)return -1;
    if(po <= be && mi[nr] != 0)return -1;
    if(be + 1 == en) return be;
    
    if(lazy[nr]){
      lazy[nr * 2] += lazy[nr];
      mi[nr * 2] += lazy[nr];
      lazy[nr * 2 + 1] += lazy[nr];
      mi[nr * 2 + 1] += lazy[nr];
      lazy[nr] = 0;
    }
    
    int pom = rec(nr * 2, be, (be + en)/2);
    if(pom != -1)return pom;
    return rec(nr * 2 + 1, (be + en)/2, en);
  };
  return rec(1,0,nn);
}
void add(int po,int ko,int val){
  function<void(int,int,int)> rec = [&](int nr,int be,int en){
    if(en <= po || ko <= be)return;
    if(po <= be && en <= ko){
      mi[nr] += val;
      lazy[nr] += val;
      return;
    }
    if(lazy[nr]){
      lazy[nr * 2] += lazy[nr];
      mi[nr * 2] += lazy[nr];
      lazy[nr * 2 + 1] += lazy[nr];
      mi[nr * 2 + 1] += lazy[nr];
      lazy[nr] = 0;
    }
    rec(nr * 2, be, (be + en)/2);
    rec(nr * 2 + 1, (be + en)/2, en);
    mi[nr] = min(mi[nr * 2], mi[nr*2 + 1]);
  };
  rec(1,0,nn);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  nn = 1;while(nn <= n)nn *= 2;
  R(i,n){
    cin >> p[i];
    gd[p[i]] = i;
    ma[i + nn] = p[i];
  }
  for(int i = nn - 1; i; i--){
    ma[i] = max(ma[i * 2], ma[i * 2 + 1]);
  }
  R(i,n){
    cout << ma[1] << "\n";
    int pom;
    cin >> pom;
    int koniec = zero_suf(pom);
    int val = ma_pref(koniec);
    debug(pom,koniec,val);
    us_pref(val);
    debug("?",gd[val],pom);
    if(gd[val] < pom){
      add(gd[val] + 1, pom, 1);
    }else{
      add(pom, gd[val] + 1, -1);
    }
    debug("??");
  }
}