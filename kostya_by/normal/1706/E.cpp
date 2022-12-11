#include <iostream>
#include <utility>
#include <vector>

static constexpr int kMaxN = 100001;
static constexpr int kMaxM = 200001;
static constexpr int kMaxQ = 200001;

struct Node {
  Node* lchild;
  Node* rchild;
  int persistence_id;

  // {min_set_id, max_set_id}
  std::pair<int, int> d;
};

int n, m, q;
std::pair<int, int> edges[kMaxM];
std::pair<int, int> queries[kMaxQ];

Node tree[kMaxN * 80];

int next_node_id;
int next_persistence_id;
Node* persistent_tree_roots[kMaxM];

int set_ids[kMaxN];
std::vector<int> inv_idx_set_ids[kMaxN];

Node* GetNextNode() {
  Node* next_node = &tree[next_node_id++];

  next_node->lchild = nullptr;
  next_node->rchild = nullptr;
  next_node->persistence_id = next_persistence_id;
  next_node->d = {-1, -1};

  return next_node;
}

Node* BuildTree(int l, int r) {
  Node* node = GetNextNode();
  node->d = {l, r};

  if (l == r) {
    return node;
  }

  int m = (l + r) / 2;
  node->lchild = BuildTree(l, m);
  node->rchild = BuildTree(m + 1, r);

  return node;
}

std::pair<int, int> MergeNodeData(const std::pair<int, int>& ld,
                                  const std::pair<int, int>& rd) {
  std::pair<int, int> result;

  result.first = std::min(ld.first, rd.first);
  result.second = std::max(ld.second, rd.second);

  return result;
}

Node* UpdateTree(Node* node, int l, int r, int pos, int set_id) {
  Node* new_node = node;
  if (node->persistence_id < next_persistence_id) {
    new_node = GetNextNode();
    new_node->lchild = node->lchild;
    new_node->rchild = node->rchild;
    new_node->persistence_id = next_persistence_id;
  }

  if (l == r) {
    new_node->d = {set_id, set_id};
    return new_node;
  }

  int m = (l + r) / 2;
  if (pos <= m) {
    new_node->lchild = UpdateTree(node->lchild, l, m, pos, set_id);
  } else {
    new_node->rchild = UpdateTree(node->rchild, m + 1, r, pos, set_id);
  }

  new_node->d = MergeNodeData(new_node->lchild->d, new_node->rchild->d);
  return new_node;
}

std::pair<int, int> QueryTree(Node* node, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    return node->d;
  }

  int m = (l + r) / 2;
  if (qr <= m) {
    return QueryTree(node->lchild, l, m, ql, qr);
  } else if (m < ql) {
    return QueryTree(node->rchild, m + 1, r, ql, qr);
  } else {
    return MergeNodeData(QueryTree(node->lchild, l, m, ql, m),
                         QueryTree(node->rchild, m + 1, r, m + 1, qr));
  }
}

void SolveTestCase(int test_case_id) {
  std::cin >> n >> m >> q;

  for (int i = 0; i < m; ++i) {
    std::cin >> edges[i].first >> edges[i].second;
    --edges[i].first;
    --edges[i].second;
  }

  for (int i = 0; i < q; ++i) {
    std::cin >> queries[i].first >> queries[i].second;
    --queries[i].first;
    --queries[i].second;
  }

  for (int i = 0; i < n; ++i) {
    set_ids[i] = i;
    inv_idx_set_ids[i] = {i};
  }

  next_node_id = 0;
  next_persistence_id = 0;

  persistent_tree_roots[0] = BuildTree(0, n - 1);
  for (int i = 0; i < m; ++i) {
    int a = edges[i].first;
    int b = edges[i].second;

    int set_id_a = set_ids[a];
    int set_id_b = set_ids[b];

    if (set_id_a == set_id_b) {
      persistent_tree_roots[i + 1] = persistent_tree_roots[i];
      continue;
    }

    if (inv_idx_set_ids[set_id_a].size() > inv_idx_set_ids[set_id_b].size()) {
      std::swap(a, b);
      std::swap(set_id_a, set_id_b);
    }

    Node* persistent_tree_root = persistent_tree_roots[i];

    ++next_persistence_id;
    for (int c : inv_idx_set_ids[set_id_a]) {
      set_ids[c] = set_id_b;
      inv_idx_set_ids[set_id_b].push_back(c);

      persistent_tree_root =
          UpdateTree(persistent_tree_root, 0, n - 1, c, set_id_b);
    }

    inv_idx_set_ids[set_id_a].clear();

    persistent_tree_roots[i + 1] = persistent_tree_root;

    // std::cout << "Edge " << i << ": ";
    // for (int i = 0; i < n; ++i) {
    //   std::cout << set_ids[i] << " ";
    // }
    // std::cout << "\n";
    // std::cout << "      : ";
    // for (int i = 0; i < n; ++i) {
    //   std::cout << QueryTree(persistent_tree_root, 0, n - 1, i, i).first << "
    //   ";
    // }
    // std::cout << "\n";
  }
  // std::cout << "----- ----- -----\n";

  for (int i = 0; i < q; ++i) {
    int ll = queries[i].first;
    int rr = queries[i].second;
    if (ll == rr) {
      std::cout << "0 ";
      continue;
    }

    // std::cout << "Query " << ll << " " << rr << "\n";

    int l = 0;
    int r = m;
    while (l + 1 < r) {
      int mid = (l + r) / 2;

      auto d = QueryTree(persistent_tree_roots[mid], 0, n - 1, ll, rr);
      // std::cout << "... " << mid << " " << d.first << " " << d.second <<
      // "\n";

      if (d.first == d.second) {
        r = mid;
      } else {
        l = mid;
      }
    }

    std::cout << r << " ";
  }
  std::cout << "\n";
}

int main(int argc, char const* argv[]) {
  std::ios::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    SolveTestCase(i);
  }

  return 0;
}