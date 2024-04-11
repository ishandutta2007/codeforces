#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2e5 + 100;

int stack_sizes[MaxN];
vector<int> adj[MaxN];
int N, M;

int vertex_group_idx[MaxN];
bool visited[MaxN];
int group_xor[MaxN];
vector<int> vertex_groups[MaxN];

void DfsMakeLayers(int vert) {
  visited[vert] = true;
  vector<int> seen_layers;
  for (int s : adj[vert]) {
    if (!visited[s]) {
      DfsMakeLayers(s);
    }
    seen_layers.push_back(vertex_group_idx[s]);
  }
  sort(seen_layers.begin(), seen_layers.end());
  seen_layers.resize(unique(seen_layers.begin(), seen_layers.end()) -
      seen_layers.begin());
  seen_layers.push_back(1e9);

  while (seen_layers[vertex_group_idx[vert]] == vertex_group_idx[vert]) {
    ++vertex_group_idx[vert];
  }
  const int group_id = vertex_group_idx[vert];
  group_xor[group_id] ^= stack_sizes[vert];
  vertex_groups[group_id].push_back(vert);
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    cin >> stack_sizes[i];
  }

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
  }

  for (int vert = 0; vert < N; ++vert) {
    if (!visited[vert]) {
      DfsMakeLayers(vert);
    }
  }

  if (count(group_xor, group_xor + N, 0) == N) {
    cout << "LOSE\n";
    return 0;
  }

  int last_idx = N;
  while (group_xor[last_idx] == 0)
    --last_idx;

  int touched_vertex = -1;
  for (int vert : vertex_groups[last_idx]) {
    if ((stack_sizes[vert] ^ group_xor[last_idx]) < stack_sizes[vert]) {
      touched_vertex = vert;
      break;
    }
  }

  assert(touched_vertex != -1);

  stack_sizes[touched_vertex] ^= group_xor[last_idx];
  group_xor[last_idx] = 0;

  for (int neigh : adj[touched_vertex]) {
    const int group_idx = vertex_group_idx[neigh];
    stack_sizes[neigh] ^= group_xor[group_idx];
    group_xor[group_idx] = 0;
  }

  assert(count(group_xor, group_xor + N, 0) == N);

  cout << "WIN\n";
  for (int i = 0; i < N; ++i)
    cout << stack_sizes[i] << " ";
  cout << "\n";
}