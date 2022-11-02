#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum += min(n, i + 2) * a[i];
  cout << sum;
  return 0;
}