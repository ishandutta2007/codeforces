#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

struct Point {
  int x, y;
  Point operator+(const Point& a) const { Point p{x + a.x, y + a.y}; return p; }
  Point operator-(const Point& a) const { Point p{x - a.x, y - a.y}; return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  
  LL CrossProd(const Point& a) const { return x * a.y - y * a.x; }
  LL CrossProd(Point a, Point b) const { a -= *this; b -= *this; return a.CrossProd(b); }
  LL DotProd(const Point& a) const { return x * a.x + y * a.y; }
  friend ostream& operator<<(ostream& out, Point m);
  static bool LexCmp(const Point& a, const Point& b) {
    if (abs(a.x - b.x) != 0) { return a.x < b.x; }
    return a.y < b.y;
  }
};

ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.x << ", " << p.y << ")"; return out;
}

struct Polygon {
  vector<Point> pts;
  LL Area() { // positive for counterclockwise
    LL area = 0;
    for (int i = 0; i < SZ(pts); i++) {
      area += pts[i].CrossProd(pts[(i + 1) % SZ(pts)]);
    }
    return area;
  }
  void OrientCounterclockwise() {
    if (Area() < 0) { reverse(pts.begin(), pts.end()); }
  }
  int next(int a) {
    if (a + 1 < SZ(pts)) { return a + 1; }
    return 0;
  }
  // for square 34 
  //            12 holds one_way_hull = {{1,3,4},{1,2,4}}
  void MakeConvexHull() {
    vector<Point> one_way_hull[2];
    sort(pts.begin(), pts.end(), Point::LexCmp);
    for (int dir = -1; dir <= 1; dir += 2) {
      int hull_num = (dir + 1) / 2;
      auto& H = one_way_hull[hull_num];
      one_way_hull[hull_num].push_back(pts[0]);
      if (SZ(pts) > 1) { H.push_back(pts[1]); }
      for (int i = 2; i < SZ(pts); i++) {
        while (SZ(H) >= 2 &&
            dir * (pts[i] - H[SZ(H) - 2]).CrossProd(H.back() - H[SZ(H) - 2]) >= 0) {
          H.pop_back();
        }
        H.push_back(pts[i]);
      }
    }
    pts.clear();
    for (auto p : one_way_hull[1]) { pts.push_back(p); }
    for (int i = SZ(one_way_hull[0]) - 2; i >= 1; i--) {
      pts.push_back(one_way_hull[0][i]);
    }
  }
};


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N;
  Polygon poly;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    LL x, y;
    cin >> x >> y;
    poly.pts.PB(Point{x, y - x * x});
  }

  poly.MakeConvexHull();
  debug(poly.pts);

  int ans = 0;
  for (int i = 0; i < SZ(poly.pts); ++i) {
    const int j = (i + 1) % SZ(poly.pts);
    if (poly.pts[i].x > poly.pts[j].x) {
      ++ans;
    }
  }

  cout << ans << "\n";
}