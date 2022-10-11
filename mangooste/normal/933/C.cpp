#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

struct line {
  int A, B, C;
  line(int A = 0, int B = 0, int C = 0) : A(A), B(B), C(C) {}
};

struct pointd {
  double x, y;
  pointd(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

bool operator == (pointd &a, pointd &b) {
  return abs(a.x - b.x) < 1e-8 && abs(a.y - b.y) < 1e-8;
}

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct circle {
  point o;
  int r;
  circle(point o = point(), int r = 0) : o(o), r(r) {}
};

int n;
vector<circle> a;
vector<vector<pair<pointd, pointd>>> ints;

int sqr(int x) {
  return x * x;
}

int dist(point a, point b) {
  return sqr(a.x - b.x) + sqr(a.y - b.y);
}

bool intersect(circle a, circle b) {
  if (a.r < b.r) {
    swap(a, b);
  }
  if (dist(a.o, b.o) >= sqr(a.r)) {
    return dist(a.o, b.o) < sqr(a.r + b.r);
  } else if (dist(a.o, b.o) > sqr(a.r - b.r)) {
    return true;
  } else {
    return false;
  }
}

bool with(circle a, circle b) {
  if (a.r < b.r) {
    swap(a, b);
  }
  if (dist(a.o, b.o) >= sqr(a.r)) {
    return dist(a.o, b.o) == sqr(a.r + b.r);
  } else {
    return dist(a.o, b.o) == sqr(a.r - b.r);
  }
}

pair<pointd, pointd> get_intersect(double r, line ln) {
  double a = ln.A, b = ln.B, c = ln.C;
  double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
  double d = r * r - c * c / (a * a + b * b);
  double mult = sqrt(d / (a * a + b * b));
  pointd A, B;
  A.x = x0 + b * mult;
  B.x = x0 - b * mult;
  A.y = y0 - a * mult;
  B.y = y0 + a * mult;
  return make_pair(A, B);
}

pair<pointd, pointd> get_intersect(circle a, circle b) {
  b.o.x -= a.o.x;
  b.o.y -= a.o.y;
  line ln = line(-2 * b.o.x, -2 * b.o.y, sqr(b.o.x) + sqr(b.o.y) + sqr(a.r) - sqr(b.r));
  pair<pointd, pointd> cur = get_intersect(1.0 * a.r, ln);
  cur.first.x += 1.0 * a.o.x;
  cur.first.y += 1.0 * a.o.y;
  cur.second.x += 1.0 * a.o.x;
  cur.second.y += 1.0 * a.o.y;
  if (cur.first.x > cur.second.x || (abs(cur.first.x - cur.second.x) < 1e-8 && cur.first.y > cur.second.y)) {
    swap(cur.first, cur.second);
  }
  return cur;
}

bool equal(pair<pointd, pointd> a, pair<pointd, pointd> b) {
  return abs(a.first.x - b.first.x) < 1e-8
      && abs(a.first.y - b.first.y) < 1e-8
      && abs(a.second.x - b.second.x) < 1e-8
      && abs(a.second.y - b.second.y) < 1e-8;
}

bool check4() {
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (intersect(a[i], a[j])) {
        ok = false;
      }
    }
  }
  ok &= (with(a[0], a[1]) + with(a[0], a[2]) + with(a[1], a[2]) < 3);
  if (with(a[0], a[1]) && with(a[0], a[2]) && with(a[1], a[2])) {
    if (equal(ints[0][1], ints[0][2]) && equal(ints[0][1], ints[1][2])) {
      ok = true;
    }
  }
  return ok;
}

bool check5() {
  bool fnd = false;
  if (with(a[0], a[1]) && with(a[0], a[2]) && with(a[1], a[2])) {
    fnd = true;
  }
  for (int i = 0; i < n && !fnd; i++) {
    swap(a[0], a[i]);
    if ((with(a[0], a[1]) + with(a[0], a[2]) < 2) && !intersect(a[0], a[1]) && !intersect(a[0], a[2]) && intersect(a[1], a[2])) {
      fnd = true;
    }
    swap(a[0], a[i]);
  }
  return fnd;
}

bool check6() {
  bool fnd = false;
  vector<int> inds = {0, 1, 2};
  do {
    if (intersect(a[inds[0]], a[inds[1]]) && intersect(a[inds[1]], a[inds[2]]) && !intersect(a[inds[0]], a[inds[2]]) && !with(a[inds[0]], a[inds[2]])) {
      fnd = true;
    }
    if (with(a[inds[0]], a[inds[1]]) && with(a[inds[0]], a[inds[2]]) && intersect(a[inds[1]], a[inds[2]])) {
      fnd = true;
    }
  } while (next_permutation(inds.begin(), inds.end()) && !fnd);
  fnd |= (equal(ints[0][1], ints[0][2]));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int z = 0;
      while (z == i || z == j) {
        z++;
      }
      if (with(a[i], a[j]) && ((ints[z][i].first == ints[i][j].first) || (ints[z][i].second == ints[i][j].first))) {
        fnd = true;
      }
    }
  }
  return fnd;
}

bool check7() {
  bool fnd = false;
  vector<int> inds = {0, 1, 2};
  do {
    if (intersect(a[inds[0]], a[inds[1]]) && intersect(a[inds[1]], a[inds[2]]) && !intersect(a[inds[0]], a[inds[2]]) && with(a[inds[0]], a[inds[2]])) {
      fnd = true;
    }
  } while (next_permutation(inds.begin(), inds.end()) && !fnd);
  if (fnd) {
    return true;
  }
  if (!intersect(a[0], a[1]) || !intersect(a[1], a[2]) || !intersect(a[0], a[2])) {
    return false;
  }
  vector<pointd> pts;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        pts.push_back(ints[i][j].first);
        pts.push_back(ints[i][j].second);
      }
    }
  }
  fnd = false;
  for (auto p : pts) {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          ok &= (ints[i][j].first == p || ints[i][j].second == p);
        }
      }
    }
    fnd |= ok;
  }
  return fnd;
}

void Main() {
  cin >> n;
  a.resize(n);
  for (auto &el : a) {
    cin >> el.o.x >> el.o.y >> el.r;
  }
  if (n == 1) {
    cout << "2\n";
    return;
  }
  if (n == 2) {
    if (intersect(a[0], a[1])) {
      cout << "4\n";
    } else {
      cout << "3\n";
    }
    return;
  }
  ints.resize(n, vector<pair<pointd, pointd>>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        ints[i][j] = get_intersect(a[i], a[j]);
      }
    }
  }
  if (check4()) {
    cout << "4\n";
    return;
  }
  if (check5()) {
    cout << "5\n";
    return;
  }
  if (check6()) {
    cout << "6\n";
    return;
  }
  if (check7()) {
    cout << "7\n";
    return;
  }
  cout << "8\n";
}