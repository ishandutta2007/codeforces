#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long a, b; cin >> a >> b;
  set<long long> answer;

  for (long long i = 1; i <= 60; i++) {
    long long value = (1ll << i) - 1ll;

    for (long long j = 0; j + 1 < i; j++) {
      long long temp = value - (1ll << j);

      if (a <= temp && temp <= b) {
        answer.insert(temp);
      }
    }
  }

  cout << answer.size() << "\n";
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}