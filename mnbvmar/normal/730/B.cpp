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
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

bool ask(int a,int b){
  cout << "? " << a + 1 << " " <<  b + 1 << endl;
  char z;
  cin >> z;
  return z == '<';
}

void test(){
  int n;
  cin >> n;
  vector<int> a,b;
  for(int i = 0; i+1 < n;i+=2){
    if(ask(i,i+1)){
      a.PB(i);
      b.PB(i+1);
    }else{
      a.PB(i+1);
      b.PB(i);
    }
  }
  if(n&1){
    a.PB(n-1);
    b.PB(n-1);
  }
  int mi = a.back();
  a.pop_back();
  for(int ak:a){
    if(ask(ak, mi))
      mi = ak;
  }
  
  int ma = b.back();
  b.pop_back();
  for(int ak:b){
    if(ask(ma,ak))
      ma = ak;
  }
  
  cout << "! " << mi + 1 << " " << ma + 1 << endl;
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--)test();
}