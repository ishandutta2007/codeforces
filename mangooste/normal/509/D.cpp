#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> w;
int min_MOD = -1000000001, MOD = -1;
vector<int> a, b, bad;

void print_ans() {
  cout << "YES\n";
  if (MOD == -1) {
    cout << "1000000000000000000\n";
  } else {
    cout << MOD << '\n';
  }
  for (auto el : a) {
    cout << el << ' ';
  }
  cout << '\n';
  for (auto el : b) {
    cout << el << ' ';
  }
  cout << '\n';
  exit(0);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  w.resize(n, vector<int>(m));
  for (auto &el : w) {
    for (auto &ell : el) {
      cin >> ell;
      min_MOD = max(min_MOD, ell);
    }
  }
  min_MOD++;
  a.assign(n, -1);
  b = w[0];
  a[0] = 0;
  for (int i = 0; i < n; i++) {
    vector<int> val;
    for (int j = 0; j < m; j++) {
      if (b[j] <= w[i][j]) {
        val.push_back(w[i][j] - b[j]);
      }
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    if (val.empty()) {
      bad.push_back(i);
    } else if (val.size() == 1) {
      a[i] = val[0];
      for (int j = 0; j < m; j++) {
        if (b[j] > w[i][j]) {
          if (MOD == -1) {
            if (a[i] + b[j] - w[i][j] < min_MOD) {
              cout << "NO\n";
              return 0;
            }
            MOD = a[i] + b[j] - w[i][j];
          } else if (a[i] + b[j] - MOD != w[i][j]) {
            cout << "NO\n";
            return 0;
          }
        }
      }
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  if (bad.empty()) {
    print_ans();
  }
  vector<int> all;
  for (auto i : bad) {
    vector<int> sum;
    for (int j = 0; j < m; j++) {
      sum.push_back(w[i][j] - b[j]);
    }
    sort(sum.begin(), sum.end());
    sum.resize(unique(sum.begin(), sum.end()) - sum.begin());
    if (sum.size() > 1) {
      cout << "NO\n";
      return 0;
    }
    all.push_back(sum[0]);
  }
  int mn = *min_element(all.begin(), all.end());
  if (MOD == -1) {
    MOD = max(abs(mn), min_MOD);
  } else if (MOD < abs(mn)) {
    cout << "NO\n";
    return 0;
  }
  for (auto i : bad) {
    a[i] = w[i][0] - b[0] + MOD;
  }
  print_ans();
}