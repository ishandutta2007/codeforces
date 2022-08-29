#include <bits/stdc++.h>

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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const LD kEps = 1e-9;
const LD kPi = 2 * acos(0);
LD Sq(LD x) { return x * x; }
struct Point {
  LD x, y;
  Point() {}
  Point(LD a, LD b) : x(a), y(b) {}
  Point(const Point& a) : x(a.x), y(a.y) {}
  void operator=(const Point& a) { x = a.x; y = a.y; }
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y); return p; }
  Point operator*(LD a) const { Point p(x * a, y * a); return p; }
  Point operator/(LD a) const { assert(abs(a) > kEps); Point p(x / a, y / a); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  Point& operator*=(LD a) { x *= a; y *= a; return *this;}
  Point& operator/=(LD a) { assert(abs(a) > kEps); x /= a; y /= a; return *this; }
  
  bool IsZero() const { return abs(x) < kEps && abs(y) < kEps; }
  bool operator==(const Point& a) const { return (*this - a).IsZero(); }
  LD CrossProd(const Point& a) const { return x * a.y - y * a.x; }
  LD CrossProd(Point a, Point b) const { a -= *this; b -= *this; return a.CrossProd(b); }
  LD DotProd(const Point& a) const { return x * a.x + y * a.y; }
  LD Norm() const { return sqrt(Sq(x) + Sq(y)); }
  void NormalizeSelf() {  *this /= Norm(); }
  Point Normalize() { Point res(*this); res.NormalizeSelf(); return res; }
  LD Dist(const Point& a) const { return (*this - a).Norm(); }
  LD Angle() const { return atan2(y, x); }
  void RotateSelf(LD angle) {
    LD c = cos(angle); LD s = sin(angle);
    LD nx = x * c - y * s; LD ny = y * c + x * s;
    y = ny; x = nx;
  }
  Point Rotate(LD angle) { Point res(*this); res.RotateSelf(angle); return res; }
  static bool LexCmp(const Point& a, const Point& b) {
    if (abs(a.x - b.x) > kEps) { return a.x < b.x; }
    return a.y < b.y;
  }
  LD SqNorm() { return x * x + y * y; }
  friend ostream& operator<<(ostream& out, Point m);
};

ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.x << ", " << p.y << ")"; return out;
}

struct Circle {
  Point center; LD r;
  Circle(LD x, LD y, LD rad) { center = Point(x, y); r = rad; }
  Circle(const Point& a, LD rad) : center(a), r(rad) {}
  LD Area() const { return kPi * Sq(r); }
  LD Perimeter() const { return 2 * kPi * r; }
  LD Diameter() const { return 2 * r; }
  Point RotateRightMost(LD ang) { return center + Point{r * cos(ang), r * sin(ang)}; }
  bool operator==(const Circle& c) { return center == c.center && abs(r - c.r) < kEps; }
};

struct Line {
  Point p[2]; bool is_seg;
  Line(Point a, Point b, bool is_seg_ = false) {
    p[0] = a; p[1] = b; is_seg = is_seg_;
  }
  Point& operator[](int a) {
    return p[a];
  }
  Point NormalVector() {
    Point perp = p[1] - p[0];
    perp.RotateSelf(kPi / 2);
    perp.NormalizeSelf();
    return perp;
  }
  
  // (A, B, C) such that A^2 + B^2 = 1, (A, B) > (0, 0)
  vector<LD> LineEqNormLD() { // seems ok
    LD A = p[1].y - p[0].y; LD B = p[0].x - p[1].x;
    LD C = -(A * p[0].x + B * p[0].y);
    assert(abs(A * p[1].x + B * p[1].y + C) < kEps);
    LD norm = sqrt(Sq(A) + Sq(B));
    vector<LD> res{A, B, C}; for (auto& x : res) { x /= norm; }
    if (A < -kEps || (abs(A) < kEps && B < -kEps)) { for (auto& x : res) { x *= -1; } }
    return res;
  }
  
