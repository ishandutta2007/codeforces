#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  auto sorted = [&](vector<vector<int>> a) {
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] < mx) return false;
        mx = a[i][j];
      }
    }
    return true;
  };

  for (int len = 0; len <= n + m - 1; ++len) {
    vector<int> val;
    for (int i = 0; i < len; ++i) val.push_back(0);
    for (int i = len; i < n + m - 1; ++i) val.push_back(1);
    vector<int> first_row;
    vector<int> first_col;
    for (int i = 0; i < m; ++i) first_row.push_back(val[i]);
    first_col.push_back(val[0]);
    for (int i = m; i < n + m - 1; ++i) first_col.push_back(val[i]);
    vector<int> flip_row(n);
    vector<int> flip_col(m);
    for (int i = 0; i < m; ++i) {
      flip_col[i] = first_row[i] != a[0][i];
    }
    for (int i = 1; i < n; ++i) {
      flip_row[i] = flip_col[0] ^ (a[i][0] != first_col[i]);
    }
    vector<vector<int>> b = a;
    for (int i = 0; i < n; ++i) {
      if (flip_row[i]) {
        for (int j = 0; j < m; ++j) {
          b[i][j] ^= 1;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      if (flip_col[i]) {
        for (int j = 0; j < n; ++j) {
          b[j][i] ^= 1;
        }
      }
    }
    if (sorted(b)) {
      cout << "YES\n";
      for (int v : flip_row) cout << v; cout << endl;
      for (int v : flip_col) cout << v; cout << endl;
      return 0;
    }
  }
  cout << "NO\n";
}