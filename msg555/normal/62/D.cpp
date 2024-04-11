#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const size_t MAXN = 110;
const size_t MAXM = 2010;

int N, M;
vector<int> E[MAXN];
int S[MAXM];
int T[MAXM];
int SOL[MAXM];

bool vis[MAXM];
bool dfsvis[MAXM];

int dfs(int u) {
  if (dfsvis[u]) return 0;
  dfsvis[u] = true;

  int result = 0;
  for (int ei : E[u]) {
    if (vis[ei]) continue;
    result += 1 + dfs(S[ei] + T[ei] - u);
  }
  return result;
}

bool solve(int ind, int u, bool on) {
  SOL[ind] = u;
  if (ind == M) {
    return !on;
  }

  for (int ei : E[u]) {
    if (vis[ei]) {
      continue;
    }

    int v = S[ei] + T[ei] - u; 
    if (on && v < T[ind]) {
      continue;
    }
    
    vis[ei] = true;
    memset(dfsvis, 0, sizeof(dfsvis));
    int res = dfs(v);
    if (res / 2 == M - ind - 1) {
      if (solve(ind + 1, v, on && v == T[ind])) {
        return true;
      }
    }
    vis[ei] = false;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  int s = -1;
  for (int i = -1; i < M; i++) {
    int t; cin >> t; --t;
    if (i >= 0) {
      S[i] = s; 
      T[i] = t;
      E[s].push_back(i);
      E[t].push_back(i);
    }
    s = t;
  }
  for (int i = 0; i < N; i++) {
    sort(E[i].begin(), E[i].end(), [](int ei, int ej) {
      return S[ei] + T[ei] < S[ej] + T[ej];
    });
  }

  if (!solve(0, S[0], true)) {
    cout << "No solution\n";
  } else {
    for (int i = 0; i <= M; i++) {
      if (i) cout << ' ';
      cout << SOL[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}