  // assumes that coordinates are integers!
  vector<int> LineEqNormInt() { // seems ok
    int A = round(p[1].y - p[0].y); int B = round(p[0].x - p[1].x);
    int C = -(A * p[0].x + B * p[0].y); int gcd = abs(__gcd(A, __gcd(B, C)));
    vector<int> res{A, B, C};
    for (auto& x : res) { x /= gcd; }
    if (A < 0 || (A == 0 && B < 0)) { for (auto& x : res) { x *= -1; } }
    return res;
  }
};

struct Utils {
  // 0, 1, 2 or 3 pts. In case of 3 pts it means they are equal
  static vector<Point> InterCircleCircle(Circle a, Circle b) {
    if (a.r + kEps < b.r) { swap(a, b); }
    if (a == b) {
      return vector<Point>{a.RotateRightMost(0), a.RotateRightMost(2 * kPi / 3),
          a.RotateRightMost(4 * kPi / 3)};
    }
    Point diff = b.center - a.center; LD dis = diff.Norm();  LD ang = diff.Angle();
    LD longest = max(max(a.r, b.r), dis); LD per = a.r + b.r + dis;
    if (2 * longest > per + kEps) { return vector<Point>(); }
    if (abs(2 * longest - per) < 2 * kEps) {
      return vector<Point>{a.RotateRightMost(ang)};
    }
    LD ang_dev = acos((Sq(a.r) + Sq(dis) - Sq(b.r)) / (2 * a.r * dis));
    return vector<Point>{a.RotateRightMost(ang - ang_dev), a.RotateRightMost(ang + ang_dev)};
  }
  
  static vector<Point> InterLineLine(Line& a, Line& b) { // working fine
    Point vec_a = a[1] - a[0]; Point vec_b1 = b[1] - a[0]; Point vec_b0 = b[0] - a[0]; 
    LD tr_area = vec_b1.CrossProd(vec_b0);
    LD quad_area = vec_b1.CrossProd(vec_a) + vec_a.CrossProd(vec_b0);
    if (abs(quad_area) < kEps) { // parallel or coinciding
      if (PtBelongToLine(b, a[0])) { return {a[0], a[1]}; }
      else { return {}; }
    }
    return {a[0] + vec_a * (tr_area / quad_area)};
  } 
  
  static Point ProjPointToLine(Point p, Line l) { ///Tested
    Point diff = l[1] - l[0];
    return l[0] + diff * (diff.DotProd(p - l[0]) / diff.DotProd(diff));
  }
  
  static Point ReflectPtWRTLine(Point p, Line l) {
    Point proj = ProjPointToLine(p, l); return proj * 2 - p;
  }
  
  static vector<Point> InterCircleLine(Circle c, Line l) {
    Point proj = ProjPointToLine(c.center, l); LD dis_proj = c.center.Dist(proj);
    if (dis_proj > c.r + kEps) { return vector<Point>(); }
    if (dis_proj > c.r - kEps) { return {proj}; }
    LD a = sqrt(Sq(c.r)-Sq(dis_proj)); Point dir = l[1]-l[0]; LD dir_norm = dir.Norm();
    vector<Point> cands{proj + dir * (a / dir_norm), proj - dir * (a / dir_norm)};
    if (cands[0].Dist(cands[1]) < kEps) { return vector<Point>{proj}; }
    return cands;
  }
  
  static bool PtBelongToLine(Line l, Point p) { return abs(l[0].CrossProd(l[1], p)) < kEps; }
  
  static bool PtBelongToSeg(Line l, Point p) { // seems ok
    return abs(p.Dist(l[0]) + p.Dist(l[1]) - l[0].Dist(l[1])) < kEps;
  }
  
  static vector<Point> InterCircleSeg(Circle c, Line l) { //seems ok
    vector<Point> from_line = InterCircleLine(c, l);
    vector<Point> res;
    for (auto p : from_line) {
      if (PtBelongToSeg(l, p)) { res.PB(p); }
    }
    return res;
  }
  
