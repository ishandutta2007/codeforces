#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

int E[1010];
int RE[1010];

int main() {
  int N, x;
  cin >> N >> x;
  x--;

  memset(RE, -1, sizeof(RE));
  for(int i = 0; i < N; i++) {
    cin >> E[i];
    if(--E[i] != -1) {
      RE[E[i]] = i;
    }
  }

  int ln = 1;
  for(; E[x] != -1; x = E[x]) {
    ln++;
  }

  vector<int> DP(N + 1, false);
  DP[ln] = 1;
  for(int i = 0; i < N; i++) {
    if(RE[i] != -1) continue;

    int y = i;
    int ln = 1;
    for(; E[y] != -1; y = E[y]) {
      ln++;
    }
    if(x == y) continue;

    for(int i = N; i >= ln; i--) {
      DP[i] |= DP[i - ln];
    }
  }

  for(int i = 1; i <= N; i++) {
    if(DP[i]) {
      cout << i << endl;
    }
  }
  return 0;
}