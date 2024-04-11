#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

constexpr int N = 200;

int n;
int ord[N];
char known[20][20];

bool askh(int i, int j) {
  if (n < 9 && known[i][j]) {
    return known[i][j] == -1;
  }
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  char c; cin >> c;
  auto res = c == '<';
  if (n < 9) {
    known[i][j] = 1 - 2 * res;
    known[j][i] = 2 * res - 1;
  }
  return res;
}

void solve_fast() {
  iota(ord, ord + 2 * n, 0);
  nth_element(ord, ord + n - 1, ord + 2 * n, askh);
}

struct CmpG {
  bool operator()(int i, int j) const { return askh(j, i); }
};

template <typename T>
auto& getcont(T& C) {
  struct Hack : T {
    static auto& getcont(T& C) {
      return C.*&Hack::c;
    }
  };
  return Hack::getcont(C);
}

void solve() {
  static priority_queue<int, vector<int>, CmpG> w0, w1;
  getcont(w0).clear();
  getcont(w1).clear();
  w0.push(0), w0.push(1);
  for (int other = 2; other <= n; ++other) {
    w1.push(other);
  }
  for (int other = n + 1; other < 2 * n; ++other) {
    if (askh(w0.top(), w1.top())) {
      w0.pop(), w0.push(other);
    } else {
      w1.pop(), w1.push(other);
    }
  }
  askh(w0.top(), w1.top());
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int it = (cin >> it, it); it--; ) {
    cin >> n;
    if (n < 9)
    for (int i = 0; i < 2 * n; ++i)
    for (int j = 0; j < 2 * n; ++j) {
      known[i][j] = 0;;
    }
    n > 20? solve_fast(): solve();
    cout << '!' << endl;;
  }
}