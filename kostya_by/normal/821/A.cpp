#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 51;

int n;
int a[kMaxN][kMaxN];

void Solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 1) {
        continue;
      }

      bool success = false;
      for (int s = 0; s < n; ++s) {
        for (int t = 0; t < n; ++t) {
          if (a[i][j] == a[i][s] + a[t][j]) {
            success = true;
            break;
          }
        }
        if (success) {
          break;
        }
      }

      if (!success) {
        cout << "No\n";
        return;
      }
    }
  }

  cout << "Yes\n";
}

int main() {
  Solve();
  return 0;
}