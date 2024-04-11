#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int n, k;
  string str;
  cin >> n >> k >> str;

  vector<int> pi(n);
  pi[0] = 0;
  for (int i=1; i<n; ++i) {
    int q = pi[i-1];
    while (q > 0 && str[q] != str[i]) {
      q = pi[q-1];
    }
    pi[i] = q + (str[q] == str[i]);
  }

  string ans;
  for (int i=1; i<=n; ++i) {
    long long minper = i - pi[i-1];
    if (k * minper > i) {
      ans += '0';
      continue;
    }

    int M = i / (k * minper);
    int rem = i - k * (M * minper);
    if (rem <= M * minper) {
      ans += '1';
    } else {
      ans += '0';
    }
  }
  cout << ans << '\n';
}