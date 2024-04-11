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

int N, M;
vector<string> files;

void fail() {
  cout << "No\n";
  exit(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    files.PB(s);
  }
  
  int length = -1;
  string curPattern;
  
  for (int i = 0; i < M; i++) {
    int v;
    cin >> v;
    v--;
    if (length == -1) {
      curPattern = files[v];
      length = SZ(files[v]);
    } else {
      if (SZ(files[v]) != length) {
        fail();
      }
      for (int j = 0; j < length; j++) {
        if (curPattern[j] != files[v][j]) { curPattern[j] = '?'; }
      }
    }
  }
  
  debug(curPattern);
  
  int numMatch = 0;
  for (int i = 0; i < N; i++) {
    if (SZ(files[i]) != length) { continue; }
    
    bool fail = false;
    for (int j = 0; j < length; j++) {
      if (curPattern[j] != '?' && curPattern[j] != files[i][j]) { fail = true; }
    }
    
    if (!fail) { debug(i); numMatch++; }
  }
  
  if (numMatch == M) {
    cout << "Yes\n";
    cout << curPattern << "\n";
  } else {
    fail();
  }
}