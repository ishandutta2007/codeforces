#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;

  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    C[x]++;
  }

  int result = 1;
  for (int x : C) {
    result += max(0, x - 1);
  }
  cout << result << endl;

  return 0;
}