/*input
1
7
-1 1 0 1 0 1 0
5
0 -1 1 0 1
3
1 0 1
1
1

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
// const int N =;
const int INF = numeric_limits<int>::max() / 2;

class TestX {
public:
  int n;
  vector<int> a;

  vector<pair<int, int>> solvePositive(int val, int nTurn) {
    vector<pair<int, int>> ret;
    // loop(i,0,n-1) if (a[i]==-1) ans.push_back({i,i});

    ret.push_back({0, 0});
    loop(i, 1, n - 1) {
      if (nTurn!=0&&a[i] == val && (a[i - 1] == 0||a[i-1]==val)) {
        nTurn--;
        ret.pop_back();
        ret.push_back({i - 1, i});
        if (i+1<=n-1) ret.push_back({i+1,i+1});
        i++;
      } else {
        ret.push_back({i, i});
      }
    }
    if (nTurn != 0)
      return {};
    return ret;
  }

  void operator()() {
    cin >> n;
    a = vector<int>(n, 0);
    for (auto &it : a)
      cin >> it;

    int sum = 0;
    for (auto it : a)
      sum += it;

    if (sum % 2 != 0) {
      cout << -1 << endl;
      return;
    }
    vector<pair<int, int>> rec;
    if (sum >= 0) {
      rec = solvePositive(1, sum / 2);

    } else {
      rec = solvePositive(-1, (-sum) / 2);
    }

    if (rec.size() == 0) {
      cout << -1 << endl;
      return;
    }
    cout << rec.size() << endl;
    for (auto [l, r] : rec)
      cout << l + 1 << sp << r + 1 << endl;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    TestX test;
    test();
  }
}