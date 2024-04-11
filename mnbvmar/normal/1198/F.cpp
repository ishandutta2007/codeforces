#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
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
template<class A, class B, class C> ostream &operator<<(ostream &os, tuple<A,B,C> P) {
  return os << "(" << get<0>(P) << "," << get<1>(P) << "," << get<2>(P) << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

vi Factors(int x) {
  vi ans;
  for (int p = 2; p * p <= x; ++p) {
    if (x % p == 0) {
      ans.PB(p);
      while (x % p == 0) { x /= p; }
    }
  }
  if (x > 1) { ans.PB(x); }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n;
  cin >> n;
  vi numbers(n);
  for (int &x : numbers) { cin >> x; }

  auto fact1 = Factors(numbers[0]);

  const int kMaxSz = 10;

  for (int otherid = 1; otherid < n && otherid < kMaxSz; ++otherid) {
    auto fact_other = Factors(numbers[otherid]);

    set<int> all_facts(ALL(fact1));
    for (int x : fact_other) { all_facts.insert(x); }

    vi all_facts_vec(ALL(all_facts));
    int S = SZ(all_facts_vec);
    vi anticounts(S);

    for (int i = 1; i < n; ++i) {
      if (i == otherid) { continue; }
      for (int j = 0; j < S; ++j) {
        if (numbers[i] % all_facts_vec[j] != 0) {
          ++anticounts[j];
        }
      }
    }

    set<int> important_facts;
    set<int> unimportant_facts;

    for (int i = 0; i < S; ++i) {
      if (anticounts[i] <= kMaxSz) {
        important_facts.insert(all_facts_vec[i]);
      } else {
        unimportant_facts.insert(all_facts_vec[i]);
      }
    }

    vi fact_list;
    for (int f : fact1) {
      if (important_facts.count(f)) { fact_list.PB(f); }
    }
    const int end1 = SZ(fact_list);
    for (int f : fact_other) {
      if (important_facts.count(f)) { fact_list.PB(f); }
    }
    S = SZ(fact_list);

    const unsigned msk1 = (1U << end1) - 1;
    const unsigned msk_other = (1U << S) - (1U << end1);
    vector<tuple<int, unsigned, unsigned>> options;

    for (int i = 1; i < n; ++i) {
      unsigned msk = 0;
      if (i == otherid) { continue; }
      for (int j = 0; j < S; ++j) {
        if (numbers[i] % fact_list[j] != 0) {
          msk |= (1U << j);
        }
      }
      if (!msk) { continue; }
      options.emplace_back(i, msk & msk1, msk & msk_other);
    }

    debug(options);

    vector<bool> dp(1 << S);
    vi used_idx(1 << S);
    vi used_side(1 << S);
    vector<unsigned> prv(1 << S);
    dp[0] = true;

    for (auto &&[idx, a, b] : options) {
      for (int i = (1 << S) - 1; i >= 0; --i) {
        if (!dp[i]) { continue; }
        if (!dp[i | a]) {
          dp[i | a] = true;
          used_idx[i | a] = idx;
          used_side[i | a] = 0;
          prv[i | a] = i;
        }
        if (!dp[i | b]) {
          dp[i | b] = true;
          used_idx[i | b] = idx;
          used_side[i | b] = 1;
          prv[i | b] = i;
        }
      }
    }

    if (!dp.back()) { continue; }

    vector<int> used[2];
    used[0].PB(0); used[1].PB(otherid);

    int curgcd[2] = {0, 0};
    unsigned curmask = (1 << S) - 1;
    vector<int> ans(n, -1);
    ans[0] = 0; ans[otherid] = 1;

    while (curmask) {
      debug(curmask, used_side[curmask], used_idx[curmask]);
      used[used_side[curmask]].PB(used_idx[curmask]);
      curmask = prv[curmask];
      assert(dp[curmask]);
    }

    for (int i : {0, 1}) {
      for (int idx : used[i]) {
        ans[idx] = i;
        curgcd[i] = gcd(curgcd[i], numbers[idx]);
      }
    }

    debug(ans, curgcd[0], curgcd[1]);

    for (int i : {0, 1}) {
      while (curgcd[i] > 1) {
        const int p = Factors(curgcd[i])[0];
        bool found = false;
        for (int j = 0; j < n; ++j) {
          if (ans[j] == -1 && numbers[j] % p != 0) {
            found = true;
            used[i].PB(j);
            ans[j] = i;
            curgcd[i] = gcd(curgcd[i], numbers[j]);
            break;
          }
        }
        assert(found);
      }
    }

    cout << "YES\n";
    for (int x : ans) {
      cout << max(x + 1, 1) << " ";
    }
    cout << "\n";
    return 0;
  }

  cout << "NO\n";
}