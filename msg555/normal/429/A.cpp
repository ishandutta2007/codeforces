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

#define MAXN 100010

vector<int> E[MAXN];

int A[MAXN];
int B[MAXN];

vector<int> C;

int solve(int x, int p, int b0, int b1) {
  int result = 0;
  if((A[x] ^ b0) != B[x]) {
    C.push_back(x);
    result++;
    b0 ^= 1;
  }
  for(int i = 0; i < E[x].size(); i++) {
    int v = E[x][i];
    if(v == p) continue;
    result += solve(v, x, b1, b0);
  }
  return result;
}

int main() {
  int N;
  cin >> N;
  for(int i = 1; i < N; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> B[i];
  }

  cout << solve(0, -1, 0, 0) << endl;
  sort(C.begin(), C.end());
  for(int i = 0; i < C.size(); i++) {
    cout << C[i] + 1 << '\n';
  }
  return 0;
}