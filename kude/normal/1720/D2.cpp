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

constexpr int INF = 1001001001;

struct Node {
  Node* ch[2];
  int d[4];
  Node() {
    ch[0] = ch[1] = nullptr;
    rep(i, 4) d[i] = -INF;
  }
};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    Node* root = new Node;
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n) {
      int x;
      cin >> x;
      int val = 1;
      Node* now = root;
      rrep(k, 30) {
        int xb = x >> k & 1, ib = i >> k & 1;
        chmax(val, now->d[xb << 1 | ib] + 1);
        int nb = xb ^ ib;
        if (now->ch[nb] == nullptr) break;
        now = now->ch[nb];
      }
      chmax(ans, val);
      now = root;
      rrep(k, 30) {
        int xb = x >> k & 1, ib = i >> k & 1;
        chmax(now->d[(ib ^ 1) << 1 | xb], val);
        int nb = xb ^ ib;
        if (now->ch[nb] == nullptr) {
          now->ch[nb] = new Node;
        }
        now = now->ch[nb];
      }
    }
    cout << ans << '\n';
    auto dfs = [&](auto self, Node* now) {
      if (now == nullptr) return;
      rep(i, 2) self(self, now->ch[i]);
      delete now;
    };
    dfs(dfs, root);
  }
}