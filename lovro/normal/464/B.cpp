#define NDEBUG
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> inline T sqr(const T a) { return a*a; }
typedef long long int64;
#define ALL(x) (x).begin(), (x).end()

struct Point {
  int x[3];
};

vector<Point> pts(8);

bool check() {
  int64 a = -1;
  for (int i=0; i<8; ++i) {
    static vector<int64> dists;
    dists.clear();
    for (int j=0; j<8; ++j) {
      if (i != j) {
        int64 dist = 0;
        for (int k=0; k<3; ++k) {
          dist += sqr<int64>(pts[i].x[k] - pts[j].x[k]);
        }
        dists.push_back(dist);
      }
    }
    sort(ALL(dists));
    bool ok = dists[0] > 0;
    if (i == 0) {
      a = dists[0];
    }
    ok &= a == dists[0];
    int64 expected_mult[7] = {1, 1, 1, 2, 2, 2, 3};
    for (int j=1; j<7; ++j) {
      ok &= dists[0] * expected_mult[j] == dists[j];
    }
    if (!ok) {
      return false;
    }
  }
  return true;
}

void rek(int pos) {
  if (pos == 8) {
    if (check()) {
      cout << "YES\n";
      for (Point p : pts) {
        cout << p.x[0] << ' ' << p.x[1] << ' ' << p.x[2] << '\n';
      }
      exit(0);
    }
    return;
  }

  sort(pts[pos].x, pts[pos].x + 3);
  do {
    rek(pos + 1);
  } while (next_permutation(pts[pos].x, pts[pos].x + 3));
}

int main() {
  ios_base::sync_with_stdio(0);

  for (int i=0; i<8; ++i) {
    Point &p = pts[i];
    cin >> p.x[0] >> p.x[1] >> p.x[2];
  }

  rek(0);
  cout << "NO\n";
}