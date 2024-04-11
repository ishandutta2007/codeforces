#include <iostream>
#include <set>

using namespace std;

int main()
{
  int t, n, a;
  set<int> s;
  cin >> t;
  while (t--) {
    bool ok = 0;
    s.clear();
    s.insert(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      auto s2 = s;
      for (auto j: s2) {
        for (auto sgn: {-1, 1}) {
          int sum = abs(j + sgn * a);
          ok |= !sum;
          s.insert(sum);
        }
      }
    }
    cout << (ok? "YES\n": "NO\n");
  }
  return 0;
}