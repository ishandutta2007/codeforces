#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5;

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<long long> cnt(N);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector<long long> dp0(N);
  vector<long long> dp1(N);
  for (long long i = N - 2; i >= 1; i--) {
    dp0[i] = max(dp1[i + 1], dp0[i + 1]);
    dp1[i] = dp0[i + 1] + cnt[i] * i;
  }
  cout << max(dp0[1], dp1[1]);
  return 0;
}