  static vector<Point> TangencyPtsToCircle(Circle c, Point p) { // seems ok
    LD d = c.center.Dist(p); if (d < c.r - kEps) { return {}; }
    if (d < c.r + kEps) { return {p}; }
    LD from_cent = (p - c.center).Angle(); LD ang_dev = acos(c.r / d);
    return {c.RotateRightMost(from_cent - ang_dev), c.RotateRightMost(from_cent + ang_dev)};
  }
  
  // outer and inner tangents tested only locally (however I believe that rigorously)
  static vector<Line> OuterTangents(Circle c1, Circle c2) {
    if (c1 == c2) { return {}; } // is it surely best choice?
    if (c1.r < c2.r) { swap(c1, c2); }
    if (c2.r + c1.center.Dist(c2.center) < c1.r - kEps) { return {}; }
    if (abs(c1.r - c2.r) < kEps) {
      Point diff = c2.center - c1.center;
      Point R = diff.Rotate(kPi / 2) * (c1.r / diff.Norm()); 
      return {{c1.center + R, c2.center + R}, {c1.center - R, c2.center - R}};
    }
    Point I = c1.center + (c2.center - c1.center) * (c1.r / (c1.r - c2.r)); 
    if (c2.r + c1.center.Dist(c2.center) < c1.r + kEps) {
      return {{I, I + (c2.center - c1.center).Rotate(kPi / 2)}};
    }
    vector<Point> to1 = TangencyPtsToCircle(c1, I);
    vector<Point> to2 = TangencyPtsToCircle(c2, I);
    vector<Line> res{{to1[0], to2[0]}, {to1[1], to2[1]}};
    assert(Utils::PtBelongToLine(res[0], I));
    assert(Utils::PtBelongToLine(res[1], I));
    return res;
  }
    
  static vector<Line> InnerTangents(Circle c1, Circle c2) {
    if (c1 == c2) { return {}; } // this time surely best choice
    if (c1.r < c2.r) { swap(c1, c2); }
    LD d = c1.center.Dist(c2.center);
    if (d < c1.r + c2.r - kEps) { return {}; }
    Point I = c1.center + (c2.center - c1.center) * (c1.r / (c1.r + c2.r));
    if (d < c1.r + c2.r + kEps) {
      return {{I, I + (c2.center - c1.center).Rotate(kPi / 2)}};
    }
    vector<Point> to1 = TangencyPtsToCircle(c1, I);
    vector<Point> to2 = TangencyPtsToCircle(c2, I);
    vector<Line> res{{to1[0], to2[0]}, {to1[1], to2[1]}};
    assert(Utils::PtBelongToLine(res[0], I));
    assert(Utils::PtBelongToLine(res[1], I));
    return res;
  }
  
  static bool AreParallel(Line l1, Line l2) { // seems ok
    return abs(l1[0].CrossProd(l2[0], l1[1]) - l1[0].CrossProd(l2[1], l1[1])) < kEps;
  }
  
  static vector<Point> InterSegs(Line l1, Line l2) { // seems ok
    if (!Point::LexCmp(l1[0], l1[1])) { swap(l1[0], l1[1]); }
    if (!Point::LexCmp(l2[0], l2[1])) { swap(l2[0], l2[1]); }
    if (AreParallel(l1, l2)) {
      if (!PtBelongToLine(l1, l2[0])) { return vector<Point>(); }
      vector<Point> ends(2);
      for (int tr = 0; tr < 2; tr++) {
        if (Point::LexCmp(l1[tr], l2[tr]) ^ tr) { ends[tr] = l2[tr]; }
        else { ends[tr] = l1[tr]; }
      }
      if ((ends[1] - ends[0]).IsZero()) { ends.pop_back(); }
      if (SZ(ends) == 2 && Point::LexCmp(ends[1], ends[0])) { return vector<Point>(); }
      return ends;
    } else {
      vector<Point> p = InterLineLine(l1, l2);
      if (PtBelongToSeg(l1, p[0]) && PtBelongToSeg(l2, p[0])) { return p; }
      return vector<Point>();
    }
  }
  
  static LD Angle(Point P, Point Q, Point R) { // angle PQR
    LD ang2 = (P - Q).Angle(); LD ang1 = (R - Q).Angle();
    LD ans = ang1 - ang2;
    if (ans < kEps) { ans += 2 * kPi; }
    return ans;
  }
  
