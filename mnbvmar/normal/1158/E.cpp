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

int N;

map<vector<int>, vector<bool>> memo;

vector<bool> Ask(const vector<int> &dists) {
  if (count(ALL(dists), 0) == N) { return vector<bool>(N); }
  auto iter = memo.find(dists);
  if (iter != memo.end()) { return iter->nd; }

  cout << "?";
  for (int d : dists) { cout << " " << min(d, N - 1); }
  cout << endl;
  string ans;
  cin >> ans;

  vector<bool> ret(N);
  for (int i = 0; i < N; ++i) {
    ret[i] = ans[i] == '1';
  }
  return memo[dists] = ret;
}

void Answer(const vector<PII> &adj) {
  cout << "!" << endl;
  for (auto [u, v] : adj) {
    cout << u + 1 << " " << v + 1 << endl;
  }
}

int GetMaxH() {
  vector<int> query(N);
  int minh = 0, maxh = N;
  while (maxh - minh > 1) {
    const int mid = (minh + maxh) / 2;
    query[0] = mid;
    auto ans = Ask(query);
    if (count(ALL(ans), true) == N - 1) {
      maxh = mid;
    } else {
      minh = mid;
    }
  }
  return maxh;
}

int32_t main() {
  cin >> N;

  const int maxh = GetMaxH();
  debug(maxh);

  VI heights(N);

  VI cur_ask{0};

  int cur_span = 1;
  while (cur_span * 2 <= maxh) { cur_span *= 2; }

  while (cur_span >= 1) {
    VI next_ask;
    debug(cur_span, cur_ask);
    for (bool odd : {false, true}) {
      VI query(N);
      VI which;
      for (int x : cur_ask) {
        if (!!(heights[x] & (cur_span * 2)) == odd) {
          query[x] = cur_span;
          which.PB(x);
        }
      }

      auto fst_ans = Ask(query);
      for (int x : which) {
        query[x] = cur_span - 1;
      }
      auto snd_ans = Ask(query);
      for (int x : which) { fst_ans[x] = snd_ans[x] = true; }

      for (int i = 0; i < N; ++i) {
        if (!!(heights[i] & (cur_span * 2)) == odd) {
          if (!snd_ans[i]) { heights[i] += cur_span; }
          if (fst_ans[i] && !snd_ans[i]) {
            next_ask.PB(i);
          }
        }
      }
    }

    cur_span /= 2;
    for (int v : next_ask) { cur_ask.PB(v); }
  }

  debug(heights);

  vector<PII> edges;

  for (int rem = 0; rem < 3; ++rem) {
    VI from, to;
    for (int i = 0; i < N; ++i) {
      if (heights[i] % 3 == rem) {
        from.PB(i);
      }
      if (heights[i] % 3 == (rem + 1) % 3) {
        to.PB(i);
      }
    }

    const int S = SZ(from);
    const int T = SZ(to);
    vector<int> to_mapping(T);

    debug(from, to);

    for (int b = 1; b < S; b *= 2) {
      debug(b);
      vector<int> query(N);
      for (int i = 0; i < S; ++i) {
        if (i & b) { query[from[i]] = 1; }
      }
      auto ans = Ask(query);
      for (int i = 0; i < T; ++i) {
        if (ans[to[i]]) { to_mapping[i] += b; }
      }
    }

    for (int i = 0; i < T; ++i) {
      if (to[i] == 0) { continue; }
      edges.emplace_back(from[to_mapping[i]], to[i]);
    }
  }

  Answer(edges);

}