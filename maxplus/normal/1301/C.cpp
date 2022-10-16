#include <iostream>

using namespace std;

int64_t subs(int64_t l) {
  return l * (l + 1) / 2;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    int l = (n + 1) / (m + 1);
    int am = (n + 1) % (m + 1);
    int64_t ans = subs(n);
    ans -= am * subs(l);
    ans -= (m + 1 - am) * subs(l - 1);
    cout << ans << '\n';
  }
}