  static LD DiskInterArea(Circle c1, Circle c2) {
    if (c1.r < c2.r) { swap(c1, c2); }
    LD d = c1.center.Dist(c2.center);
    if (c1.r + c2.r < d + kEps) { return 0; }
    if (c1.r - c2.r > d - kEps) { return kPi * Sq(c2.r); }
    LD alfa = acos((Sq(d) + Sq(c1.r) - Sq(c2.r)) / (2 * d * c1.r));
    LD beta = acos((Sq(d) + Sq(c2.r) - Sq(c1.r)) / (2 * d * c2.r));
    return alfa * Sq(c1.r) + beta * Sq(c2.r)
        - sin(2 * alfa) * Sq(c1.r) / 2 - sin(2 * beta) * Sq(c2.r) / 2;
  }
  
  static Line RadAxis(Circle c1, Circle c2) {
    LD d = c1.center.Dist(c2.center); LD a = (Sq(c1.r) - Sq(c2.r) + Sq(d)) / (2 * d);
    Point Q = c1.center + (c2.center - c1.center) * (a / d);
    Point R = Q + (c2.center - c1.center).Rotate(kPi / 2);
    return Line(Q, R);
  }
};

struct Polygon {
  vector<Point> pts;
  void Add(Point p) { pts.push_back(p); }
  double Area() { // positive for counterclockwise
    double area = 0;
    for (int i = 0; i < SZ(pts); i++) {
      area += pts[i].CrossProd(pts[(i + 1) % SZ(pts)]);
    }
    return area / 2;
  }
  void OrientCounterclockwise() {
    if (Area() < 0) { reverse(pts.begin(), pts.end()); }
  }
  int next(int a) {
    if (a + 1 < SZ(pts)) { return a + 1; }
    return 0;
  }
  pair<int, int> FurthestPair() {
    MakeConvexHull();
    OrientCounterclockwise();
    int furth = 1;
    pair<int, int> best_pair = make_pair(0, 0);
    double best_dis = 0;
    for (int i = 0; i < SZ(pts); i++) {
      Point side = pts[next(i)] - pts[i];
      while (side.CrossProd(pts[furth] - pts[i]) <
             side.CrossProd(pts[next(furth)] - pts[i])) {
        furth = next(furth);
      }
      vector<int> vec{i, next(i)};
      for (auto ind : vec) {
        if (pts[ind].Dist(pts[furth]) > best_dis) {
          best_pair = make_pair(ind, furth); best_dis = pts[ind].Dist(pts[furth]);
        }
      }
      cerr<<"Furthest from: "<<pts[i]<<"-"<<pts[next(i)]<<" is "<<pts[furth]<<endl;
    }
    return best_pair;
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
            dir * (pts[i] - H[SZ(H) - 2]).CrossProd(H.back() - H[SZ(H) - 2]) > -kEps) {
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
  // without sides
  vector<vector<bool>> InsideDiagonalsMatrix() {
    int n = pts.size();
    vector<vector<bool>> res(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        Line diag(pts[i], pts[j]);
        if (i == j || abs(i - j) == 1 || abs(i - j) == n - 1) { continue; }
        res[i][j] = 1;
        for (int k = 0; k < n; k++) {
          int kk = next(k);
          Line side(pts[k], pts[kk]);
          if (k == i || k == j || kk == i || kk == j) { continue; }
          vector<Point> inter = Utils::InterSegs(diag, side);
          if (SZ(inter)) { res[i][j] = 0; }
        }
        int act = next(i); LD areas[2] = {0, 0}; int passed_j = 0;
        while (act != i) {
          passed_j |= (act == j);
          areas[passed_j] += pts[i].CrossProd(pts[act], pts[next(act)]);
          act = next(act);
        }
        if (areas[0] * areas[1] < kEps) { res[i][j] = 0; }
      }
    }
    return res;
  }
  // P needs to be strictly outside polygon 
  // polygon needs to be STRICTLY convex and counterclockwise oriented (as MakeConvexHull does)
  // returns {L, R} so that PL, PR are tangents and PL is on left
  vector<Point> Tangents(Point p) { // tested here: https://icpc.kattis.com/problems/spin (1169964)
    vector<Point> res;
    REP (tr, 2) {
      auto GrThan = [&](int fir, int sec) { // fir on sec's left
        return p.CrossProd(pts[sec], pts[fir]) > kEps;
      };
      bool up = false; int cr = 0;
      if (SZ(pts) >= 2) { cr = p.CrossProd(pts[0], pts[1]); }
      if (abs(cr) < kEps && SZ(pts) >= 3) { cr = p.CrossProd(pts[0], pts[2]); }
      up = (cr > 0);
      VI bd{1, SZ(pts) - 1};
      int faj = 0;
      while (bd[0] + 6 <= bd[1]) { // better don't replace with smaller constants
        VI h(2);
        REP (hh, 2) { h[hh] = (bd[0] + bd[1] + bd[hh]) / 3; }
        if (!GrThan(h[up ^ tr], 0) ^ tr) { bd[up ^ tr] = h[up ^ tr]; }
        else {
          int gr = GrThan(h[0], h[1]);
          bd[gr ^ tr] = h[gr ^ tr];
        }
      }
      FOR (i, bd[0], bd[1]) {
        if (GrThan(i, faj) ^ tr) { faj = i; }
      }
      res.PB(pts[faj]);
    }
    return res;
  }
};

