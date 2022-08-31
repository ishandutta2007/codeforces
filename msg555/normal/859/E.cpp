#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define MOD 1000000007

vector<int> A;
vector<vector<int> > RA;
vector<int> vis;
int tmr;

int search(int x) {
  int res = 1;
  vis[x] = true;
  while (RA[x].size() == 1) {
    res++;
    x = RA[x][0];
    vis[x] = tmr++;
  }
  for (auto y : RA[x]) {
    res += search(y);
  }
  return res;
}

int main() {
  int N; cin >> N;

  A = vector<int>(2 * N, -1);
  for (int i = 0; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    A[u] = v;
  }

  RA = vector<vector<int> >(2 * N);
  for (int i = 0; i < A.size(); i++) {
    if (A[i] != -1) {
      RA[A[i]].push_back(i);
    }
  }

  long long result = 1;

  tmr = 1;
  vis = vector<int>(2 * N, 0);
  for (int i = 0; i < 2 * N; i++) {
    if (A[i] == -1) {
      result = (result * search(i)) % MOD;
    }
  }

  for (int i = 0; i < 2 * N; i++) {
    if (vis[i]) {
      continue;
    }
    int start_tmr = tmr;

    int x = i;
    int sz = 0;
    while (vis[x] == 0) {
      vis[x] = tmr++;
      x = A[x];
    }
    if (vis[x] >= start_tmr && tmr - vis[x] > 1) {
      result = (result * 2) % MOD;
    }
  }

  cout << result << endl;
  return 0;
}