#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}

struct Point {
  int x, y;
};

struct Rect {
  int x1, y1, x2, y2;
};

bool inside(const Rect &r, const Point &p) {
  return p.x >= r.x1 && p.x <= r.x2 && p.y >= r.y1 && p.y <= r.y2;
}

bool solve() {
  int n;
  cin >> n;
  vector<Rect> rect(n);
  vector<Point> qpts;
  for (int i=0; i<n; ++i) {
    Rect &r = rect[i];
    cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    r.x1 *= 2; r.y1 *= 2;
    r.x2 *= 2; r.y2 *= 2;
    for (int dx=-1; dx<=1; ++dx) {
      for (int dy=-1; dy<=1; ++dy) {
        qpts.push_back((Point){r.x1 + dx, r.y1 + dy});
        qpts.push_back((Point){r.x2 + dx, r.y2 + dy});
      }
    }
  }

  Rect bbox = rect[0];
  for (int i=1; i<n; ++i) {
    const Rect &r = rect[i];
    makemin(bbox.x1, r.x1);
    makemax(bbox.x2, r.x2);
    makemin(bbox.y1, r.y1);
    makemax(bbox.y2, r.y2);
  }

  if (bbox.x2 - bbox.x1 != bbox.y2 - bbox.y1) {
    return false;
  }

  for (int i=0; i<(int)qpts.size(); ++i) {
    const Point &q = qpts[i];
    if (inside(bbox, q)) {
      bool ok = false;
      for (int j=0; j<n; ++j) {
        ok |= inside(rect[j], q);
      }
      if (!ok) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin.sync_with_stdio(0);

  cout << (solve() ? "YES" : "NO") << '\n';
  return 0;
}