#include <bits/stdc++.h>

using namespace std;

int count_zeroes(int n) {
  int result = 0;
  while (n) {
    result += n / 5;
    n /= 5;
  }

  return result;
}

void solve() {
  int m; cin >> m;

  vector<int> answer;
  for (int n = 1; n <= 1000000; n++) {
    if (count_zeroes(n) == m) {
      answer.push_back(n);
    }
  }

  cout << answer.size() << "\n";
  for (int x : answer) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}