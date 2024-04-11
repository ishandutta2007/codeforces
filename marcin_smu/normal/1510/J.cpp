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

vector<int> dl1,dl2;
void spr(int x){
  vector<int> res;
  R(i,SZ(dl1)){
    int el = dl1[i];
    if(el >= x + 2){
      int pom = el - x;
      if(pom & 1){
        if(x == 2)return;
        res.PB(2);
        pom -= 3;
      }
      R(_,pom/2){
        res.PB(1);
      }
    }else if(el != x){
      return;
    }
    if(i < SZ(dl1) - 1)
      res.PB(dl2[i] + x - 1);
  }
  cout << SZ(res) << "\n";
  for(int el:res){
    cout << el << " ";
  }
  cout << "\n";
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  string s;
  cin >> s;
  int n = SZ(s);
  dl1.PB(1);
  R(i,n){
    if(s[i] == '#'){
      if(dl1.back() == 0){
        dl2.back()++;
      }else{
        dl1.PB(0);
        dl2.PB(1);
      }
    }else{
      dl1.back()++;
    }
  }
  dl1.back()++;
  debug(dl1,dl2);
  if(dl2.empty()){
    cout << "0\n";
    return 0;
  }
  int mi = 1e9;
  int ma = 0;
  for(int el:dl1){
    mini(mi, el);
    maxi(ma, el);
  }
  if(ma == mi){
    cout << SZ(dl2) << "\n";
    for(int el:dl2){
      cout << el + mi - 1 << " ";
    }
    cout << "\n";
    return 0;
  }
  spr(2);
  spr(3);
  spr(4);
  cout << "-1\n";
}