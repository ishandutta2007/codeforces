#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200200;

int f[MAX_N];

int main() {
  int n; cin >> n;

  int answer = 0;

  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    f[x] = f[x - 1] + 1;

    answer = max(answer, f[x]);
  }

  cout << n - answer << "\n";
}