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

struct S {
  int v, cnt, idx;
  bool operator<(const S& rhs) const {
    return v < rhs.v;
  }
  S(int v, int cnt, int idx) : v(v), cnt(cnt), idx(idx) {}
};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<S> q;
  rep(i, n) {
    int x;
    cin >> x;
    q.emplace(x, 0, i + 1);
  }
  int ans = -1, i_ans = -1, j_ans = -1;
  while(q.size() > 1) {
    auto [v, cnt, i] = q.top(); q.pop();
    while(q.size() && q.top().v == v) {
      auto [_, c, j] = q.top(); q.pop();
      if (cnt + c > ans) {
        ans = cnt + c;
        i_ans = i;
        j_ans = j;
      }
      if (c > cnt) {
        cnt = c;
        i = j;
      }
    }
    if (v == 0) break;
    int k = 0;
    while((1 << k) < v) k++;
    int nv = (1 << k) - v;
    assert(nv < v);
    q.emplace(nv, cnt + 1, i);
  }
  cout << i_ans << ' ' << j_ans << ' ' << ans << '\n';
}