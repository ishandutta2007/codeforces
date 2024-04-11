#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MINUSONE(v) memset(v, -1, sizeof v)

int k1, k2;
int memo[105][105][15][15];
int MOD = 100000000;

int calc(int n1, int n2, int x1, int x2) {
  if (n1 == 0 && n2 == 0) {
    return 1;
  }

  int &ret = memo[n1][n2][x1][x2];
  if (ret != -1) {
    return ret;
  }

  ret = 0;
  if (n1 > 0 && x1 < k1) {
    ret += calc(n1-1, n2, x1+1, 0);
  }
  if (n2 > 0 && x2 < k2) {
    ret += calc(n1, n2-1, 0, x2+1);
  }
  ret %= MOD;
  return ret;
}

int main() {
  cin.sync_with_stdio(0);

  int n1, n2;
  cin >> n1 >> n2 >> k1 >> k2;

  MINUSONE(memo);
  cout << calc(n1, n2, 0, 0) << endl;

  return 0;
}