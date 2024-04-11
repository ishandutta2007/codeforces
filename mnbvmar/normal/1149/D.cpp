#include <bits/stdc++.h>

using namespace std;

const int MaxN = 80;
const int kCompoSizeBound = 4;

int N, M, A, B;
vector<int> adj_cheap[MaxN];
vector<int> adj_expensive[MaxN];
vector<vector<int>> large_cheap_compos;
unsigned large_compo_mask[MaxN];
bool is_same_compo[MaxN][MaxN];

bool visited[MaxN];
vector<int> cur_component;

void DfsCheap(int v) {
  visited[v] = true;
  cur_component.push_back(v);
  for (int s : adj_cheap[v]) {
    if (!visited[s]) {
      DfsCheap(s);
    }
  }
}

void FindCheapComponents() {
  fill_n(visited, N + 1, false);

  for (int v = 1; v <= N; ++v) {
    if (!visited[v]) {
      cur_component.clear();
      DfsCheap(v);
      for (int a : cur_component) for (int b : cur_component) {
        is_same_compo[a][b] = true;
      }
      if ((int)cur_component.size() >= kCompoSizeBound) {
        const int compo_idx = (int)large_cheap_compos.size();
        large_cheap_compos.push_back(cur_component);
        for (int vert : cur_component) {
          large_compo_mask[vert] = 1U << compo_idx;
        }
      }
    }
  }
}

int32_t main() {
  cin >> N >> M >> A >> B;
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    if (c == A) {
      adj_cheap[u].push_back(v);
      adj_cheap[v].push_back(u);
    } else {
      adj_expensive[u].push_back(v);
      adj_expensive[v].push_back(u);
    }
  }

  FindCheapComponents();

  const int S = large_cheap_compos.size();

  using State = pair<int, unsigned>;
  using QueueElem = pair<int, State>;

  const State init_state{1, large_compo_mask[1]};
  
  priority_queue<QueueElem, vector<QueueElem>, greater<QueueElem>> que;
  que.emplace(0, init_state);

  const int kInfty = 1e9;
  vector<int> answers(N + 1, kInfty);
  vector<vector<int>> distances(N + 1, vector<int>(1 << S, kInfty));
  distances[1][large_compo_mask[1]] = 0;
  vector<vector<bool>> dij_visited(N + 1, vector<bool>(1 << S));

  while (!que.empty()) {
    auto [cost, state] = que.top();
    que.pop();
    auto &&[vert, mask] = state;

    if (dij_visited[vert][mask]) {
      continue;
    }
    dij_visited[vert][mask] = true;

    answers[vert] = min(answers[vert], cost);

    for (int s_cheap : adj_cheap[vert]) {
      const int new_dist = cost + A;
      if (distances[s_cheap][mask] > new_dist) {
        que.emplace(new_dist, State{s_cheap, mask});
        distances[s_cheap][mask] = new_dist;
      }
    }

    for (int s_large : adj_expensive[vert]) {
      if (is_same_compo[vert][s_large]) { continue; }
      if (large_compo_mask[s_large] & mask) { continue; }
      const unsigned new_mask = mask | large_compo_mask[s_large];
      const int new_dist = cost + B;
      if (distances[s_large][new_mask] > new_dist) {
        que.emplace(new_dist, State{s_large, new_mask});
        distances[s_large][new_mask] = new_dist;
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << answers[i] << (i == N ? '\n' : ' ');
  }
}