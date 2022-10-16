#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

const int MaxN = 1e6 + 100;

int N;
LL K;
LL weight[MaxN];

struct Subcase {
  int l1, r1, l2, r2;
  friend ostream &operator<<(ostream &os, Subcase &s) {
    os << "(" << s.l1 << " " << s.r1 << " " << s.l2 << " " << s.r2 << ")";
    return os;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> K;
  const LL first_K = K;
  for (int i = 1; i < N; ++i) {
    int p;
    LL w;
    cin >> p >> w;
    --p;
    weight[i] = weight[p] ^ w;
  }

  sort(weight, weight + N);

#ifdef LOCAL
  cerr << "dbg: ";
  for (int i = 0; i < N; ++i)
    cerr << weight[i] << " ";
  cerr << "\n";
#endif

  LL answer = 0;
  vector<Subcase> cases;
  cases.push_back(Subcase{0, N, 0, N});

  auto AddCase = [&](int l1, int r1, int l2, int r2) {
    if (r1 > l1 && r2 > l2)
      cases.push_back(Subcase{l1, r1, l2, r2});
  };

  for (int bit = 61; bit >= 0; --bit) {
    const LL coef = 1LL << bit;

    vector<Subcase> old_cases;
    swap(cases, old_cases);

    const int S = SZ(old_cases);
    vector<int> m1(S), m2(S);

    LL num_same = 0;

    for (int i = 0; i < S; ++i) {
      const auto &c = old_cases[i];
      m1[i] = c.l1;
      while (m1[i] < c.r1 && !(weight[m1[i]] & coef))
        ++m1[i];

      m2[i] = c.l2;
      while (m2[i] < c.r2 && !(weight[m2[i]] & coef))
        ++m2[i];

      num_same += (LL)(m1[i] - c.l1) * (m2[i] - c.l2);
      num_same += (LL)(c.r1 - m1[i]) * (c.r2 - m2[i]);
    }

    debug(bit, old_cases, K, num_same);

    bool add_bit = num_same < K;

    if (!add_bit) {
      for (int i = 0; i < S; ++i) {
        const auto &c = old_cases[i];
        AddCase(c.l1, m1[i], c.l2, m2[i]);
        AddCase(m1[i], c.r1, m2[i], c.r2);
      }
    } else {
      for (int i = 0; i < S; ++i) {
        const auto &c = old_cases[i];
        AddCase(c.l1, m1[i], m2[i], c.r2);
        AddCase(m1[i], c.r1, c.l2, m2[i]);
      }
      answer += coef;
      K -= num_same;
    }
  }

#ifdef LOCAL
  vector<LL> all_pairs;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      all_pairs.push_back(weight[i] ^ weight[j]);
  sort(ALL(all_pairs));
  assert(answer == all_pairs[first_K - 1]);
#endif

  cout << answer << "\n";
}