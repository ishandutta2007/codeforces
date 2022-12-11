#include <bits/stdc++.h>

using namespace std;

const int MAX_C = 1000100;
const int MAX_T = 7;

bool has_c[MAX_C];
bool has_c_divisor[MAX_C];

vector<int> prime_divisors;

bool f[1 << MAX_T];
int g[1 << MAX_T];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int c; scanf("%d", &c);

    has_c[c] = true;
  }

  for (int i = 1; i < MAX_C; i++) {
    for (int j = i; j < MAX_C; j += i) {
      if (has_c[j]) {
        has_c_divisor[i] = true;
        break;
      }
    }
  }

  for (int d = 2; d * d <= k; d++) {
    if (k % d == 0) {
      int prime_divisor = 1;
      while (k % d == 0) {
        prime_divisor *= d;
        k /= d;
      }

      prime_divisors.push_back(prime_divisor);
    }
  }

  if (k > 1) {
    prime_divisors.push_back(k);
  }

  int t = (int) prime_divisors.size();
  f[0] = true;

  for (int mask = 0; mask < (1 << t); mask++) {
    g[mask] = 1;

    for (int i = 0; i < t; i++) {
      if (mask & (1 << i)) {
        g[mask] *= prime_divisors[i];
      }
    }
  }

  for (int mask = 1; mask < (1 << t); mask++) {
    int submask = mask;

    while (submask) {
      if (f[mask ^ submask] && has_c_divisor[g[submask]]) {
        f[mask] = true;
        break;
      }

      submask = mask & (submask - 1);
    }
  }

  if (f[(1 << t) - 1]) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

int main() {
  solve();

  return 0;
}