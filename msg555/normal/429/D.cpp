#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <complex>
#include <cmath>

using namespace std;

static bool geoerror;

// #define USE_FLOAT

// #define USE_RELATIVE_ERROR

#ifdef USE_FLOAT
#define EPS 1e-9
typedef double num;
#else
#define EPS 0
typedef long long num;
#endif

inline num nabs(num x) {
  return x < 0 ? -x : x;
}

bool num_lt(num X, num Y) {
#ifdef USE_RELATIVE_ERROR
  return X + max(num(1), nabs(Y)) * EPS < Y;
#else
  return X + EPS < Y;
#endif
}

bool num_lteq(num X, num Y) {
#ifdef USE_RELATIVE_ERROR
  return X <= Y + max(num(1), nabs(Y)) * EPS;
#else
  return X <= Y + EPS;
#endif
}

bool num_eq(num X, num Y) {
#ifdef USE_FLOAT
  return num_lteq(X, Y) && num_lteq(Y, X);
#else
  return X == Y;
#endif
}

typedef complex<num> point;
typedef vector<point> poly;

struct line {
  line(point norm, num C) : norm(norm), C(C) {}
  point norm;
  num C;
};

num cp(point A, point B, point C = point(0, 0)) {
  return imag(conj(A - C) * (B - C));
}

/* Returns true if C is strictly counter-clockwise AB in cartesian coordinates.
 * In other words as you walk from A to B, C would be on your left.  */
bool ccw(point A, point B, point C) {
  return num_lt(0, cp(A, B, C));
}

bool ccweq(point A, point B, point C) {
  return num_lteq(0, cp(A, B, C));
}

num dot(point A, point B, point C = point(0, 0)) {
  return real(conj(A - C) * (B - C));
}

point pivot;
bool pointCmp(point A, point B) {
  return make_pair(A.real(), A.imag()) < make_pair(B.real(), B.imag());
}
bool angleCmp(point A, point B) {
  num c = cp(pivot, A, B);
  return num_eq(c, 0) && dot(A, A, pivot) < dot(B, B, pivot) || num_lt(0, c);
}
void unwind(poly& P, point A) {
  int sz = P.size();
  while(sz > 1 && ccweq(A, P[sz - 1], P[sz - 2])) --sz;
  P.resize(sz);
}

/* Computes the convex hull of the list of points P.  Returns the points
 * defining the convex hull in ccw order. */
poly hull(poly P) {
  swap(P[0], *min_element(P.begin(), P.end(), pointCmp));
  pivot = P[0];
  sort(P.begin() + 1, P.end(), angleCmp);

  poly ret(1, pivot);
  for(int i = 1; i < P.size(); i++) {
    unwind(ret, P[i]);
    ret.push_back(P[i]);
  }
  if(ret.size() > 2) {
    unwind(ret, pivot);
  }
  return ret;
}

/* Check if A is in the convex polygon P (in ccw order) in O(log(N)) time.  If
 * on is false A must be strictly in the interior of P. */
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
  point norm(B.imag() - A.imag(), A.real() - B.real());
  return line(norm, dot(A, norm));
}

/* Returns the line that passes between A and B orthogonal to the line formed by
 * A and B. */
line bisector(point A, point B) {
  point norm(B.real() - A.real(), B.imag() - A.imag());
  return line(norm * num(2), dot(norm, A + B));
}

/* Returns the point where lines A and B intersect.  Sets geoerror to true if
 * the lines are parallel. */
point intersect(line A, line B) {
  num det = A.norm.real() * B.norm.imag() - A.norm.imag() * B.norm.real();
  if(num_eq(det, 0)) {
    geoerror = true;
    return point(0, 0);
  }
  return point(B.norm.imag() * A.C - A.norm.imag() * B.C,
               -B.norm.real() * A.C + A.norm.real() * B.C) / det;
}

/* Returns the center of the circle that contains the three points A, B, and C.
 * If the points are colinear sets geoerror to true. */
point get_circle_center(point A, point B, point C) {
  return intersect(bisector(A, B), bisector(B, C));
}

/* Returns true if X is on the line segment with endpoints at A and B.  If
 * closed is false X does not include A and B itself. */
