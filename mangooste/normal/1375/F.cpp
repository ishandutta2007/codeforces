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

int last = -1;
array<ll, 3> a;

array<pair<ll, int>, 3> get() {
  array<pair<ll, int>, 3> cur;
  for (int i = 0; i < 3; i++) {
    cur[i] = make_pair(a[i], i);
  }
  sort(cur.begin(), cur.end());
  return cur;
}

void Main() {
  cin >> a[0] >> a[1] >> a[2];
  cout << "First" << endl;
  array<pair<ll, int>, 3> b = get();
  ll x = b[1].first - b[0].first;
  ll y = b[2].first - b[1].first;
  cout << x + 2 * y << endl;
  cin >> last;
  if (last == 0) {
    return;
  }
  last--;
  if (last == b[2].second) {
    a[last] += x + 2 * y;
    array<pair<ll, int>, 3> b = get();
    x = b[1].first - b[0].first;
    y = b[2].first - b[1].first;
    cout << x + 2 * y << endl;
    int last;
    cin >> last;
    if (last == 0) {
      return;
    }
    last--;
    if (last == b[0].second) {
      cout << y << endl;
      cin >> last;
      assert(last == 0);
    } else {
      assert(last == b[1].second);
      cout << x + y << endl;
      cin >> last;
      assert(last == 0);
    }
  } else if (last == b[0].second) {
    cout << y << endl;
    cin >> last;
    assert(last == 0);
  } else {
    cout << x + y << endl;
    cin >> last;
    assert(last == 0);
  }
}