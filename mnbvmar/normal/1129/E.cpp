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

int N;

int Ask(VI S, VI T, int v) {
  if (SZ(S) == 0 || SZ(T) == 0) { return 0; }

  cout << SZ(S) << "\n";
  for (int x : S) { cout << x << " "; }
  cout << "\n";
  cout << SZ(T) << "\n";
  for (int x : T) { cout << x << " "; }
  cout << "\n";
  cout << v << endl;

  int ans;
  cin >> ans;
  return ans;
}

int FindAnySub(int v, set<int> remaining_set) {
  remaining_set.erase(v);

  vector<int> remaining(ALL(remaining_set));
  debug(v, remaining);
  if (Ask(VI{1}, remaining, v) == 0) { return -1; }

  function<int(int,int)> Rec = [&](int L, int R) {
    if (L == R - 1) {
      return L;
    }

    const int mid = (L + R) / 2;
    if (Ask(VI{1}, VI(remaining.begin() + L, remaining.begin() + mid), v)) {
      return Rec(L, mid);
    } else {
      return Rec(mid, R);
    }
  };

  const int S = SZ(remaining);
  return remaining[Rec(0, S)];
}

int32_t main() {
  cin >> N;

  vector<int> tree_sizes(N + 1);
  VI without_1;
  for (int v = 2; v <= N; ++v) { without_1.PB(v); }

  tree_sizes[1] = N;
  for (int v = 2; v <= N; ++v) {
    tree_sizes[v] = Ask(VI{1}, without_1, v);
  }

  VI order = without_1;
  order.PB(1);
  sort(ALL(order), [&](int lhs, int rhs) {
        return tree_sizes[lhs] < tree_sizes[rhs];
      });

  debug(tree_sizes, order);

  vector<PII> answer;
  set<int> unconnected_verts(ALL(without_1));
  for (int v : order) {
    if (tree_sizes[v] == 1) { continue; }

    while (true) {
      int s = FindAnySub(v, unconnected_verts);
      if (s == -1) { break; }
      answer.emplace_back(v, s);
      debug(v, s);
      unconnected_verts.erase(s);
    }
  }

  cout << "ANSWER" << endl;
  for (auto [u, v] : answer) { cout << u << " " << v << endl; }
}