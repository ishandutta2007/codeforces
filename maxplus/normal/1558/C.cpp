#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 2021;

int a[N + 2], n;
vector<int> ans;

void rev(int pos) {
  reverse(a, a + pos);
  ans.push_back(pos);
}

bool rev_by_val(int val, int offset = 0) {
  int pos = find(a, a + n, val) - a;
  if (!((val ^ pos) & 1)) {
    return 0;
  }
  rev((pos & ~1) + 1 + offset);
  return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
      cin >> n;
      for (int i = 0; i < n; ++i) {
        cin >> a[i];
      }
      bool ok = 1;
      ans.clear();
      for (int i = n; i > 1; i -= 2) {
        ok &= rev_by_val(i);
        ok &= rev_by_val(i - 1);
        ok &= rev_by_val(i, 2);
        rev(3);
        rev(i);
      }
      if (ok) {
        cout << ans.size() << '\n';
        for (auto i: ans) {
          cout << i << ' ';
        }
        cout << '\n';
      } else {
        cout << "-1\n";
      }
    }
    return 0;
}