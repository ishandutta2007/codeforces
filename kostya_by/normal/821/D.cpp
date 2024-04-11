#include <bits/stdc++.h>

using namespace std;

const int kMaxK = 10001;
const int kMaxN = 3 * kMaxK;

struct Ceil {
  int r;
  int c;
  int id;
};

struct Edge {
  int to;
  int cost;
};

int n;
int m;
int k;
Ceil lighten_ceils[kMaxK];

int d[kMaxN];
vector<Edge> adjacent_edges[kMaxN];

void AddEdge(int node_a, int node_b, int cost) {
  adjacent_edges[node_a].push_back({node_b, cost});
  adjacent_edges[node_b].push_back({node_a, cost});
}

void BuildAdjacentHorizonatalEdges() {
  sort(lighten_ceils, lighten_ceils + k, [](const Ceil& a, const Ceil& b) {
    return make_pair(a.r, a.c) < make_pair(b.r, b.c);
  });

  for (int i = 1; i < k; ++i) {
    const Ceil& ceil_a = lighten_ceils[i - 1];
    const Ceil& ceil_b = lighten_ceils[i];

    if (ceil_a.r == ceil_b.r && ceil_a.c + 1 == ceil_b.c) {
      AddEdge(ceil_a.id, ceil_b.id, 0);
    }
  }
}

void SwapAllCeilCoordinates() {
  for (int i = 0; i < k; ++i) {
    Ceil& ceil = lighten_ceils[i];
    swap(ceil.r, ceil.c);
  }
}

void Solve() {
  scanf("%d%d%d", &n, &m, &k);
  bool have_dst = false;
  for (int i = 0; i < k; ++i) {
    Ceil& ceil = lighten_ceils[i];
    scanf("%d%d", &ceil.r, &ceil.c);

    --ceil.r;
    --ceil.c;
    ceil.id = i;
  }

  BuildAdjacentHorizonatalEdges();
  SwapAllCeilCoordinates();
  BuildAdjacentHorizonatalEdges();
  SwapAllCeilCoordinates();

  const auto row_node_id = [](int r) {
    return k + r;
  };

  const auto col_node_id = [](int c) {
    return k + n + c;
  };

  for (int i = 0; i < k; ++i) {
    const Ceil& ceil = lighten_ceils[i];

    int ceil_id = lighten_ceils[i].id;

    if (ceil.r) {
      AddEdge(ceil.id, row_node_id(ceil.r) - 1, 1);
    }
    AddEdge(ceil.id, row_node_id(ceil.r), 1);
    if (ceil.r + 1 < n) {
      AddEdge(ceil.id, row_node_id(ceil.r) + 1, 1);
    }

    if (ceil.c) {
      AddEdge(ceil.id, col_node_id(ceil.c) - 1, 1);
    }
    AddEdge(ceil.id, col_node_id(ceil.c), 1);
    if (ceil.c + 1 < m) {
      AddEdge(ceil.id, col_node_id(ceil.c) + 1, 1);
    }
  }

  int nodes_num = k + n + m;
  fill(d, d + nodes_num, -1);
  assert(lighten_ceils[0].r + lighten_ceils[0].c == 0);
  int start_node_id = lighten_ceils[0].id;
  d[start_node_id] = 0;

  deque<int> dq;
  dq.push_front(start_node_id);
  while (!dq.empty()) {
    int node_id = dq.front();
    dq.pop_front();

    for (const Edge& edge : adjacent_edges[node_id]) {
      if (d[edge.to] == -1) {
        d[edge.to] = d[node_id] + edge.cost;
        if (edge.cost) {
          dq.push_back(edge.to);
        } else {
          dq.push_front(edge.to);
        }
      }
    }
  }

  int answer = -1;
  const auto update_answer = [&answer](int value) {
    if (answer == -1 || answer > value) {
      answer = value;
    }
  };

  for (int i = 0; i < k; ++i) {
    const Ceil& ceil = lighten_ceils[i];
    if (ceil.r + ceil.c == n + m - 2 && d[ceil.id] != -1) {
      update_answer(d[ceil.id] / 2);
      answer = d[ceil.id] / 2;
    }
  }

  int last_row_id = row_node_id(n - 1);
  if (d[last_row_id] != -1) {
    update_answer((d[last_row_id] + 1) / 2);
  }

  int last_col_id = col_node_id(m - 1);
  if (d[last_col_id] != -1) {
    update_answer((d[last_col_id] + 1) / 2);
  }

  printf("%d\n", answer);
}

int main() {
  Solve();

  return 0;
}