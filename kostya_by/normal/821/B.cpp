#include <bits/stdc++.h>

using namespace std;

int m;
int b;

void Solve() {
  cin >> m >> b;

  long long answer = 0;
  for (int y = 0; y <= b; ++y) {
    long long x = m * (b - y);

    long long current_bid = static_cast<long long>(y + 1) * x * (x + 1) / 2 + (x + 1) * y * (y + 1) / 2;
    answer = max(answer, current_bid);
  }

  cout << answer << "\n";
}

int main() {
  Solve();
  return 0;
}