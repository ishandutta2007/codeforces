#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>

constexpr int kMaxN = 400001;
constexpr int kMaxQ = 200001;
constexpr int kBufferSize = 16;
constexpr int kMaxValue = 300;
constexpr int kModulo = 1000 * 1000 * 1000 + 7;

constexpr int kMaxNumTreeNodes = 1048574;

struct Query {
  int l;
  int r;
  int value;
};

struct TreeNode {
  int delta;
  uint32_t sum;
};

struct VisitedNode {
  int v;
  int intersection;
};

int n;
int q;
int arr[kMaxN];
Query queries[kMaxQ];
char query_name[kBufferSize];

int arr_d[kMaxN];
int running_answers[kMaxQ];
TreeNode tree_nodes[kMaxNumTreeNodes];

std::vector<VisitedNode> visited_tree_nodes[kMaxQ];
std::vector<VisitedNode> visited_tree_leaves[kMaxQ];

void ReadInput() {
  scanf("%d%d", &n, &q);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    arr_d[i] = 0;
  }

  for (int i = 0; i < q; ++i) {
    scanf("%s%d%d", query_name, &queries[i].l, &queries[i].r);

    if (query_name[0] == 'T') { // TOTIENT
      queries[i].value = -1;
      running_answers[i] = 1;
    } else {
      scanf("%d", &queries[i].value);
      running_answers[i] = -1;
    }
  }
}

bool IsPrime(int x) {
  if (x < 2) {
    return false;
  }

  for (int d = 2; d * d <= x; ++d) {
    if (x % d == 0) {
      return false;
    }
  }

  return true;
}

int GetPrimeDegree(int x, int p) {
  int result = 0;
  while (x % p == 0) {
    x /= p;
    ++result;
  }

  return result;
}

int BinaryPower(int x, int power) {
  int result = 1;
  int64_t acc = x;
  while (power) {
    if (power & 1) {
      result = (acc * result) % kModulo;
    }

    acc = (acc * acc) % kModulo;
    power >>= 1;
  }

  return result;
}

int g_visit_nodes_tree_query_id;
int g_visit_nodes_tree_query_l;
int g_visit_nodes_tree_query_r;

void VisitNodesTree(int v, int l, int r) {
  int intersection_l = std::max(l, g_visit_nodes_tree_query_l);
  int intersection_r = std::min(r, g_visit_nodes_tree_query_r);
  int intersection = intersection_r - intersection_l + 1;

  if (l >= g_visit_nodes_tree_query_l && r <= g_visit_nodes_tree_query_r) {
    visited_tree_leaves[g_visit_nodes_tree_query_id].push_back(
        {v, intersection});
    return;
  }

  int m = (l + r) / 2;
  if (g_visit_nodes_tree_query_l <= m) {
    VisitNodesTree(2 * v, l, m);
  }
  if (m + 1 <= g_visit_nodes_tree_query_r) {
    VisitNodesTree(2 * v + 1, m + 1, r);
  }

  visited_tree_nodes[g_visit_nodes_tree_query_id].push_back(
      {v, intersection});
}

void BuildTree(int v, int l, int r) {
  tree_nodes[v].delta = 0;
  tree_nodes[v].sum = 0;

  if (l == r) {
    tree_nodes[v].delta = arr_d[l - 1];
    return;
  }

  int m = (l + r) / 2;
  BuildTree(2 * v, l, m);
  BuildTree(2 * v + 1, m + 1, r);

  tree_nodes[v].sum = 2 * (tree_nodes[2 * v].delta + tree_nodes[2 * v].sum / 2 + tree_nodes[2 * v + 1].delta + tree_nodes[2 * v + 1].sum / 2);
  if (tree_nodes[v].sum) {
    tree_nodes[v].sum |= 1;
  }
}

void AddTree(int query_id, int delta) {
  int query_l = queries[query_id].l;
  int query_r = queries[query_id].r;

  for (const auto& visited_node : visited_tree_leaves[query_id]) {
    auto& tree_node = tree_nodes[visited_node.v];
    tree_node.delta += delta;
  }

  for (const auto& visited_node : visited_tree_nodes[query_id]) {
    auto& tree_node = tree_nodes[visited_node.v];
    tree_node.sum =
        ((static_cast<int64_t>(visited_node.intersection) * delta + tree_node.sum / 2) % (kModulo - 1) << 1) | 1;
  }
}

int64_t SumTree(int query_id, bool* greater_than_zero) {
  int query_l = queries[query_id].l;
  int query_r = queries[query_id].r;

  int64_t result = 0;
  *greater_than_zero = false;
  for (const auto& visited_node : visited_tree_leaves[query_id]) {
    const auto& tree_node = tree_nodes[visited_node.v];

    result += static_cast<int64_t>(visited_node.intersection) * tree_node.delta;
    result += (tree_node.sum >> 1ll);
    *greater_than_zero |= (tree_node.sum & 1ll);
  }

  for (const auto& visited_node : visited_tree_nodes[query_id]) {
    const auto& tree_node = tree_nodes[visited_node.v];

    result += static_cast<int64_t>(visited_node.intersection) * tree_node.delta;
  }

  *greater_than_zero |= (result > 0);

  return result;
}

void PrepareVisitedTreeNodesForQueries() {
  for (int i = 0; i < q; ++i) {
    const auto& query = queries[i];

    g_visit_nodes_tree_query_id = i;
    g_visit_nodes_tree_query_l = query.l;
    g_visit_nodes_tree_query_r = query.r;
    VisitNodesTree(1, 1, n);
  }
}

void UpdateRunningAnswers(int p) {
  for (int i = 0; i < n; ++i) {
    arr_d[i] = GetPrimeDegree(arr[i], p);
  }

  BuildTree(1, 1, n);

  for (int i = 0; i < q; ++i) {
    const auto& query = queries[i];
    if (query.value != -1) {
      int d = GetPrimeDegree(query.value, p);
      if (d) {
        AddTree(i, d);
      }
    } else {
      bool greater_than_zero = false;
      int64_t s = SumTree(i, &greater_than_zero);
      if (greater_than_zero) {
        s = (s + kModulo - 2) % (kModulo - 1);
        int m = (static_cast<int64_t>(p - 1) * BinaryPower(p, s)) % kModulo;
        running_answers[i] = (static_cast<int64_t>(m) * running_answers[i]) % kModulo;
      }
    }
  }
}

void WriteOutput() {
  for (int i = 0; i < q; ++i) {
    if (queries[i].value == -1) {
      printf("%d\n", running_answers[i]);
    }
  }
}

void Solve() {
  ReadInput();

  PrepareVisitedTreeNodesForQueries();

  for (int p = 2; p <= kMaxValue; ++p) {
    if (!IsPrime(p)) {
      continue;
    }

    UpdateRunningAnswers(p);
  }

  WriteOutput();
}

int main() {
  Solve();
  return 0;
}