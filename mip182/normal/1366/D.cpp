#pragma GCC optimize("O3")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

vector<int> primes(int n) {
  vector<int> p(n + 1, 0);
  vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    if (p[i] == 0) {
      p[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > p[i] || 1ll * x * i > n)
        break;
      p[x * i] = x;
    }
  }
  return p;
}

const int N = 5e6 + 10;
int a[N], b[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> p = primes(1e7);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int y = p[x];
    while (x % y == 0) {
      x /= y;
    }
    if (x == 1) {
      a[i] = b[i] = -1;
    }
    else {
      a[i] = y;
      b[i] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}