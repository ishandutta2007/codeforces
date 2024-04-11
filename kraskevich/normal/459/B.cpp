#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  map<int, long long> cnt;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  cout << cnt.rbegin()->first - cnt.begin()->first << " ";
  if (cnt.size() == 1) {
    long long s = cnt.begin()->second;
    cout << s * (s - 1) / 2;
    return 0;
  }
  long long s1 = cnt.rbegin()->second;
  long long s2 = cnt.begin()->second;
  cout << s1 * s2;
  return 0;
}