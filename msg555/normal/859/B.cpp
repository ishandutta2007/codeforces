#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;

  int result = 4 * N;
  for (int i = 1; i * i <= N; i++) {
    int j = (N + i - 1) / i;
    result = min(result, 2 * (i + j));
  }
  cout << result << '\n';

  return 0;
}