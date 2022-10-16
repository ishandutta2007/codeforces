#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <bitset>
//#include <unordered_set>
//#include <set>

using namespace std;

constexpr int N = 18, H = 1 << 16;

vector<int> mc[N + 1][N + 1][N * N * 2 + 1];

//struct XYS {
//  int x, y, s;
//
//  XYS(int x, int y, int s): x{x}, y{y}, s{s} {
//  }
//
//  XYS(int xys): x{}, y{}, s{} {
//    s = xys % (N * N * 2), xys %= (N * N * 2);
//    s = xys % (N * N * 2), xys %= (N * N * 2);
//  }
//};

int compose(int x, int y) {
  return x | y * H;
}

array<int, 2> decompose(int xy) {
  return {xy % H, xy / H};
}

void uniq(vector<int>& mc, int n, int op, int cl, int s) {
  static bitset<45349632> bs;
  auto key = [](auto xy) {
    auto [x, y] = decompose(xy);
    int key = y / 6;
    key = key * (N * N * N * 2) + x / 3;
    return key;
  };
  mc.erase(remove_if(mc.begin(), mc.end(), [&](auto xy) {
    if (auto k = key(xy); bs[k]) {
      return 1;
    } else {
      bs[k] = 1;
      return 0;
    }
  }), mc.end());
  if (op < n && cl < n) {
    swap(mc, ::mc[op + 1][cl + 1][s]);
    mc.resize(::mc[op + 1][cl + 1][s].size());
    copy(::mc[op + 1][cl + 1][s].begin(), ::mc[op + 1][cl + 1][s].end(), mc.begin());
    ::mc[op + 1][cl + 1][s].clear();
  }
  for (auto xy: mc) {
    bs[key(xy)] = 0;
  }
}

int main() {
  int n; cin >> n;
  int N = n / 2;
  mc[1][0][1] = {compose(2, 2)};
  for (int op = 1; op <= N; ++op)
  for (int cl = 0; cl <= op; ++cl)
  for (int s = 1; s <= N * N * 2; ++s) {
    uniq(mc[op][cl][s], N, op, cl, s);
//    sort(mc[op][cl][s].begin(), mc[op][cl][s].end());
//    mc[op][cl][s].erase(unique(mc[op][cl][s].begin(), mc[op][cl][s].end()), mc[op][cl][s].end());
    for (auto xy: mc[op][cl][s]) {
      auto [x, y] = decompose(xy);
      y /= 2;
      auto bal = op - cl;
      if (op != N) {
        mc[op + 1][cl][s + bal * 2 + 1].push_back({compose(
          x + ((op + cl) * 2 + 1) * bal * 3 + (op + cl) * 3 + 2,
          y + bal * bal * 3 + bal * 3 + 1 << 1
        )});
      }
      if (op != cl) {
        --bal;
        mc[op][cl + 1][s + bal * 2 + 1].push_back({compose(
          x + ((op + cl) * 2 + 1) * bal * 3 + (op + cl) * 3 + 1,
          y + bal * bal * 3 + bal * 3 + 1 << 1 | 1
        )});
      }
    }
//    if (cl == op) {
//      cout << op << ' ' << mc[op][cl][s].size() << '\n';
//    }
  }
  long double X, Y; cin >> X >> Y;
  int op = N, cl = N;
  string ans;
  auto [x, y, s] = [&]() {
    for (int s = 1; s <= N * N * 2; ++s)
    for (auto xy: mc[op][cl][s]) {
      auto [cx, cy] = decompose(xy);
      cy /= 2;
      long double ox = cx, oy = cy;
      ox /= s * 3, oy /= s * 3;
      auto sqr = [](auto x) { return x * x; };
      if (sqr(ox - X) + sqr(oy - Y) < .9e-14) {
        return array{cx, cy, s};
      }
    }
    return array{-1, -1, -1};
  }();
//  cout << x << ' ' << y << ' ' << s << '\n';
  while (op) {
    for (auto xy: mc[op][cl][s]) if (auto [cx, cy] = decompose(xy); cx == x && cy / 2 == y) {
      auto bal = op - cl;
      if (~cy & 1) {
        ans += '(';
        --op;
        --bal;
        x -= ((op + cl) * 2 + 1) * bal * 3 + (op + cl) * 3 + 2;
        y -= bal * bal * 3 + bal * 3 + 1;
      } else {
        ans += ')';
        --cl;
        x -= ((op + cl) * 2 + 1) * bal * 3 + (op + cl) * 3 + 1;
        y -= bal * bal * 3 + bal * 3 + 1;
      }
      s -= bal * 2 + 1;
      break;
    }
  }
  cout << string(ans.rbegin(), ans.rend());
}