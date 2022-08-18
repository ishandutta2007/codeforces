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

#define MAXN 1010

int A[MAXN];

int main() {
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int result = 0;
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    result += min(A[u], A[v]);
  }
  cout << result << endl;

  return 0;
}