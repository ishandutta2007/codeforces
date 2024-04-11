#include <iostream>
#include <memory.h>

using namespace std;

constexpr int N = 1000;

bool a[N + 1];

int main()
{
    int t, n, m;
    cin >> t;
    while (t--) {
      cin >> n >> m;
      int alive = 0;
      cin.ignore();
      for (int i = 0; i < n; ++i) {
        alive += a[i] = cin.get() == '1';
      }
      a[n] = 0;
      int changed = -1;
      for (int i = 0; i < m && changed; ++i) {
        bool abefore = 0;
        changed = 0;
        for (int j = 0; j < n; ++j) {
          int nei = abefore + a[j + 1];
          abefore = a[j];
          changed -= a[j];
          changed += a[j] |= nei == 1;
        }
        alive += changed;
      }
      for (int i = 0; i < n; ++i) {
        cout.put(a[i] + '0');
      }
      cout << '\n';
    }
    return 0;
}