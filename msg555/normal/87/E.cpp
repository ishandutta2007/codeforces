#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <set>

using namespace std;

//#define USE_FLOAT

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

bool pointEq(point A, point B) {
  return make_pair(A.real(), A.imag()) == make_pair(B.real(), B.imag());
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

poly sum_polys(poly& A, poly& B) {
  poly ret;
  vector<pair<double, int> > EA, EB;
  for(int i = 0; i < A.size(); i++) {
    int j = i + 1 < A.size() ? i + 1 : 0;
    point diff = A[j] - A[i];
    EA.push_back(make_pair(atan2(diff.imag(), diff.real()), j));
  }
  for(int i = 0; i < B.size(); i++) {
    int j = i + 1 < B.size() ? i + 1 : 0;
    point diff = B[j] - B[i];
    EB.push_back(make_pair(atan2(diff.imag(), diff.real()), j));
  }
  sort(EA.begin(), EA.end());
  sort(EB.begin(), EB.end());

  int i = 0, j = 0;
  int u = EA.back().second, v = EB.back().second;
  while(i < EA.size() || j < EB.size()) {
    ret.push_back(A[u] + B[v]);
    if(i != EA.size() && j != EB.size()) {
      if(EA[i] < EB[j]) {
        u = EA[i++].second;
      } else {
        v = EB[j++].second;
      }
    } else if(i != EA.size()) {
      u = EA[i++].second;
    } else {
      v = EB[j++].second;
    }
  }
  sort(ret.begin(), ret.end(), pointCmp);
  ret.resize(unique(ret.begin(), ret.end(), pointEq) - ret.begin());
  return hull(ret);
}

poly sum_polys_slow(poly& A, poly& B) {
  poly ret;
  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < B.size(); j++) {
      ret.push_back(A[i] + B[j]);
    }
  }
  return hull(ret);
}

void dump_poly(string name, poly& P) {
  cout << "Dump " << name << endl;
  for(int i = 0; i < P.size(); i++) {
    cout << i << ": " << P[i].real() << ", " << P[i].imag() << endl;
  }
}

int main() {
/*
  srand(time(NULL));
  for(int t = 1; ; t++) {
    cout << "Iteration: " << t << endl;
    poly A, B;
    A.push_back(point(0, 2));
    A.push_back(point(1, 0));
    A.push_back(point(3, 2));
    B.push_back(point(0, 5));
    B.push_back(point(2, 1));
    B.push_back(point(8, 0));
    if(A.size() < 3 || B.size() < 3) continue;

    poly r1 = sum_polys(A, B);
    poly r2 = sum_polys_slow(A, B);
    if(r1 != r2) {
      cout << in_convex(r2, point(2, 3), true) << endl;
      dump_poly("r1", r1);
      dump_poly("r2", r2);
      return 1;
    }
    return 0;
  }
*/

  poly res;
  for(int i = 0; i < 3; i++) {
    int N; cin >> N;
    poly P;
    for(int j = 0; j < N; j++) {
      num x, y; cin >> x >> y;
      P.push_back(point(x, y));
    }
    P = hull(P);
    res = i ? sum_polys(res, P) : P;
  }

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    num x, y; cin >> x >> y; x *= 3; y *= 3;
    cout << (in_convex(res, point(x, y), true) ? "YES\n" : "NO\n");
  }
}