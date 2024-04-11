#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int64;
#define MINUSONE(v) memset(v, -1, sizeof v)

const int MOD = 1000000007;
const int MAXN = 1000;
int memo[MAXN+1][MAXN+1];

int64 calc(int w, int k) {
  if (k == 0) return 1;
  if (w <= 0) return 0;

  if (memo[w][k] != -1) {
    return memo[w][k];
  }

  int64 ret = 0;
  for (int v=1; v<=w-2; ++v) {
    ret += (w-v-1) * calc(v, k-1);
  }
  ret %= MOD;
  return memo[w][k] = ret;
}

int main() {
  int x, y, k;
  cin >> x >> y >> k;
  MINUSONE(memo);
  cout << calc(x, k) * calc(y, k) % MOD << endl;
  return 0;
}