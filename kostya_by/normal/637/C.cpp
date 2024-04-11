#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;

string codes[MAX_N];

void solve() {
  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> codes[i];
  }

  int answer = 6;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = 0;
      for (int k = 0; k < 6; k++) {
        a += codes[i][k] != codes[j][k];
      }

      answer = min(answer, (a + a % 2) / 2 - 1);
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);

  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}