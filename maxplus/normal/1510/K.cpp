#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr int N = 1e3, M = 2 * N;

int n;
int a[2 * N];

void op1(auto& a) {
  for (int i = 0; i < n; ++i) {
    swap(a[2 * i], a[2 * i + 1]);
  }
}

void op2(auto& a) {
  for (int i = 0; i < n; ++i) {
    swap(a[i], a[n + i]);
  }
}

int src[2 * N];
uint32_t ans = -1;

void solve(int parity) {
  for (int i = 0; i < 2 * n; ++i) {
    src[i] = a[i];
  }
  for (uint32_t its = n * 2, it = 0; it++ < its; ) {
    it + parity & 1? op1(src): op2(src);
    if (is_sorted(src, src + 2 * n)) {
      ans = min(ans, it);
      break;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  if (is_sorted(a, a + 2 * n)) {
    ans = 0;
  }
  solve(0);
  solve(1);
  cout << (int)ans;
}