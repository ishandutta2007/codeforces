#include <iostream>
#include <vector>
#include <array>
#include <ctime>
#include <cstring>

using namespace std;

constexpr int M = 6, D = 3, A = 201, P[2]{25, 15};

array<int, 4> res[M][2 * D + 1][A][A];

void relax(int m, int d, int a, int b, int da, int db) {
  int nd = d + 2 * (da > db) - 1;
  int na = a + da, nb = b + db;
  if (na >= A || nb >= A) {
    return;
  }
  auto& cur = res[m + 1][nd + D][na][nb];
  if (cur[0] != -1) {
    return;
  }
  cur = res[m][d + D][a][b];
  cur[0] += da > db;
  cur[1] += da < db;
  cur[2] = da;
  cur[3] = db;
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(res, -1, sizeof res);
  res[0][D][0][0] = {};
  for (int i = 0; i < M - 1; ++i)
  for (int d = -D + 1; d < D; ++d)
  for (int a = 0; a < A; ++a)
  for (int b = 0; b < A; ++b) if (res[i][d + D][a][b][0] != -1 && abs(d) + (i - abs(d)) / 2 != D)
  for (int d1 = 0; d1 + max(a, b) < A; ++d1) {
    relax(i, d, a, b, d1, max(P[i == M - 2], d1 + 2));
    relax(i, d, a, b, max(P[i == M - 2], d1 + 2), d1);
  }
//  cerr << "done" << clock() << "\n";
  int m; cin >> m;
  while (m--) {
    int a, b; cin >> a >> b;
    int mi = -1, maxd = -D - 1;
    for (int i = D; i < M; ++i)
    for (int d = maxd + 1; d <= D; ++d) if (abs(d) + (i - abs(d)) / 2 == D && res[i][d + D][a][b][0] != -1) {
      mi = i, maxd = d;
    }
    if (mi == -1) {
      cout << "Impossible\n";
      continue;
    }
    int i = mi, d = maxd;
    cout << res[i][d + D][a][b][0] << ':' << res[i][d + D][a][b][1] << '\n';
    vector<array<int, 2>> results;
    while (i) {
      results.push_back({res[i][d + D][a][b][2], res[i][d + D][a][b][3]});
      --i;
      d = d + 1 - 2 * (results.back()[0] > results.back()[1]);
      a -= results.back()[0];
      b -= results.back()[1];
    }
    for (int i = results.size(); i--; ) {
      cout << results[i][0] << ':' << results[i][1] << ' ';
    }
    cout << '\n';
  }
}