struct ConvexPolHalves { // tested here: https://icpc.kattis.com/problems/spin (1169964)
  vector<vector<Point>> chains; // initialized by MakeConvexHull
  bool BelongTo(Point p) { // including borders
    if (SZ(chains[0]) == 1) {
      return (chains[0][0] - p).IsZero();
    }
    if (p.x  + kEps < chains[0][0].x || p.x - kEps > chains[0].back().x) { return false; }
    REP (tr, 2) {
      int kl = 0, kp = SZ(chains[tr]) - 2, faj = 0;
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        if (chains[tr][aktc].x < p.x + kEps) {
          kl = aktc + 1;
          faj = aktc;
        } else {
          kp = aktc - 1;
        }
      }
      Point fir = chains[tr][faj], sec = chains[tr][faj + 1];
      if (abs(fir.x - sec.x) < kEps) {
        if (tr == 0) { if (sec.y + kEps < p.y) { return false; } }
        else { if (fir.y - kEps > p.y) { return false; } }
      } else {
        LD cr = fir.CrossProd(sec, p);
        if (abs(cr) < kEps) { return true; }
        if ((cr > 0) ^ tr) { return false; }
      }
    }
    return true;
  }
};

// CLIP START
bool InUpper(Point a) {
  if (abs(a.y) > kEps) { return a.y > 0; } return a.x > 0;
}
bool angle_cmp(const Point a, const Point b) {
  bool u = InUpper(a); bool v = InUpper(b);
  return u!=v ? u : a.CrossProd(b)>0;
}
/** @brief a+(b-a)*f \in c+lin(d-c)  @returns f */
LD cross(Point a, Point b, Point c, Point d) {
  return (d - c).CrossProd(a - c) / (d - c).CrossProd(a - b);
}

struct ClipLine { // valid side is on left
  ClipLine(Point A, Point B) : al(A), bl(B), a(A), b(B) {};
  Point al,bl; // original line points
  mutable Point a,b; // actual intersection points
  Point dir() const { return bl - al; }
  bool operator<(const ClipLine& l) const { return angle_cmp(dir(),l.dir()); }
  Point cross(const ClipLine& l) {
    return al + (bl - al) * ::cross(al, bl, l.al, l.bl);
  }
  bool left(Point p) { return (bl - al).CrossProd(p - al) > 0; }
};

