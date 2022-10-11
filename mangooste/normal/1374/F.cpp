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

void Main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
      cin >> el;
    }
    vector<int> ans;
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < n - 2; i++) {
      int where = -1;
      for (int j = i; j < n; j++) {
        if (a[j] == b[i]) {
          where = j;
          break;
        }
      }
      if (where == i) {
        continue;
      }
      if ((where - i) % 2 == 1) {
        if (where == n - 1) {
          ans.push_back(where - 2);
          a[where] = a[where - 1];
          a[where - 1] = a[where - 2];
          a[where - 2] = b[i];
          where -= 2;
        }
        ans.push_back(where - 1);
        a[where] = a[where - 1];  
        a[where - 1] = a[where + 1];
        a[where + 1] = b[i];
        where++;
      }
      for (int pos = where - 2; pos >= i; pos -= 2) {
        ans.push_back(pos);
      }
      for (int pos = where; pos > i; pos--) {
        swap(a[pos], a[pos - 1]);
      }
      a[i] = b[i];
    }
    if (a != b) {
      if (a[n - 3] == a[n - 1]) {
        ans.push_back(n - 3);
      } else {
        int where = -1;
        for (int i = 0; i < n - 3; i++) {
          if (a[i] == a[i + 1]) {
            where = i;
            break;
          }
        }
        if (where == -1) {
          cout << "-1\n";
          continue;
        }
        for (int i = where; i < n - 4; i++) {
          ans.push_back(i);
        }
        ans.push_back(n - 4);
        ans.push_back(n - 4);
        ans.push_back(n - 3);
        ans.push_back(n - 3);
        for (int i = n - 5; i >= where; i--) {
          ans.push_back(i);
          ans.push_back(i);
        }
      }
    }
    cout << (int)ans.size() << '\n';
    for (auto el : ans) {
      cout << el + 1 << ' ';
    }
    cout << '\n';
  }
}