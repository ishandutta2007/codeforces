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

const int kBase = 1 << 17;

struct Node {
  bool flip_minus, flip_plus;

  Node() : flip_minus(0), flip_plus(0) {}
  Node(char ch, int bound, int cur_val) {
    if (ch == '>') {
      flip_minus = -cur_val > bound;
      flip_plus = cur_val > bound;
    } else {
      flip_minus = -cur_val < bound;
      flip_plus = cur_val < bound;
    }
  }

  Node Merge(const Node &rhs) const {
    Node ans;
    ans.flip_minus = flip_minus ? !rhs.flip_plus : rhs.flip_minus;
    ans.flip_plus = flip_plus ? !rhs.flip_minus : rhs.flip_plus;
    return ans;
  }
};

Node tree[kBase * 2];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N, Q;
  cin >> N >> Q;
  string type;
  VI bound(Q);

  VI arr(N);
  for (int &x : arr) { cin >> x; }

  vector<VI> at_abs_bound(kBase);

  for (int i = 0; i < Q; ++i) {
    char ch;
    cin >> ch >> bound[i];
    type += ch;

    tree[i + kBase] = Node(ch, bound[i], 0);
    at_abs_bound[abs(bound[i])].PB(i);
    if (bound[i]) {
      at_abs_bound[abs(bound[i]) - 1].PB(i);
    }
  }

  for (int i = kBase - 1; i > 0; --i) {
    tree[i] = tree[i * 2].Merge(tree[i * 2 + 1]);
  }

  VI ans_plus(kBase);
  VI ans_minus(kBase);

  for (int i = 0; i < kBase; ++i) {
    auto &root = tree[1];
    ans_plus[i] = i * (root.flip_plus ? -1 : 1);
    ans_minus[i] = -i * (root.flip_minus ? -1 : 1);

    for (int loc : at_abs_bound[i]) {
      int v = loc + kBase;
      tree[v] = Node(type[loc], bound[loc], i + 1);
      v /= 2;
      while (v) {
        tree[v] = tree[v * 2].Merge(tree[v * 2 + 1]);
        v /= 2;
      }
    }
  }

  for (int v : arr) {
    const int ans = v >= 0 ? ans_plus[v] : ans_minus[-v];
    cout << ans << " ";
  }
  cout << "\n";
}