#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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

const int MAX = 3e5 + 100;
int n,a[MAX],b[MAX];
vector<int> m;
int base = 1e9;
const int P = 1e9 + 7;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a-=P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a += P;
}

void norm(){
  while(!m.empty() && m.back() == 0){
    m.pop_back();
  }
}
vector<int> res;
int dodaj(int a){
  vector<int> res2(SZ(res) + a);
  R(i,SZ(res2)){
    if(i)res2[i] = res2[i-1];
    if(i < SZ(res)) add(res2[i],res[i]);
    if(i - a - 1 >= 0) sub(res2[i], res[i-a-1]);
  }
  debug(a,res,res2);
  swap(res,res2);
}

void dziel(int a){
  int reszt = 0;
  for(int i = SZ(m)-1; i >= 0; i--){
    int pom = (m[i] + reszt * base);
    m[i] = pom / a;
    reszt = pom % a;
  }
  norm();
  vector<int> res2;
  while(reszt < SZ(res)){
    res2.PB(res[reszt]);
    reszt += a;
  }
  swap(res2,res);
  if(SZ(res) == 0){
    cout << "0\n";
    exit(0);
  }
  if(SZ(m) == 0){
    cout << res[0] << "\n";
    exit(0);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n-1){
    cin >> a[i];
  }
  a[n-1] = 0;
  R(i,n){
    cin >> b[i];
  }
 
  string z;
  cin >> z;
  while(SZ(z) % 9 != 0)z = '0' + z;
  int ak = 0;
  R(i,SZ(z)){
    ak *= 10;
    ak += z[i] - '0';
    if(i % 9 == 8){
      m.PB(ak);
      ak = 0;
    }
  }
  reverse(ALL(m));
  norm();
  res.PB(1);
  if(SZ(m) == 0){
    cout << "1\n";
    return 0;
  }
  
  R(i,n){
    dodaj(b[i]);
    if(i != n-1 && a[i] != 1){
      dziel(a[i]);
    }
  }
  
  if(SZ(m) > 1 || m[0] > SZ(res)){
    cout << "0\n";
  }else{
    cout << res[m[0]] << "\n";
  }
  
}