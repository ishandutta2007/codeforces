#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

template<class S>
struct value_compression : vector<S> {
  bool built = false;
  using VS = vector<S>;
  using VS::vector;
  value_compression(vector<S> v) : vector<S>(move(v)) {}
  void build() {
    sort(VS::begin(), VS::end());
    VS::erase(unique(VS::begin(), VS::end()), VS::end());
    built = true;
  }
  template<class T>
  void convert(T first, T last) { for (; first != last; ++first) *first = (*this)(*first); }
  int operator()(S x) {
    assert(built);
    return lower_bound(VS::begin(), VS::end(), x) - VS::begin();
  }
  void clear() { VS::clear(); built = false; }
};

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    value_compression<P> vc; vc.reserve(5 * n);
    vector<P> xy(n);
    for(auto& [x, y]: xy) {
      cin >> x >> y;
      vc.emplace_back(x, y);
      rep(k, 4) {
        int nx = x + di[k];
        int ny = y + dj[k];
        vc.emplace_back(nx, ny);
      }
    }
    vc.build();
    const int sz = vc.size();
    VI ixy(n);
    rep(i, n) ixy[i] = vc(xy[i]);
    vector<char> on_point(sz);
    for(int i: ixy) on_point[i] = true;
    VI ans(sz, -1);
    queue<int> q;
    rep(i, sz) if (!on_point[i]) {
      q.emplace(i);
      ans[i] = i;
    }
    while(!q.empty()) {
      int u = q.front(); q.pop();
      auto [x, y] = vc[u];
      rep(k, 4) {
        int nx = x + di[k];
        int ny = y + dj[k];
        int v = vc({nx, ny});
        if (v == sz || vc[v] != P{nx, ny}) continue;
        if (ans[v] != -1) continue;
        ans[v] = ans[u];
        q.emplace(v);
      }
    }
    rep(i, n) {
      auto [x, y] = vc[ans[ixy[i]]];
      cout << x << ' ' << y << '\n';
    }
  }
}