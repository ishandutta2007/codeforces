#include <cstdint>
#include <cstring>
#include <iostream>
#include <utility>

static constexpr int kMaxN = 1005;
static constexpr int kModulo = 1000 * 1000 * 1000 + 7;


int64_t dp[2 * kMaxN][kMaxN];

void ClearDpData() {
  memset(dp, 0, sizeof(dp));
}

bool IsValidState(int n, int len, int balance) {
  if (len < 0 || len > 2 * n || balance < 0) {
    return false;
  }

  if (balance > std::min(len, 2 * n - len)) {
    return false;
  }

  if ((balance % 2) != (len % 2)) {
    return false;
  }

  return true;
}

int Solve(int n) {
  memset(dp, 0, sizeof(dp));

  dp[0][0] = 1;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (!IsValidState(n, i, j)) {
        continue;
      }

      if (IsValidState(n, i + 1, j + 1)) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= kModulo;
      }

      if (IsValidState(n, i + 1, j - 1)) {
        dp[i + 1][j - 1] += dp[i][j];
        dp[i + 1][j - 1] %= kModulo;
      }
    }
  }

  // for (int i = 0; i <= 2 * n; ++i) {
  //   for (int j = 0; j <= n; ++j) {
  //     std::cout << n << " " << i << " " << j << " " << IsValidState(n, i, j) << std::endl;
  //     // std::cout << dp[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  int64_t answer = 0;
  for (int i = 1; i < 2 * n; i += 2) {
    for (int j = 0; j <= n; ++j) {
      if (!IsValidState(n, i, j)) {
        continue;
      }

      answer += dp[i][j];
      answer %= kModulo;
    }
  }

  return answer;
}

int main() {
  int n; std::cin >> n;
  std::cout << Solve(n) << std::endl;

  return 0;
}