#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 101;
const int kMaxA = 501;

int n;
int m;
int a[kMaxN][kMaxN];

int row_sum[kMaxN];
int col_sum[kMaxN];

int r_value[kMaxN];
int c_value[kMaxN];

void Solve() {
  memset(row_sum, 0, sizeof(row_sum));
  memset(col_sum, 0, sizeof(col_sum));

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];

      row_sum[i] += a[i][j];
      col_sum[j] += a[i][j];
    }
  }

  for (int i = 1; i < n; ++i) {
    int delta = abs(row_sum[0] - row_sum[i]);
    if (delta % m != 0) {
      cout << "-1\n";
      return;
    }
  }

  const auto is_valid_value = [](int a) {
    return 0 <= a && a < kMaxA;
  };

  int min_operations_num = -1;
  vector<int> best_r_value;
  vector<int> best_c_value;
  for (int r0 = 0; r0 < kMaxA; ++r0) {
    r_value[0] = r0;

    bool is_successful = true;
    int operations_num = r0;
    for (int i = 1; i < n; ++i) {
      r_value[i] = (row_sum[i] - row_sum[0]) / m + r_value[0];

      if (!is_valid_value(r_value[i])) {
        is_successful = false;
        break;
      }

      operations_num += r_value[i];
    }

    if (!is_successful) {
      continue;
    }

    for (int j = 0; j < m; ++j) {
      c_value[j] = a[0][j] - r_value[0];
      if (!is_valid_value(c_value[j])) {
        is_successful = false;
        break;
      }

      operations_num += c_value[j];
    }

    if (!is_successful) {
      continue;
    }

    if (min_operations_num != -1 && min_operations_num < operations_num) {
      continue;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (r_value[i] + c_value[j] != a[i][j]) {
          is_successful = false;
          break;
        }
      }

      if (!is_successful) {
        break;
      }
    }

    if (!is_successful) {
      continue;
    }

    min_operations_num = operations_num;
    best_r_value = vector<int>(r_value, r_value + n);
    best_c_value = vector<int>(c_value, c_value + m);
  }

  cout << min_operations_num << "\n";
  if (min_operations_num != -1) {
    for (int i = 0; i < best_r_value.size(); ++i) {
      for (int k = 0; k < best_r_value[i]; ++k) {
        cout << "row " << i + 1 << "\n";
      }
    }

    for (int j = 0; j < best_c_value.size(); ++j) {
      for (int k = 0; k < best_c_value[j]; ++k) {
        cout << "col " << j + 1 << "\n";
      }
    }
  }
}

int main() {
  int cases_num; cases_num = 1;

  for (int i = 0; i < cases_num; ++i) {
    Solve();
  }

  return 0;
}