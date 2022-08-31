#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int N;
int A[50];


int memo[1 << 12][30];

bool solve(int m, int ones) {
  if(m == 0) return ones == 1;
  if(memo[m][ones] != -1) return memo[m][ones] == 1;

  int rt = -1;
  int NN = __builtin_popcount(m) + ones;
  for(int i = 0; i < N; i++) {
    if(m & 1 << i) {
      if(A[i] == NN) {
        rt = i;
      }
    }
  }
  if(rt == -1) return false;

  m ^= 1 << rt;
  NN -= ones + 1;
  vector<vector<bool> > DP(1 << NN, vector<bool>(30, false));

  DP[0][0] = true;
  for(int j = 0, ss = m; j < 1 << NN; j++, ss = ss - 1 & m) {
    for(int i = 0; i <= ones; i++) {
      if((j == (1 << NN) - 1 && i == ones) || !solve(ss ^ m, i)) continue;

      int all = ((1 << NN) - 1) ^ j;
      for(int k = all; ; k = k - 1 & all) {
        for(int a = i; a <= ones; a++) {
          if(DP[k][a - i]) {
            DP[k | j][a] = true;
          }
        }
        if(!k) break;
      }
    }
    if(!ss) break;
  }
  bool res = DP[(1 << NN) - 1][ones];
  memo[m | 1 << rt][ones] = res ? 1 : 0;
  return res;
}

int main() {
  cin >> N;
  int ones = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(A[i] == 1) {
      ones++;
      N--;
      i--;
    }
  }

  memset(memo, -1, sizeof(memo));
  if(ones < N) {
    cout << "NO" << endl;
  } else if (solve((1 << N) - 1, ones)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}