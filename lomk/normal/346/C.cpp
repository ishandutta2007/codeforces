/*input
3
5 6 7
1000 200

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
const int N = 1e6 + 5;

int n;
int L, R;
vector<int> a;

int divi[N];
int dp[N];

void eratosthene() {
  memset(divi, -1, sizeof(divi));
  for (auto it : a) {
    int start = L;
    if (L % it != 0)
      start += it - L % it;
    for (int i = start; i <= R; i += it) {
      divi[i - L] = max(divi[i - L], it);
    }
  }
}

bool inverted(pair<int, int> X, pair<int, int> Y) {
  if (X.fi <= Y.fi && X.se >= Y.se)
    return true;
  return false;
}

void solve() {
  memset(dp, 60, sizeof(dp));
  dp[0] = 0;

  deque<pair<int, int>> vals; // <pos, val>

  loop(i, L, R) {
    while (!vals.empty() && vals.front().fi < i)
      vals.pop_front();

    int &curVal = dp[i - L];

    if (i != L) {
      curVal = min(curVal, dp[i - L - 1] + 1);
      if (!vals.empty())
        curVal = min(curVal, vals.front().se);
    }

    if (divi[i - L] != -1) {
      int num = divi[i - L];
      pair<int, int> newPair = {i + num - 1, curVal + 1};
      while (!vals.empty() && inverted(vals.back(), newPair))
        vals.pop_back();

      if (vals.empty() || !inverted(vals.back(), newPair))
        vals.push_back(newPair);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  cin >> R >> L;

  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());

  eratosthene();
  solve();
  cout << dp[R - L] << endl;
}