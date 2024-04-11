#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <complex>
#include <stdio.h>

using namespace std;

#define EPS 1e-3
#define nabs fabs
typedef double num;

typedef complex<num> point;
typedef vector<point> poly;

struct line {
  line(num A, num B, num C) : A(A), B(B), C(C) {}
  num A, B, C;
};

num dot(point A, point B, point C = point(0, 0)) {
  A -= C; B -= C;
  return A.real() * B.real() + A.imag() * B.imag();
}

line get_line(point A, point B) {
  line ret(B.imag() - A.imag(), A.real() - B.real(), 0);
  ret.C = ret.A * A.real() + ret.B * A.imag();
  return ret;
}

line bisector(point A, point B) {
  point P1 = A + B;
  point P2 = P1;
  P2.real() += (A.imag() - B.imag());
  P2.imag() += (B.real() - A.real());
  line ln = get_line(P1, P2);
  ln.A *= 2; ln.B *= 2;
  return ln;
}

point intersect(line A, line B) {
  num det = A.A * B.B - A.B * B.A;
  if(nabs(det) <= EPS) return point(0, 0);
  return point((B.B * A.C - A.B * B.C) / det, (-B.A * A.C + A.A * B.C) / det);
}

point get_circle_center(point A, point B, point C) {
  return intersect(bisector(A, B), bisector(B, C));
}

#define PI 3.14159265358979323

int main() {
  double x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  point A(x1, y1), B(x2, y2), C(x3, y3);
  point center = get_circle_center(A, B, C);
  double radius = sqrt((A.real() - center.real()) * (A.real() - center.real()) +
                       (A.imag() - center.imag()) * (A.imag() - center.imag()));

  vector<double> ANG;
  ANG.push_back(atan2(A.imag() - center.imag(), A.real() - center.real()));
  ANG.push_back(atan2(B.imag() - center.imag(), B.real() - center.real()));
  ANG.push_back(atan2(C.imag() - center.imag(), C.real() - center.real()));
  sort(ANG.begin(), ANG.end());
  
  double alpha = (ANG[1] - ANG[0]) / (2 * PI);
  double beta = (ANG[2] - ANG[0]) / (2 * PI);
  for(int n = 3; ; n++) {
    double r1 = alpha * n;
    double r2 = beta * n;
    if(fabs(r1 - round(r1)) < EPS &&
       fabs(r2 - round(r2)) < EPS) {
      printf("%.9f\n", 0.5 * n * radius * radius * sin(2 * PI / n));
      break;
    }
  }
}