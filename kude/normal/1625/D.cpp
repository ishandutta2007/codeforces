#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;


struct binary_trie {
    using val_type = unsigned int;
    static constexpr int k = 8 * sizeof(val_type);

    struct Node {
        unsigned int count = 0;
        int idx[2] = {-1, -1};
    };
    std::vector<Node> d{{}};

    void add(val_type x) {
        int now = 0;
        d[0].count++;
        for(int i = k - 1; i >= 0; i--) {
            bool bit = x >> i & 1;
            if (d[now].idx[bit] == -1) {
                d[now].idx[bit] = d.size();
                d.emplace_back();
            }
            now = d[now].idx[bit];
            d[now].count++;
        }
    }

    val_type xor_max(val_type x) {
        assert(d[0].count);
        int now = 0;
        val_type z = 0;
        for(int i = k - 1; i >= 0; i--) {
            bool bit = !(x >> i & 1);
            if (d[now].idx[bit] == -1) bit = !bit;
            z = z << 1 | bit;
            now = d[now].idx[bit];
        }
        return x ^ z;
    }
};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  VI a(n);
  rep(i, n) cin >> a[i];
  if (k == 0) {
    cout << n << '\n';
    for(int i = 1; i <= n; i++) cout << i << " \n"[i == n];
    return 0;
  }
  int msb = 0;
  rep(i, 30) if (k >> i & 1) msb = i;
  map<int, VI> cat;
  rep(i, n) cat[a[i] >> (msb + 1)].emplace_back(i);
  VI ans;
  VI is0, is1;
  for(auto& [_, c] : cat) {
    is0.clear(); is1.clear();
    for(int i : c) {
      if (a[i] >> msb & 1) is1.emplace_back(i);
      else is0.emplace_back(i);
    }
    if (is0.empty()) {
      ans.emplace_back(is1[0]);
      continue;
    }
    if (is1.empty()) {
      ans.emplace_back(is0[0]);
      continue;
    }
    binary_trie bt;
    for(int i : is0) bt.add(a[i]);
    bool found = false;
    for(int i : is1) {
      if (bt.xor_max(a[i]) >= k) {
        found = true;
        ans.emplace_back(i);
        for(int j : is0) if ((a[i] ^ a[j]) >= k) {
          ans.emplace_back(j);
          break;
        }
        break;
      }
    }
    if (!found) {
      ans.emplace_back(is0[0]);
    }
  }
  int sz = ans.size();
  if (sz <= 1) {
    cout << -1 << '\n';
    return 0;
  }
  cout << sz << '\n';
  rep(i, sz) cout << ans[i] + 1 << " \n"[i + 1 == sz];
}