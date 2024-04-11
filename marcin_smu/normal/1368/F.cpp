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

void koncz(){
  cout << "0" << endl;
  exit(0);
}

int n;
vector<int> ak;
vector<int> graj(vector<int> x){
  cout << SZ(x) << " ";
  for(int el:x){
    cout << el + 1 << " ";
    ak[el] = 1;
  }
  cout << endl;
  int y;
  cin >> y;
  y--;
  vector<int> res;
  R(i,SZ(x)){
    if(ak[y] == 1){
      res.PB(y);
      ak[y] = 0;
    }
    y++;
    if(y == n) y = 0;
  }
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  if(n <= 3){
    koncz();
  }
  int naj = 0;
  int siz = 1;
  for(int i = 1; i < n; i++){
    int res = n - (n + i - 1) / i - i + 1;
    if(res > naj){
      naj = res;
      siz = i;
    }
  }
  debug(siz,naj);
  ak.resize(n);
  vector<int> todo;
  R(i,n-1){
    if(i % siz != siz - 1){
      todo.PB(i);
    }
  }
  debug(todo);
  vector<int> ost;
  while(SZ(todo)){
    vector<int> x = ost;
    while(SZ(x) != siz && SZ(todo)){
      x.PB(todo.back());
      todo.pop_back();
    }
    ost = graj(x);
  }
  koncz();
}