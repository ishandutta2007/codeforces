#include <bits/stdc++.h>

using namespace std;

long long det(long long a, long long b, long long c, long long d) {
  return a * d - b * c;
}

long long mabs(long long a) {
  return a > 0 ? a : -a;
}

long long sqr(long long a) {
  return a * a;
}

struct Point {
  long long x;
  long long y;
  long long z;

  explicit Point(long long xx = 0, long long yy = 0, long long zz = 0):
    x(xx), y(yy), z(zz) {}

  void read() {
    cin >> x >> y >> z;
  }

  void print() const {
    cout << x << " " << y << " " << z << "\n";
  }

  Point operator*(const Point &p) const {
    return Point(det(y, z, p.y, p.z), -det(x, z, p.x, p.z), det(x, y, p.x, p.y));
  }

  long long scalar(const Point& p) const {
    return x * p.x + y * p.y + z * p.z;
  }

  Point operator-(const Point& p) const {
    return Point(x - p.x, y - p.y, z - p.z);
  }

  Point operator+(const Point& p) const {
    return Point(x + p.x, y + p.y, z + p.z);
  }

  long long dist(const Point& p) {
    return sqr(x - p.x) + sqr(y - p.y) + sqr(z - p.z);
  }

  bool operator==(const Point& p) const {
    return x == p.x && y == p.y && z == p.z;
  }

  Point apply(const vector<int>& p) const {
    Point res;
    vector<long long> t{x, y, z};
    res.x = t[p[0]];
    res.y = t[p[1]];
    res.z = t[p[2]];
    return res;
  }
};

bool isSquare(Point p1, Point p2, Point p3, Point p4) {
  if ((p2 - p1).scalar(p3 - p2) || (p3 - p2).scalar(p4 - p3) || (p4 - p3).scalar(p1 - p4) || (p4 - p1).scalar(p2 - p1))
    return false;
  if (p1 == p2 || p2 == p3 || p3 == p4)
    return false;
  long long d = p1.dist(p2);
  if (p2.dist(p3) != d || p3.dist(p4) != d || p4.dist(p1) != d)
    return false;
  if (p1.dist(p3) != 2 * d || p2.dist(p4) != 2 * d)
    return false;
  return true;
}

vector<int> matches(const Point &have, const Point& want) {
  vector<int> p{0, 1, 2};
  do {
    if (have.apply(p) == want)
      return p;
  } while(next_permutation(p.begin(), p.end()));
  return vector<int>();
}

int main() {
  ios_base::sync_with_stdio(0);
  int n = 8;
  vector<Point> p(n);
  for (int i = 0; i < n; i++)
    p[i].read();
  for (int mask = 0; mask < (1 << 8); mask++) {
    if (__builtin_popcount(mask) != 4)
      continue;
    vector<int> here;
    for (int i = 0; i < 8; i++)
      if (mask & (1 << i))
        here.push_back(i);
    for (int rep = 0; rep < 24; rep++) {
      vector<int> p1{0, 1, 2};
      for (int k = 0; k < 1; k++) {
        vector<int> p2{0, 1, 2};
        do {
          vector<int> p3{0, 1, 2};
          do {
            vector<int> p4{0, 1, 2};
            do {
              Point pt1 = p[here[0]].apply(p1);
              Point pt2 = p[here[1]].apply(p2);
              Point pt3 = p[here[2]].apply(p3);
              Point pt4 = p[here[3]].apply(p4);
              if (!isSquare(pt1, pt2, pt3, pt4))
                continue;
              Point norm = (pt2 - pt1) * (pt4 - pt1);
              long long len = pt1.dist(pt2);
              long long a = (long long)(sqrt(len) + 1e-3);
              if (a * a != len)
                continue;
              if (norm.x % a || norm.y % a || norm.z % a)
                continue;
              norm.x /= a;
              norm.y /= a;
              norm.z /= a;
              vector<Point> f{pt1, pt2, pt3, pt4};
              vector<bool> was(8, false);
              vector<vector<int>> ans(n);
              for (int x : here)
                was[x] = true;
              bool good = true;
              for (int i = 0; i < 4; i++) {
                Point want = f[i] + norm;
                bool ok = false;
                for (int j = 0; j < 8; j++) {
                  if (was[j])
                    continue;
                  vector<int> tmp = matches(p[j], want);
                  if (tmp.size()) {
                    was[j] = true;
                    ans[j] = tmp;
                    ok = true;
                    break;
                  }
                }
                good &= ok;
              }
              if (!good)
                continue;
              ans[here[0]] = p1;
              ans[here[1]] = p2;
              ans[here[2]] = p3;
              ans[here[3]] = p4;
              cout << "YES\n";
              for (int i = 0; i < 8; i++)
                p[i].apply(ans[i]).print();
              return 0;
            } while (next_permutation(p4.begin(), p4.end()));
          } while (next_permutation(p3.begin(), p3.end()));
        } while(next_permutation(p2.begin(), p2.end()));
      }
      next_permutation(here.begin(), here.end());
    }
  }
  cout << "NO\n";
  return 0;
}