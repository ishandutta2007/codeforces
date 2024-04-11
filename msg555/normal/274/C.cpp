#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <complex>
#include <cmath>

using namespace std;

#define USE_FLOAT

#ifdef USE_FLOAT
#define EPS 1e-9
#define nabs fabs
typedef double num;
#else
#define EPS 0
#define nabs(x) ((x) < 0 ? -(x) : (x))
typedef long long num;
#endif

typedef complex<num> point;
typedef vector<point> poly;

struct line {
  line(num A, num B, num C) : A(A), B(B), C(C) {}
  num A, B, C;
};

num cp(point A, point B, point C = point(0, 0)) {
  A -= C; B -= C;
  return A.real() * B.imag() - B.real() * A.imag();
}

/* Returns true if C counter-clockwise AB.  In other words as you walk from A to
 * B, C would be on your left.  */
bool ccw(point A, point B, point C) {
  return cp(A, B, C) > EPS;
}

bool ccweq(point A, point B, point C) {
  return cp(A, B, C) >= -EPS;
}

num dot(point A, point B, point C = point(0, 0)) {
  A -= C; B -= C;
  return A.real() * B.real() + A.imag() * B.imag();
}

/* O(N log N) convex hull implementation. */
bool pointCmp(point A, point B) {
  return make_pair(A.real(), A.imag()) < make_pair(B.real(), B.imag());
}

point pivot;

bool angleCmp(point A, point B) {
  num c = cp(pivot, A, B);
  return nabs(c) <= EPS && dot(A, A, pivot) < dot(B, B, pivot) || c > EPS;
}

void unwind(poly& P, point A) {
  int sz = P.size();
  while(sz > 1 && ccweq(A, P[sz - 1], P[sz - 2])) --sz;
  P.resize(sz);
}

poly hull(poly P) {
  swap(P[0], *min_element(P.begin(), P.end(), pointCmp));
  pivot = P[0];
  sort(P.begin() + 1, P.end(), angleCmp);

  poly ret(1, pivot);
  for(int i = 1; i < P.size(); i++) {
    unwind(ret, P[i]);
    ret.push_back(P[i]);
  }
  unwind(ret, pivot);
  return ret;
}

/* Check if A is in the convex polygon P (in ccw order). */
bool in_convex(poly& P, point A, bool on) {
  if(ccw(P[0], A, P[1]) || ccw(P[0], P.back(), A)) return false;
  int lo = 1;
  int hi = P.size() - 2;
  while(lo < hi) {
    int md = (lo + hi + 1) / 2;
    if(ccw(P[0], P[md], A)) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }
  return (on || lo != 1 ? ccweq : ccw)(P[0], P[lo], A) &&
         (on ? ccweq : ccw)(P[lo], P[lo + 1], A) &&
         (on || lo + 2 != P.size() ? ccweq : ccw)(P[lo + 1], P[0], A);
}

line get_line(point A, point B) {
  line ln(B.imag() - A.imag(), A.real() - B.real(), 0);
  return line(ln.A, ln.B, ln.A * A.real() + ln.B * A.imag());
}

line bisector(point A, point B) {
  line ln(B.real() - A.real(), B.imag() - A.imag(), 0);
  return line(ln.A * 2, ln.B * 2,
              ln.A * (A.real() + B.real()) + ln.B * (A.imag() + B.imag()));
}

point intersect(line A, line B) {
  num det = A.A * B.B - A.B * B.A;
  if(nabs(det) <= EPS) return point(0, 0);
  return point((B.B * A.C - A.B * B.C) / det, (-B.A * A.C + A.A * B.C) / det);
}

point get_circle_center(point A, point B, point C) {
  return intersect(bisector(A, B), bisector(B, C));
}

point A[110];

#define PI 3.14159265358979323

bool flt(double x, double y) {
  if(x + EPS < y) return true;
  if(nabs(y) > EPS) return x / nabs(y) + EPS < (y < 0 ? -1 : 1);
  return false;
}

bool flteq(double x, double y) {
  if(x < y + EPS) return true;
  if(nabs(y) > EPS) return x / nabs(y) < (y < 0 ? -1 : 1) + EPS;
  return false;
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i].real() >> A[i].imag();
  }

  vector<pair<double, point> > pts;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      point pt = A[i] + A[j];
      pt.real() /= 2;
      pt.imag() /= 2;
      //pts.push_back(make_pair(dot(pt - A[i], pt - A[i]), pt));
      for(int k = j + 1; k < N; k++) {
        if(flteq(nabs(cp(A[i], A[j], A[k])), 0)) continue;

        point pt = get_circle_center(A[i], A[j], A[k]);
        pts.push_back(make_pair(dot(pt, pt, A[i]), pt));
      }
    }
  }

  double mxt = 0;
  for(int i = 0; i < pts.size(); i++) {
    point pt = pts[i].second;
    double nt = pts[i].first;

    if(flteq(nt, mxt)) continue;

    bool ok = true;
    vector<double> ANG;
    for(int k = 0; k < N; k++) {
      double r = dot(pt, pt, A[k]);
      ok = flteq(nt, r);
      if(!ok) break;

      if(flteq(r, nt)) {
        double ang = atan2(A[k].imag() - pt.imag(), A[k].real() - pt.real());
        ANG.push_back(ang);
        ANG.push_back(ang + 2 * PI);
      }
    }

    sort(ANG.begin(), ANG.end());
    for(int i = 0; ok && i + 1 < ANG.size(); i++) {
      ok = flt(ANG[i + 1] - ANG[i], PI);
    }
    if(ok) mxt = nt;
  }

  if(mxt == 0) {
    printf("-1\n");
  } else {
    printf("%.9f\n", sqrt(mxt));
  }
  
  return 0;
}