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

const int MaxN = 1e5 + 6;

int N;
int perm[MaxN];
bool isVal[MaxN];
vector<int> selfs;
int selfId[MaxN];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> perm[i];
    isVal[perm[i]] = true;
    if (perm[i] == i) {
      selfs.push_back(i);
      selfId[i] = SZ(selfs);
    }
  }
  
  for (int v = 1; v <= N; v++) {
    if (isVal[v] && perm[v] != v) {
      cout << "-1\n";
      return 0;
    }
  }
  
  cout << SZ(selfs) << "\n";
  for (int i = 1; i <= N; i++) {
    int who = perm[i];
    cout << selfId[who] << " ";
  }
  cout << "\n";
  for (int i = 1; i <= SZ(selfs); i++) {
    cout << selfs[i - 1] << " ";
  }
  cout << "\n";
}