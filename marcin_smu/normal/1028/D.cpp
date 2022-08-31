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

const int MAX = 500000;
const int P = 1e9 + 7;
const int inf = 1e12;
int n;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a-=P;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  set<int> all;
  set<int> male,duze;
  male.insert(-inf);
  duze.insert(inf);
  int res = 1;
  R(i,n){
    string z;
    int t;
    cin >> z >> t;
    if(z[1] == 'D'){
      if(*duze.begin() < t){
        duze.insert(t);
      }else if(*male.rbegin() > t){
        male.insert(t);
      }else
        all.insert(t);
    }else{
      if(*duze.begin() < t || *male.rbegin() > t){
        cout << "0\n";
        return 0;
      }
      if(all.find(t) != all.end()){
        add(res,res);
        all.erase(t);
      }else{
        male.erase(t);
        duze.erase(t);
      }
      for(int el:all){
        if(el < t){
          male.insert(el);
        }else{
          duze.insert(el);
        }
      }
      all.clear();
    }
  }
  cout << res * (SZ(all) + 1) % P << "\n";
}