bool on_segment(point A, point B, point X, bool closed = true) {
  point lnorm(B.imag() - A.imag(), A.real() - B.real());
  point bnorm(B.real() - A.real(), B.imag() - A.imag());
  if(!num_eq(dot(lnorm, A), dot(lnorm, X))) {
    return false;
  }
  num AN = dot(bnorm, A);
  num BN = dot(bnorm, B);
  num XN = dot(bnorm, X);
  if(BN < AN) {
    swap(AN, BN);
  }
  return (closed ? num_lteq : num_lt)(AN, XN) &&
         (closed ? num_lteq : num_lt)(XN, BN);
}

point rotate(point X, point R, point C = 0) {
  return (X - C) * R + C;
}

/* Returns the area of the simple (not-necessarily convex) polygon P
 * (in ccw order).  However when using integer arithmetic the area may be a
 * half integer.  In this case you can set nohalf to true and twice the area
 * will be returned.
 *
 * If P is clockwise order the result will be negative.
 */
num area(poly P, bool nohalf = false) {
  num result = 0;
  for(int i = 1; i + 1 < P.size(); i++) {
    result += cp(P[i], P[i + 1], P[0]);
  }
  return nohalf ? result : result / 2;
}

bool cmpX(point A, point B) {
  return make_pair(A.real(), A.imag()) < make_pair(B.real(), B.imag());
}
bool cmpY(point A, point B) {
  return make_pair(A.imag(), A.real()) < make_pair(B.imag(), B.real());
}
pair<point, point> closest_pair_rec(const vector<point>& A) {
  if(A.size() <= 10) {
    num ndis = -1;
    pair<point, point> res;
    for(int i = 0; i < A.size(); i++) {
      for(int j = i + 1; j < A.size(); j++) {
        num nn = norm(A[i] - A[j]);
        if(ndis == -1 || num_lt(nn, ndis)) {
          ndis = nn;
          res = make_pair(A[i], A[j]);
        }
      }
    }
    return res;
  }

  point pivot;
  vector<point> X, Y;
  for(; X.size() <= 1 || Y.size() <= 1;) {
    X.clear();
    Y.clear();

    pivot = A[rand() % A.size()]; /* Change to deterministic median */
    for(int i = 0; i < A.size(); i++) {
      if(cmpX(A[i], pivot)) {
        X.push_back(A[i]);
      } else {
        Y.push_back(A[i]);
      }
    }
  }

  pair<point, point> r1 = closest_pair_rec(X);
  pair<point, point> r2 = closest_pair_rec(Y);
  pair<point, point> res = norm(r1.first - r1.second) <
                           norm(r2.first - r2.second) ? r1 : r2;
  num ndis = norm(res.first - res.second);

  int XN = 0;
  for(int i = 0; i < X.size(); i++) {
    if(num_lt(norm(X[i] - point(pivot.real(), X[i].imag())), ndis)) {
      X[XN++] = X[i];
    }
  }

  int YN = 0;
  for(int i = 0; i < Y.size(); i++) {
    if(num_lt(norm(Y[i] - point(pivot.real(), Y[i].imag())), ndis)) {
      Y[YN++] = Y[i];
    }
  }

  for(int i = 0, j = 0; i < XN; i++) {
    while(j < YN && Y[j].imag() < X[i].imag() &&
          num_lteq(ndis, norm(point(pivot.real(), X[i].imag()) - Y[j]))) {
      j++;
    }
    for(int k = j; k < YN; k++) {
      if(X[i].imag() < Y[k].imag() &&
         num_lteq(ndis, norm(X[i] - point(pivot.real(), Y[k].imag())))) {
        break;
      }
      if(num_lt(norm(X[i] - Y[k]), ndis)) {
        ndis = norm(X[i] - Y[k]);
        res = make_pair(X[i], Y[k]);
      }
    }
  }
  return res;
}
pair<point, point> closest_pair(vector<point> A) {
  sort(A.begin(), A.end(), cmpY);
  return closest_pair_rec(A);
}

int main() {
  int N;
  cin >> N;
  vector<point> A(N);
  for(int i = 0, s = 0; i < N; i++) {
    int x; cin >> x;
    s += x;
    A[i] = point(i, s);
  }
  pair<point, point> res = closest_pair(A);
  cout << norm(res.first - res.second) << endl;
  return 0;
}