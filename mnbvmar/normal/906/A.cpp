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

const int MaxS = 30;

bool CanBe[MaxS];
bool Now[MaxS];
int N;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  const int A = 26;
  fill(CanBe, CanBe + A, true);

  int Result = 0;

  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    string t, c;
    cin >> t >> c;
    bool NeedShock = count(CanBe, CanBe + A, true) == 1;
    bool Shock = (t != ".");

    if (t == "!" || t == ".") {
      fill(Now, Now + A, false);
      for (char ch : c) { Now[ch - 'a'] = true; }
      if (t == "!") {
        for (int j = 0; j < A; ++j)
          CanBe[j] &= Now[j];
      } else {
        for (int j = 0; j < A; ++j)
          CanBe[j] &= !Now[j];
      }
    }

    if (t == "?")
      CanBe[c[0] - 'a'] = false;

    debug(count(CanBe, CanBe + A, true));
    Result += Shock && NeedShock;
  }

  cout << Result << "\n";
}