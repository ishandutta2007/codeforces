#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<int> f(11);
  long long ans = 0;
  for (char c : s) {
    int x = c - '0';
    vector<int> nf(11);
    for (int i = x + 1; i < 11; ++i) {
      nf[(i * (i - 1) / 2 + x + 10) % 11] += f[i];
    }
    if (x) nf[x]++;
    f.swap(nf);
    ans += accumulate(f.begin(), f.end(), 0);
  }
  cout << ans << '\n';
}