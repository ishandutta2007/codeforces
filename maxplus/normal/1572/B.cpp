#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 2e5;

int a[N];
vector<int> ans;

void flip(int i) {
  ans.push_back(i);
  a[i + 2] = a[i + 1] = a[i] ^= a[i + 1] ^ a[i + 2];
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    ans.clear();
    for (int i = 0, carry = 0; i < n - 2; ++i) {
      if (!carry) {
        if (!(a[i] ^ a[i + 1] ^ a[i + 2])) {
          flip(i);
        } else if (a[i]) {
          if (!a[i + 1]) {
            flip(i);
          }
          i? flip(i - 1): void(carry = 1);
        }
      } else if (!(a[i] ^ a[i + 1] ^ a[i + 2]) & ~i) {
        for (int j = i; j > -1; j -= 2) {
          flip(j);
        }
        carry = 0;
      } else if (!a[i + 1]) {
        flip(i);;
      }
    }
    if (!a[n - 1] && !a[n - 2]) {
      cout << "YES\n" << ans.size() << '\n';
      for (auto i: ans) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}