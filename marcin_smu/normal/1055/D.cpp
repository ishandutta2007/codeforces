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
int n;
vector<string> x,y;
string pre,srod,suf;
string srodna;
string p,q;
vector<int> kmp;
void prep(){
  kmp.resize(SZ(p));
  int t = 0;
  for(int i = 1; i < SZ(p); i++){
    while(t && p[i] != p[t])t = kmp[t-1];
    kmp[i] = t += p[i] == p[t];
  }
  debug(kmp);
}
void zamien(string& s){
  int t = 0;
  for(int i = 0; i < SZ(s); i++){
    while(t && p[t] != s[i]) t = kmp[t-1];
    t += p[t] == s[i];
    if(t == SZ(p)){
      R(j,SZ(p)){
        s[i - j] = q[SZ(q) - j - 1];
      }
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  x.resize(n);
  y.resize(n);
  R(i,n) cin >> x[i];
  R(i,n) cin >> y[i];
  int ile = 0;
  R(i,n){
    if(x[i] != y[i]){
      ile++;
      if(ile == 1){
        int pocz = -1,kon = 0;
        R(j,SZ(x[i])){
          if(x[i][j] != y[i][j]){
            if(pocz == -1)pocz = j;
            kon = j;
          }
        }
        for(int j = pocz; j <= kon; j++){
          srod += x[i][j];
          srodna += y[i][j];
        }
        R(j,pocz){
          pre += x[i][pocz - j - 1];
        }
        R(j,SZ(x[i]) - pocz - SZ(srod)){
          suf += x[i][pocz + SZ(srod) + j];
        }
        debug(pre,suf,srod);
      }else{
        int pocz = -1;
        R(j,SZ(x[i])){
          if(x[i][j] != y[i][j]){
            pocz = j;
            break;
          }
        }
        if(pocz < SZ(pre)){
          pre.resize(pocz);
        }
        R(j,pocz){
          if(pre[j] != x[i][pocz - j - 1]){
            pre.resize(j);
            break;
          }
        }
        if(SZ(x[i]) - pocz - SZ(srod) < SZ(suf))
          suf.resize(SZ(x[i]) - pocz - SZ(srod));
        
        R(j,SZ(x[i]) - pocz - SZ(srod)){
          if(suf[j] != x[i][pocz + SZ(srod) + j]){
            suf.resize(j);
            break;
          }
        }
        /*
        while(SZ(pre) && (pocz < SZ(pre) || x[i][pocz - SZ(pre)] != pre.back() )){
          pre.pop_back();
        }
        while(SZ(suf) && (
          (SZ(x[i]) - pocz - SZ(srod)) < SZ(suf) ||
          x[i][pocz + SZ(srod) + SZ(suf) - 1] != suf.back()
        )){
          suf.pop_back();
        }*/
      }
    }
  }
  reverse(ALL(pre));
  p = pre + srod + suf;
  q = pre + srodna + suf;
  debug(p,q);
  prep();
  R(i,n){
    zamien(x[i]);
    if(x[i] != y[i]){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n" << p << "\n" << q << "\n";
}