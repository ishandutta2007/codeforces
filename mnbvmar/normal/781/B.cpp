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


const int MaxN = 1024;

int N;
string nameA[MaxN], nameB[MaxN];
map<string, vector<int>> typeA, typeB;
set<string> used;
string results[MaxN];
bool isChanged[MaxN];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> nameA[i] >> nameB[i];
    typeA[nameA[i].substr(0, 3)].push_back(i);
    results[i] = nameA[i].substr(0, 3);
  }

  for (auto &P : typeA) {
    if (SZ(P.second) > 1) {
      for (int v : P.second) {
        results[v] = nameA[v].substr(0, 2) + nameB[v][0];
        used.insert(results[v]);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (isChanged[j]) { continue; }
      if (used.count(nameA[j].substr(0, 3))) {
        isChanged[j] = true;
        results[j] = nameA[j].substr(0, 2) + nameB[j][0];
        used.insert(results[j]);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    used.insert(results[i]);
  }

  if (SZ(used) < N) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < N; i++) {
      cout << results[i] << "\n";
    }
  }
}