#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 1000100;

int counters[MAX_A];
int last_vote[MAX_A];

void solve() {
  int n; cin >> n;

  for (int i = 1; i <= n; i++) {
    int a; cin >> a;

    counters[a] += 1;
    last_vote[a] = i;
  }

  int winner = 1;
  for (int i = 2; i < MAX_A; i++) {
    if (counters[i] > counters[winner] || (counters[i] == counters[winner] && last_vote[i] < last_vote[winner])) {
      winner = i;
    }
  }

  cout << winner << "\n";
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}