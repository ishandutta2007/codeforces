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


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N;
  cin >> N;

  string s, t;
  cin >> s >> t;

  vector<int> Ops;

  auto doOp = [&](int x) {
    s = s.substr(N - x) + s.substr(0, N - x);
    reverse(s.begin(), s.begin() + x);
    Ops.PB(x);
  };

  int NumOK = 0;
  while (s != t) {
    char What = t[NumOK];
    int Loc = -1;
    for (int i = 0; i < N - NumOK; ++i)
      if (s[i] == What) {
        Loc = i;
        break;
      }

    if (Loc == -1) {
      cout << "-1\n";
      return 0;
    }

    int a = Loc,
        b = N - Loc - NumOK - 1,
        u = NumOK;

    doOp(b + u);
    doOp(1);
    doOp(a + b + u);

    ++NumOK;
    debug(s, t, NumOK);
  }

  cout << SZ(Ops) << "\n";
  for (int v : Ops) { cout << v << " "; }
  cout << "\n";
}