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

  int result = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    result = max(result, x - 25);
  }
  cout << result << '\n';

  return 0;
}