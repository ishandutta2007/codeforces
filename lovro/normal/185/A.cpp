#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int64;

const int MOD = 1000000007;

int64 p2(int64 x) {
  if (x == 0) {
    return 1;
  }

  if (x%2 == 1) {
    return 2 * p2(x-1) % MOD;
  }
  int64 y = p2(x/2);
  return y * y % MOD;
}

int main() {
  cin.sync_with_stdio(0);

  int64 n;
  cin >> n;
  if (n == 0) {
    cout << "1\n";
    return 0;
  }
  
  cout << (p2(2*n-1) + p2(n-1)) % MOD << '\n';
  return 0;
}