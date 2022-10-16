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

LL N, S;

const int MaxN = 2e5;
int found_parent[MaxN];
int cur_depth[MaxN];
int count_at_depth[MaxN];
bool is_on_low_path[MaxN];

bool CanMaxBranch(int b) {
  LL on_lvl = 1;
  LL remaining = N;
  LL min_total = 0;
  fill_n(count_at_depth, N + 1, 0);
  fill_n(is_on_low_path, N + 1, false);

  for (int lvl = 1; remaining; ++lvl) {
    const int max_lvl = min(on_lvl, remaining);
    min_total += max_lvl * lvl;
    remaining -= max_lvl;
    on_lvl *= b;
  }

  debug(b, min_total);

  if (min_total > S) {
    return false;
  }

  int cur_parent = 0;
  int parent_for = b;
  for (int i = 1; i < N; ++i) {
    if (parent_for == 0) {
      ++cur_parent;
      parent_for = b;
    }

    found_parent[i] = cur_parent;
    cur_depth[i] = cur_depth[cur_parent] + 1;
    ++count_at_depth[cur_depth[i]];
    --parent_for;
  }

  int lowest_vert = N - 1;
  int lowest_depth = cur_depth[lowest_vert];
  LL cur_total = min_total;

  for (int v = lowest_vert; v; v = found_parent[v]) {
    is_on_low_path[v] = true;
  }

  for (int i = N - 2; i > 0; --i) {
    if (is_on_low_path[i]) { continue; }
    if (count_at_depth[cur_depth[i]] == 1) { continue; }
    --count_at_depth[i];
    debug(i, count_at_depth[cur_depth[i]]);
    int cur_diff = lowest_depth + 1 - cur_depth[i];
    if (cur_diff <= S - cur_total) {
      found_parent[i] = lowest_vert;
      cur_depth[i] = lowest_depth + 1;
      lowest_vert = i;
      lowest_depth = cur_depth[i];
      cur_total += cur_diff;
      continue;
    }

    int dest = lowest_vert;
    while (cur_diff > S - cur_total) {
      dest = found_parent[dest];
      --cur_diff;
    }
    found_parent[i] = dest;
    cur_depth[i] = cur_depth[dest] + 1;
    cur_total += cur_diff;
    break;
  }

  assert(cur_total == S);
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> S;

  if (S < 2 * N - 1 || S > N * (N + 1) / 2) {
    cout << "No\n";
    return 0;
  }

#warning 0
  int lft = 1, rgt = N;
  while (rgt - lft > 1) {
    const int mid = (lft + rgt) / 2;
    if (CanMaxBranch(mid)) {
      rgt = mid;
    } else {
      lft = mid;
    }
  }

  debug(rgt);
  CanMaxBranch(rgt);

  cout << "Yes\n";
  for (int i = 1; i < N; ++i) {
    cout << found_parent[i] + 1 << " ";
  }
  cout << "\n";
}