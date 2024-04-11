#include <bits/stdc++.h>

using namespace std;

vector<int> divs(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++)
    if (n % i == 0) {
      res.push_back(i);
      res.push_back(n / i);
    }
  return res;
}

long long res = -1;
long long n, m, k;

void upd1(long long kk) {
  long long k1 = kk;
  long long k2 = k - kk;
  if (k1 > 0 && k2 > 0)
    res = max(res, (n / k1) * (m / k2));
}

void upd2(long long kk) {
  long long k1 = k - kk;
  long long k2 = kk;
  if (k1 > 0 && k2 > 0)
    res = max(res, (n / k1) * (m / k2));
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> m >> k;
  k += 2;
  for (int d : divs(n))
    for (int j = -10; j <= 10; j++)
      upd1(d + j);
  for (int d : divs(m))
    for (int j = -10; j <= 10; j++)
      upd2(d + j);
  if (res == 0)
    res = -1;
  cout << res;

  return 0;
}