#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

constexpr int N = 3e5, B = __builtin_sqrt(N) / 3;

array<int, 2> knights[N];

struct Block {
  int tfirst;
  int64_t dtot, texit;
  vector<array<int, 2>> knights;

  void recalc() {
    tfirst = knights[0][0];
    int i;
    int idtot = 0, itexit = 0;
    for (i = 0; i < knights.size() && itexit < (int)2e9; ++i) {
      idtot += knights[i][1];
      itexit = max(itexit, knights[i][0]) + knights[i][1];
    }
    dtot = idtot, texit = itexit;
    for (; i < knights.size(); ++i) {
      dtot += knights[i][1];
    }
    texit += dtot - idtot;
  }

  int locate(int t) {
    return partition_point(knights.begin(), knights.end(), [&](const auto& k) { return k[0] <= t; }) - knights.begin();
  }
};

vector<Block> blocks;

int locate(int t) {
  return partition_point(blocks.begin(), blocks.end(), [&](const Block& b) { return b.tfirst <= t; }) - blocks.begin() - 1;
}

void insert(int t, int d) {
  static int cnt = 9999;
  cnt = min(cnt + 1, N);
  int b = __builtin_sqrt(cnt) / 2;
  if (blocks.empty()) {
    blocks.push_back({0, 0, 0, {{t, d}}});
    return blocks.back().recalc();
  }
  int i = max(locate(t), 0);
  int j = blocks[i].locate(t);
  blocks[i].knights.insert(blocks[i].knights.begin() + j, {t, d});
  if (blocks[i].knights.size() == 2 * b) {
    blocks.insert(blocks.begin() + i + 1, {{}});
    blocks[i + 1].knights.resize(b);
    copy(blocks[i].knights.begin() + b, blocks[i].knights.end(), blocks[i + 1].knights.begin());
    blocks[i].knights.resize(b);
    blocks[i + 1].recalc();
  }
  blocks[i].recalc();
}

void erase(int t, int d) {
  int i = locate(t);
  int j = blocks[i].locate(t) - 1;
  blocks[i].knights.erase(blocks[i].knights.begin() + j);
  if (blocks[i].knights.empty()) {
    blocks.erase(blocks.begin() + i);
  } else {
    blocks[i].recalc();
  }
}

int64_t query(int t) {
  int64_t ct = 0;
  int i, j;
  for (i = 0; i + 1 < blocks.size() && blocks[i + 1].tfirst <= t; ++i) {
    ct = max(ct + blocks[i].dtot, blocks[i].texit);
  }
  if (i < blocks.size()) {
    if (ct < (int)2e9) {
      int ict = ct;
      for (j = 0; ict < (int)2e9 && j < blocks[i].knights.size() && blocks[i].knights[j][0] <= t; ++j) {
        ict = max(ict, blocks[i].knights[j][0]) + blocks[i].knights[j][1];
      }
      ct = ict;
    }
    for (; j < blocks[i].knights.size() && blocks[i].knights[j][0] <= t; ++j) {
      ct += blocks[i].knights[j][1];
    }
  }
  return max(ct - t, {});
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, t, d; cin >> n;
  for (int i = 0; i < n; ++i) {
    char c; cin >> c >> t;
    if (c == '+') {
      cin >> d;
      knights[i] = {t, d};
      insert(t, d);
    } else if (c == '-') {
      erase(knights[t - 1][0], knights[t - 1][1]);
    } else {
      cout << query(t) << '\n';
    }
  }
}