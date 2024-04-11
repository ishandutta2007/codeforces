#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

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

const int MaxN = 1600;

int N, S, M, K;

vector<PII> segments;
int values[MaxN];

bool CanGetLower(int bound) {
  vector<int> ends(N + 1, -1);
  for (auto &&[l, r] : segments) {
    assert(ends[r] == -1);
    ends[r] = l;
  }

  for (int i = N - 1; i > 0; --i)
    if (ends[i] == -1 && ends[i + 1] < i)
      ends[i] = ends[i + 1];

  if (bound == 11)
    debug(ends);


  vector<int> pref_zeros(N + 1);
  for (int i = 0; i < N; ++i)
    pref_zeros[i + 1] = pref_zeros[i] + (values[i] < bound);

  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

  for (int r = 1; r <= N; ++r) {
    dp[r] = dp[r - 1];
    if (ends[r] == -1) { continue; }

    const int l = ends[r];
    const int num_zeros = pref_zeros[r] - pref_zeros[l];

    for (int s = 0; s < M; ++s)
      maxi(dp[r][s + 1], dp[l][s] + num_zeros);
  }

  return *max_element(ALL(dp[N])) >= K;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> S >> M >> K;

  for (int i = 0; i < N; ++i)
    cin >> values[i];

  segments.resize(S);
  for (auto &[l, r] : segments) {
    cin >> l >> r;
    --l;
  }

  {
    vector<PII> good_segments;
    vector<bool> found_bad(S);

    for (int i = 0; i < S; ++i) {
      bool is_bad = false;
      for (int j = 0; j < S; ++j) {
        if (i == j) { continue; }
        if (found_bad[j]) { continue; }
        if (segments[j].st <= segments[i].st && segments[i].nd <= segments[j].nd) {
          is_bad = true;
          found_bad[i] = true;
          break;
        }
      }
      if (!is_bad)
        good_segments.push_back(segments[i]);
    }

    segments = good_segments;
    sort(ALL(segments));
    debug(segments);
    S = SZ(segments);
    mini(M, S);
  }

  const int Infty = 1e9 + 100;
  int L = 0, R = Infty;
  while (R - L > 1) {
    const int mid = (L + R) / 2;
    if (CanGetLower(mid))
      R = mid;
    else
      L = mid;
  }

  if (L > 1e9 + 50)
    L = -1;

  cout << L << "\n";
}