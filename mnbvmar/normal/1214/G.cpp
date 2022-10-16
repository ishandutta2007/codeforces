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

const int kMaxN = 2048;
const int kBuckSize = 50;
const int kNumBucks = kMaxN / kBuckSize + 5;

using Bits = bitset<kMaxN>;
Bits rows[kMaxN];

Bits cur_queued[kMaxN];
Bits tree[kMaxN];
Bits buckets[kNumBucks];
Bits cur_total;
queue<pair<int, Bits>> ops_waiting;
int last_change[kMaxN];
pii cur_bad;

void Flip(int r, Bits b) {
  debug(r, b);
  static int pushid = 0, popid = 0;
  last_change[r] = pushid;
  ++pushid;

  cur_bad = pii{-1, -1};

  cur_queued[r] ^= b;
  b = cur_queued[r];
  debug(b);
  ops_waiting.emplace(r, b);

  Bits old_b = tree[r];
  buckets[r / kBuckSize] ^= old_b;
  cur_total ^= old_b;
  tree[r].reset();
  debug(cur_total);

  while (!ops_waiting.empty()) {
    auto [op_r, op_b] = ops_waiting.front();
    if (popid != last_change[op_r]) {
      ops_waiting.pop();
      ++popid;
      continue;
    }
    debug(op_r, op_b, last_change[op_r], popid);
    Bits x = (cur_total & op_b);
    if (x.any()) {
      int bit = x._Find_first();
      int buckid = -1;
      for (int i = 0; i < kNumBucks; ++i) {
        if (buckets[i][bit]) { buckid = i; break; }
      }
      assert(buckid != -1);
      int which = -1;
      for (int i = buckid * kBuckSize;; ++i) {
        if (tree[i][bit]) { which = i; break; }
      }
      assert(which != -1);
      cur_bad = pii{which, op_r};
      debug("!", cur_bad);
      break;
    } else {
      tree[op_r] = op_b;
      buckets[op_r / kBuckSize] ^= op_b;
      cur_total ^= op_b;
      debug(cur_total);
      ops_waiting.pop();
      ++popid;
    }
  }

  /*r += kMaxN;
  tree[r] ^= b;
  r /= 2;
  while (r) {
    tree[r] = tree[r*2] | tree[r*2+1];
    is_bad[r] = (is_bad[r*2] || is_bad[r*2+1] || (tree[r*2] & tree[r*2+1]).any());
    r /= 2;
  }*/
}

/*vi GetBad() {
  int x = 1;
  while (true) {
    if (is_bad[x * 2]) { x *= 2; continue; }
    if (is_bad[x * 2 + 1]) { x = x * 2 + 1; continue; }
    break;
  }

  assert(is_bad[x]);
  int bit = (tree[x*2] & tree[x * 2 + 1])._Find_first();
  vi found{bit};
  for (int y : {x * 2, x * 2 + 1}) {
    while (y < kMaxN) {
      if (tree[y*2][bit]) { y *= 2; } else { y = y * 2 + 1; }
    }
    found.push_back(y-kMaxN);
  }
  return found;
}*/

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n, m, q;
  cin >> n >> m >> q;

  vector<int> bit_cnts(n + 5);
  set<pii> row_order;
  for (int i = 0; i < n; ++i) {
    row_order.emplace(0, i);
  }
  row_order.emplace(-1, n);
  row_order.emplace(m, n + 1);
  bit_cnts[n+1] = m;
  bit_cnts[n] = -1;
  for (int i = 0; i < m; ++i) {
    rows[n + 1][i] = true;
  }
  Flip(n + 1, rows[n + 1]);

  vector<Bits> prefs(m + 1);
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j < i; ++j) {
      prefs[i][j] = true;
    }
  }

  auto ApplyVals = [&](set<pii>::iterator iter) {
    if (iter != row_order.begin()) {
      Bits a = rows[prev(iter)->nd] ^ rows[iter->nd];
      Flip(iter->nd, a);
    }
    auto nxt = next(iter);
    Bits nxtbits;
    if (nxt != row_order.end()) {
      nxtbits = rows[nxt->nd] ^ rows[iter->nd];
    }
    if (iter != row_order.begin() && nxt != row_order.end()) {
      nxtbits ^= rows[nxt->nd] ^ rows[prev(iter)->nd];
    }
    if (nxt != row_order.end()) {
      Flip(nxt->nd, nxtbits);
    }
  };

  for (int i = 0; i < q; ++i) {
    int a, l, r;
    cin >> a >> l >> r;
    --a; --l; --r;

    auto iter = row_order.find(make_pair(bit_cnts[a], a));
    ApplyVals(iter);

    Bits toxor = prefs[r+1] ^ prefs[l];
    rows[a] ^= toxor;
    bit_cnts[a] = rows[a].count();
    row_order.erase(iter);

    auto [nxtiter, succ] = row_order.insert(make_pair(bit_cnts[a], a));
    assert(succ);
    ApplyVals(nxtiter);
#ifdef LOCAL
    debug(vector<pii>(ALL(row_order)));
#endif

    if (cur_bad.st != -1) {
      int r1 = cur_bad.st, r2 = cur_bad.nd;
      debug(r1, r2, tree[r1], ops_waiting.front().nd);
      int bit1 = (tree[r1] & ops_waiting.front().nd)._Find_first();
      //vi info = GetBad();
      //cout << info << "\n";
      //int r1 = info[1], r2 = info[2], bit1 = info[0];

      if (bit_cnts[r1] > bit_cnts[r2]) { swap(r1, r2); }
      if (bit_cnts[r1] == bit_cnts[r2] && r1 > r2) { swap(r1, r2); }
      if (rows[r2][bit1]) { r2 = prev(row_order.find(make_pair(bit_cnts[r2], r2)))->nd; }
      if (!rows[r1][bit1]) { r1 = prev(row_order.find(make_pair(bit_cnts[r1], r1)))->nd; }
      assert(rows[r1][bit1]);
      assert(!rows[r2][bit1]);

      int bit2 = (rows[r2] & (~rows[r1]))._Find_first();

      if (r1 > r2) { swap(r1, r2); }
      if (bit1 > bit2) { swap(bit1, bit2); }
      assert(rows[r1][bit1] == rows[r2][bit2]);
      assert(rows[r1][bit2] == rows[r2][bit1]);
      assert(rows[r1][bit1] != rows[r2][bit1]);
      //cout << "0\n";
      cout << r1+1 << " " << bit1+1 << " " << r2+1 << " " << bit2+1 << "\n";
    } else {
      cout << "-1\n";
    }

  }
}