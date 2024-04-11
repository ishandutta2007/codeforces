#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>

using namespace std;

int f3(int n) {
  return n * (n - 1) * (n - 2) / 6;
}

int main() {
  int K; cin >> K;
  int N = 3;
  while(f3(N + 1) <= K) N++;

  int MN = N * (N - 1) / 2;
  int TN = 100;

  vector<string> E(TN, string(TN, '0'));
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      E[i][j] = E[j][i] = '1';
    }
  }

  int GK = f3(N);
  for(int i = N; i < TN; i++) {
    for(int j = 0; j < N && GK + j <= K; j++) {
      E[i][j] = E[j][i] = '1';
      GK += j;
    }
  }

  cout << TN << endl;
  for(int i = 0; i < E.size(); i++) cout << E[i] << endl;
}