#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
  int N, M, A, B;
  cin >> N >> M >> A >> B;

  int res = N * A;
  for(int i = 0; i <= 1000; i++) {
    res = min(res, i * B + max(0, N - i * M) * A);
  }
  cout << res << endl;

  return 0;
}