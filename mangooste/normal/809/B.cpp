#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

inline bool ask(int x, int y) {
  cout << "1 " << x << ' ' << y << endl;
  string cur;
  cin >> cur;
  return (cur == "TAK");
}

int find(int L, int R, bool down = false) {
  if (L > R) {
    return -1;
  }
  int bl = L, br = R + 1;
  while (br - bl > 3) {
    int mid = (bl + br) / 2;
    if (down) {
      mid--;
    }
    mid = max(mid, L);
    if (ask(mid, mid + 1)) {
      br = mid + 1;
    } else {
      bl = mid + 1;
    }
  }
  if (br - bl == 3) {
    if (!ask(bl, bl + 1)) {
      bl++;
      if (!ask(bl, bl + 1)) {
        bl++;
      }
    }
  } else if (br - bl == 2) {
    if (!ask(bl, bl + 1)) {
      bl++;
    }
  }
  return bl;
}

void Main() {
  int n, k;
  cin >> n >> k;
  int one = find(1, n);
  int two = find(1, one - 1, true);
  if (two == -1 || two == one || !ask(two, one)) {
    assert(one != n);
    two = find(one + 1, n);
  }
  assert(two != -1);
  cout << "2 " << one << ' ' << two << endl;
}