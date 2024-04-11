/*input

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
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

class Solver {
public:
  int ask(int x, int y) {
    cout << "?" << sp << x << sp << y << endl;
    int ret;
    cin >> ret;
    if (ret == 1)
      return x;
    else if (ret == 2)
      return y;
    return -1;
  }

  void answer(int x) { cout << "!" << sp << x << endl; }

  int playRound(vector<int> a) {
    if (a.size() == 1) {
      return a[0];
    }
    if (a.size() == 2) {
      int which = ask(a[0], a[1]);
      return which;
    }
    vector<int> nextRound;
    for (int i = 0; i < a.size(); i += 4) {
      int which = ask(a[i], a[i + 2]);
      if (which == -1) {
        nextRound.push_back(ask(a[i + 1], a[i + 3]));
      } else if (which == a[i]) {
        nextRound.push_back(ask(a[i], a[i + 3]));
      } else {
        nextRound.push_back(ask(a[i + 1], a[i + 2]));
      }
    }
    return playRound(nextRound);
  }
  void operator()() {
    int n;
    cin >> n;
    vector<int> a;
    loop(i, 1, (1 << n)) { a.push_back(i); }
    int ans = playRound(a);
    answer(ans);
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    Solver solver;
    solver();
  }
}