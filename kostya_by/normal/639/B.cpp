#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, d, h; cin >> n >> d >> h;

  if (2 * h < d) {
    cout << "-1\n";
    return;
  }

  if (h < d) {
    for (int i = 2; i <= h + 1; i++) {
      cout << i - 1 << " " << i << "\n";
    }

    int path_length = h;
    int prev = 1;
    int next = h + 2;
    while (path_length < d) {
      path_length += 1;
      cout << prev << " " << next << "\n";
      tie(prev, next) = make_tuple(next, next + 1);
    }

    for (int i = next; i <= n; i++) {
      cout << 1 << " " << i << "\n";
    }

    return;
  }

  if (d == 1) {
    if (n == 2) {
      cout << "1 2\n";
    } else {
      cout << "-1\n";
    }

    return;
  }

  if (h == 1) {
    if (d == 2) {
      for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << "\n";  
      }
    } else {
      cout << "-1\n";
    }

    return;
  }

  for (int i = 2; i <= h + 1; i++) {
    cout << i - 1 << " " << i << "\n";
  }

  int path_length = h;
  int prev = 1;
  int next = h + 2;
  while (path_length < d) {
    path_length += 1;
    cout << prev << " " << next << "\n";
    tie(prev, next) = make_tuple(next, next + 1);
  }

  for (int i = next; i <= n; i++) {
    cout << 2 << " " << i << "\n";
  }
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}