struct Clip {
  Clip(LD r) : area(4*r*r) {
    Point a{-r,-r}, b{r,-r}, c{r,r}, d{-r,r};
    lines = {ClipLine(a,b), ClipLine(b,c), ClipLine(c,d), ClipLine(d,a)};
  }
  // doesn't work when two equal lines are inserted
  // in such case create set of normalized equations of lines with custom == kEps
  void insert(Line l) { insert(ClipLine(l[0], l[1])); }
  void insert(ClipLine l) {
    assert(abs(l.dir().SqNorm()) > kEps); find(l);
    while (size() && !l.left(it->a) && !l.left(it->b)) { erase(); }
    if (size()) {
      while (prev(), size() && !l.left(it->a) && !l.left(it->b)) { erase(); }
    }
    if (size() && (!l.left(it->a) || !l.left(it->b))) {
      l.a = l.cross(*it);
      area -= l.a.CrossProd(it->b)*.5; it->b = l.a; next();
      l.b = l.cross(*it);
      if ((l.a-l.b).SqNorm() < kEps) { l.b = l.a; }
      area -= it->a.CrossProd(l.b) * .5;
      it->a = l.b;
      if (!(l.a - l.b).IsZero()) { area += l.a.CrossProd(l.b)*.5; lines.insert(l); }
    }
  }
  void find(const ClipLine &l) {
    it = lines.lower_bound(l); if (it == lines.end()) { it = lines.begin(); }
  }
  void recalculate() {
    area = 0; for (const ClipLine &l : lines) area += l.a.CrossProd(l.b); area *= .5;
  }
  int size() { return lines.size(); }
  void next() { if(++it==lines.end()) it = lines.begin(); }
  void prev() { if(it==lines.begin()) it = lines.end(); --it; }
  void erase() {
    assert(it!=lines.end()); area -= it->a.CrossProd(it->b)*.5; it = lines.erase(it);
    if(it==lines.end()) it = lines.begin();
  }
  typename set<ClipLine>::iterator it; set<ClipLine> lines; LD area;
};
// CLIP ENDS

// CENTERS BEGIN
Point Bary(Point A, Point B, Point C, LD a, LD b, LD c) {
  return (A * a + B * b + C * c) / (a + b + c);
}
Point Centroid(Point A, Point B, Point C) { return Bary(A, B, C, 1, 1, 1); }
Point Circumcenter(Point A, Point B, Point C) {
  LD a = (B - C).SqNorm(), b = (C - A).SqNorm(), c = (A - B).SqNorm();
  return Bary(A, B, C, a * (b + c - a), b * (c + a - b), c * (a + b - c));
}
Point Incenter(Point A, Point B, Point C) {
  return Bary(A, B, C, (B - C).Norm(), (A - C).Norm(), (A - B).Norm());
}
Point Orthocenter(Point A, Point B, Point C) {
  LD a = (B - C).SqNorm(), b = (C - A).SqNorm(), c = (A - B).SqNorm();
  return Bary(A, B, C, (a+b-c)*(c+a-b), (b+c-a)*(a+b-c), (c+a-b)*(b+c-a));
}
Point Excenter(Point A, Point B, Point C) { // opposite to A
  LD a = (B - C).Norm(), b = (A - C).Norm(), c = (A - B).Norm();
  return Bary(A, B, C, -a, b, c);
}

int n;
vector<Circle> t;
vector<Point> all;
void add(Point x){
  for(auto el:all){
    if((x - el).IsZero())return;
  }
  all.PB(x);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  int il = 0;
  t.resize(3,Circle(0,0,0));
  R(i,n){
    cin >> t[i].center.x >> t[i].center.y >> t[i].r;
    R(j,i){
      if(t[i]==t[j]){
        n--;i--;break;
      }
    }
  }
  R(i,n){
    R(j,i){
      auto pom = Utils::InterCircleCircle(t[i],t[j]);
      for(auto el:pom){
        add(el);
      }
      if(SZ(pom)){
        il++;
      }
    }
  }
  int edges = 0;
  int ss = max(n-il,1ll);
  R(i,n){
    for(auto el:all){
      if(abs(t[i].center.Dist(el) - t[i].r) < 5e-6){
        edges++;
      }
    }
  }
  debug(edges,ss,all);
  cout << edges + ss + 1 - SZ(all) << "\n";
}