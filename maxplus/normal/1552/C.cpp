#include <algorithm>
#include <iostream>
#include <memory.h>

using namespace std;

constexpr int N = 100;

int l[2 * N + 1];
int fl[N];

int main()
{
    int t, n, k, a, b;
    cin >> t;
    while (t--) {
      memset(l, -1, sizeof l);
      int ans = 0;
      cin >> n >> k;
      for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        if (a > b) {
          swap(a, b);
        }
        l[b] = a;
        l[a] = a;
      }
      for (int i = 1, op = 0; i <= 2 * n; ++i) {
        bool f = l[i] == -1;
        bool toop = op < n - k;
        if (f? toop: l[i] == i) {
          l[i] = fl[op] = i;
        } else {
          if (f) {
            l[i] = fl[op - n + k];
          }
          for (int j = l[i] + 1; j < i; ++j) {
            ans += l[j] < l[i] && l[j] != j;
          }
        }
        op += f;
      }
      cout << ans << '\n';
    }
    return 0;
}