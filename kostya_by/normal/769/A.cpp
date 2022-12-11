#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 6;

int n;
int years[kMaxN];

void Solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> years[i];
  }

  int k = n / 2;
  nth_element(years, years + k, years + n);
  cout << years[k] << "\n";
}

int main() {
  Solve();

  return 0;
}