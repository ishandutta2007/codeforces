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

map<int,int> mapka;
void factor(int a){
  if(a == 0)return;
  for(int i = 2; i * i <= a; i++){
    if(a % i == 0){
      mapka[i]++;
      while(a % i == 0)
        a /= i;
    }
  }
  if(a > 1){
    mapka[a]++;
  }
}

int res;
int n;
vector<int> t;
void spr(int x){
  int ak = 0;
  R(i,n){
    int pom = t[i] % x;
    int xx = x - pom;
    if(t[i] >= x)mini(xx, pom);
    ak += xx;
    if(ak > res)return;
  }
  res = ak;
}

int lh(string x){
  int h = 0;
  for(char el:x){
    h += el;
    h *= 111;
    h %= (int)(1e9 + 7);
  }
  return h;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  srand(lh("321746187247842616784271674217846216847qeyudgasujdgayegcfffffffffffffffffffffffffffffffffffffffffffffffffffffffhdsagfhasgdfjkasdhfkghasgdfkasgdgfsdafhgashdgfhasdgfhasgdhfkgafkhasgdfgkashdgfksadhgfhgaskjgfhasgdfkahgsdhkhdfahafk\n"));
  cin >> n;
  vector<int> p(n);
  t.resize(n);
  R(i,n){
    cin >> t[i];
    p[i] = i;
  }
  random_shuffle(ALL(p));
  R(i,min(SZ(p),50ll)){
    factor(t[p[i]]);
    factor(t[p[i]]+1);
    factor(t[p[i]]-1);
  }
  vector<PII> x;
  for(PII el:mapka){
    x.PB({el.SE,el.FI});
  }
  sort(ALL(x));
  reverse(ALL(x));
  debug(x);
  res = n;
  R(i,min(50ll, SZ(x))){
    spr(x[i].SE);
  }
  cout << res << "\n";
}