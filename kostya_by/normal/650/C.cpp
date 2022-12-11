#include <bits/stdc++.h>

using namespace std;

const int MAX_N_M = 1000100;
const int MAX_N = 4000400;

int n, m;
int a[MAX_N_M];

vector<int> graph[MAX_N];
int f[MAX_N];
int p[MAX_N];

pair<int, int> buffer[MAX_N_M];

int get(int i, int j) {
  return a[i * m + j];
}

vector<pair<int, int> > edges;

void add_edge(int u, int v) {
  edges.push_back(make_pair(u, v));
}

int get_prev(int v) {
  if (v == p[v]) {
    return v;
  }

  return p[v] = get_prev(p[v]);
}

int fun(int v) {
  if (f[v] != -1) {
    return f[v];
  }
  f[v] = 0;
  for (int u : graph[v]) {
    f[v] = max(f[v], fun(u) + 1);
  }

  return f[v];
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n * m; i++) {
    scanf("%d", &a[i]);
  }

  int h = n * m;

  memset(f, -1, sizeof(f));
  for (int i = 0; i < MAX_N; i++) {
    f[i] = -1;
    p[i] = i;
  }
  
  // rows
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      buffer[j] = make_pair(get(i, j), i * m + j);
    }

    sort(buffer, buffer + m);

    int previous_last_id = -1;
    int last_id = h++;
    add_edge(last_id, buffer[0].second);
    for (int j = 1; j < m; j++) {
      if (buffer[j - 1].first < buffer[j].first) {
        previous_last_id = last_id;
        last_id = h++;
      } else {
        int a = get_prev(buffer[j - 1].second);
        int b = get_prev(buffer[j].second);

        p[a] = b;
      }

      if (previous_last_id != -1) {
        add_edge(buffer[j].second, previous_last_id);
      }
      add_edge(last_id, buffer[j].second);
    }
  }

  // columns
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      buffer[i] = make_pair(get(i, j), i * m + j);
    }

    sort(buffer, buffer + n);

    int previous_last_id = -1;
    int last_id = h++;
    add_edge(last_id, buffer[0].second);
    for (int i = 1; i < n; i++) {
      if (buffer[i - 1].first < buffer[i].first) {
        previous_last_id = last_id;
        last_id = h++;
      } else {
        int a = get_prev(buffer[i - 1].second);
        int b = get_prev(buffer[i].second);

        p[a] = b;
      }

      if (previous_last_id != -1) {
        add_edge(buffer[i].second, previous_last_id);
      }
      add_edge(last_id, buffer[i].second);
    }
  }

  // compress graph
  for (int i = 0; i < edges.size(); i++) {
    int u = get_prev(edges[i].first);
    int v = get_prev(edges[i].second);

    graph[u].push_back(v);
  }

  // dp
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v = get_prev(i * m + j);
      int value = fun(v);
      printf("%d ", value / 2 + 1);
    }
    printf("\n");
  }
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}