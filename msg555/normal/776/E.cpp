#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MOD 1000000007

/*
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int f(int n) {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    if (gcd(i, n) == 1) {
      result++;
    }
  }
  return result;
}

int g(int n) {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      result += f(n / i);
    }
  }
  return result;
}
*/

long long f(long long N) {
  vector<pair<long long, int> > F;
  for (long long x = 2; x * x <= N; x++) {
    if (N % x) {
      continue;
    }
    int cnt = 1;
    for (N /= x; N % x == 0; ) {
      N /= x;
      ++cnt;
    }
    F.push_back(make_pair(x, cnt));
  }
  if (N > 1) {
    F.push_back(make_pair(N, 1));
  }

  long long result = 1;
  for (auto i : F) {
    result *= i.first - 1;
    for (int j = 1; j < i.second; j++) {
      result *= i.first;
    }
  }

  return result;
}

int main() {
/*
  for (int i = 1; i < 40; i++) {
    cout << i << " " << f(i) << " " << g(i) << "\n";
  }
*/

  long long N, K;
  cin >> N >> K;

  while (K >= 1 && N > 1) {
    N = f(N);
    K -= 2;
  }

  cout << N % MOD << endl;

  return 0;
}