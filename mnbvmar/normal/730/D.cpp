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

#define MAX 201001

int n,r;
int l[MAX],t[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> r;
  int wyn = 0;
  vector<int> res;
  int mam = 0;
  R(i,n)cin >> l[i];
  R(i,n)cin >> t[i];
  int time = 0;
  R(i,n){
    if(l[i] > t[i]){
      cout << "-1\n";
      return 0;
    }
    int pom = min(mam,l[i]);
    l[i] -= pom;
    t[i] -= pom;
    mam -= pom;
    time += pom;
    pom = min(l[i], t[i]-l[i]);
    l[i] -= pom;
    time += 2*pom;
    while(l[i] != 0 && SZ(res) < 100000){
      res.PB(time);wyn ++;
      mam = r;
      pom = min(l[i],mam);
      l[i] -= pom;
      mam -= pom;
      time += pom;
    }
    
    if(l[i]){
      pom = (l[i] + r - 1) / r;
      wyn += pom;
      mam = (((r - l[i]) % r) + r) % r;
    }
    
    
  }
  
  cout << wyn << "\n";
  if(wyn <= 100000){
    for(int ak:res){
      cout << ak << " ";
    }
    cout << "\n";
  }
}