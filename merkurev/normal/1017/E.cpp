#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long int ll;

const int N = (int)1e5 + 100;

struct Point {
  long long x, y;
  Point() {}
  Point(long long _x, long long _y) : x(_x), y(_y) {}
  Point operator+(const Point &a) const { return Point(x + a.x, y + a.y); }
  Point operator-(const Point &a) const { return Point(x - a.x, y - a.y); }
  ll operator%(const Point &a) const { return x * a.x + y * a.y; }
  ll operator*(const Point &a) const { return x * a.y - y * a.x; }
  double length() { return sqrt(x * x + y * y); }
  long long len2() { return *this % *this; }
  bool operator<(const Point &a) const {
    return x < a.x || (x == a.x && y < a.y);
  }
  void scan() { scanf("%lld%lld", &x, &y); }
  void eprint() { eprintf("%lld %lld\n", x, y); }
};

Point minP;

bool cmpPoints(const Point &a, const Point &b) {
  Point v = a - minP;
  Point u = b - minP;
  if (v * u != 0) return v * u > 0;
  return v.length() < u.length();
}

vector<Point> graham(vector<Point> wall) {
  int n = (int)wall.size();
  minP = *min_element(wall.begin(), wall.end());
  sort(wall.begin(), wall.end(), cmpPoints);
  vector<Point> st(n);
  int r = 0;
  for (int i = 0; i < n; i++) {
    while (r > 1 && (st[r - 1] - st[r - 2]) * (wall[i] - st[r - 2]) <= 0) r--;
    st[r++] = wall[i];
  }
  st.resize(r);
  return st;
}

int n[2];
vector<Point> P[2];

void readP(int id) {
  P[id].resize(n[id]);
  for (int i = 0; i < n[id]; i++) P[id][i].scan();
  P[id] = graham(P[id]);

  eprintf("---\n");
  for (auto x : P[id]) x.eprint();
  eprintf("---\n");
}

const int SZ = 10 * N;
long long ar[SZ];
int z[SZ];

void putAr(int id, int &sz) {
  int psz = (int)P[id].size();
  for (int i = 0; i < psz; i++) {
    int ni = (i + 1) % psz;
    int pi = (i + psz - 1) % psz;
    ar[sz++] = (P[id][ni] - P[id][i]).len2();
    ar[sz++] = (P[id][ni] - P[id][i]) % (P[id][i] - P[id][pi]);
  }
}

void calcZ(int sz) {
  int wl = 0, wr = 0;
  for (int i = 1; i < sz; i++) {
    if (i < wr) z[i] = min(z[i - wl], wr - i);
    while (ar[z[i]] == ar[i + z[i]]) z[i]++;
    if (i + z[i] > wr) {
      wl = i;
      wr = i + z[i];
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n[0], &n[1]);
  readP(0);
  readP(1);

  if (P[0].size() != P[1].size()) {
    printf("NO\n");
    return 0;
  }

  int sz = 0;
  putAr(0, sz);
  int need = sz;
  //  ar[sz++] = 0;
  putAr(1, sz);
  putAr(1, sz);
  calcZ(sz);

  //  for (int i = 0; i < sz; i++) eprintf("%lld ", ar[i]);
  //  eprintf("\n");

  for (int i = need; i < sz; i++)
    if (z[i] >= need) {
      printf("YES\n");
      return 0;
    }
  printf("NO\n");

  return 0;
}