#include <bits/stdc++.h>

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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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
string a,b,aa;

vector<int> res;
void rusz(int x){
  res.PB(n-x);
  a = a.substr(x) + a.substr(0,x);
  reverse(a.begin(),a.begin() + n - x);
  
//   debug(x);
//   aa = aa.substr(x) + aa.substr(0,x);
//   reverse(aa.begin(),aa.begin() + n - x);
//   debug(aa);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  cin >> a >> b;
  aa = a;
  R(i,n){
    int gd = -1;
    R(j,n){
      if(b[i] == a[j]){
        gd = j;
        a[j] = -1;
        break;
      }
    }
    if(gd == -1){
      cout << "-1\n";
      return 0;
    }
    debug(gd);
    rusz(gd+1);
    rusz(n-1);
    rusz(0);
  }
  cout << SZ(res) << "\n";
  for(int el:res){
    cout << el << " ";
  }
  cout << "\n";
}