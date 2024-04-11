#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int A[310];
int B[310];

int P[310];

int find(int x) {
  return x == P[x] ? x : P[x] = find(P[x]);
}

bool merge(int x, int y) {
  int X = find(x);
  int Y = find(y);
  if(X == Y) return false;
  P[X] = P[Y] = P[x] = P[y] = (rand() % 2 ? X : Y);
  return true;
}

vector<pair<pair<int, int>, int> > res;

vector<int> E[310];

int solve(int u, int p, int d) {
  int amt = min(d, max(A[u] - B[u], 0));
  A[u] -= amt;

  int ip = res.size();
  for(int i = 0; amt < d && i < E[u].size(); i++) {
    int v = E[u][i];
    if(v == p) continue;

    int res = solve(v, u, d - amt);
    amt += res;
  }
  if(p != -1) {
    int qamt = min(A[u], amt);
    if(qamt > 0) {
      res.insert(res.begin() + ip, make_pair(make_pair(u, p), qamt));
    }
    if(qamt < amt) {
      res.push_back(make_pair(make_pair(u, p), amt - qamt));
    }
  }
  return amt;
}

int main() {
  int N, V, M;
  cin >> N >> V >> M;

  for(int i = 0; i < N; i++) {
    P[i] = i;
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> B[i];
  }

  for(int i = 0; i < M; i++) {
    int u, v; cin>> u >> v;
    u--; v--;
    if(merge(u, v)) {
      E[u].push_back(v);
      E[v].push_back(u);
    }
  }

  for(int i = 0; i < N; i++) {
    if(A[i] < B[i]) {
      A[i] += solve(i, -1, B[i] - A[i]);
    }
  }

  for(int i = 0; i < N; i++) {
    if(A[i] != B[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << res.size() << endl;
  for(int i = 0; i < res.size(); i++) {
    cout << res[i].first.first + 1 << ' ' << res[i].first.second + 1 << ' '
         << res[i].second << '\n';
  }

  return 0;
}