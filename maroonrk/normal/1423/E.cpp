#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


using Double = double;

struct Pt {
	Double x, y;
	Pt() {}
	Pt(Double x, Double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator/(const Pt &a) const { const Double d2 = a.abs2(); return Pt((x * a.x + y * a.y) / d2, (y * a.x - x * a.y) / d2); }
	Pt operator+() const { return Pt(+x, +y); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const Double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const Double &k) const { return Pt(x / k, y / k); }
	friend Pt operator*(const Double &k, const Pt &a) { return Pt(k * a.x, k * a.y); }
	Pt &operator+=(const Pt &a) { x += a.x; y += a.y; return *this; }
	Pt &operator-=(const Pt &a) { x -= a.x; y -= a.y; return *this; }
	Pt &operator*=(const Pt &a) { return *this = *this * a; }
	Pt &operator/=(const Pt &a) { return *this = *this / a; }
	Pt &operator*=(const Double &k) { x *= k; y *= k; return *this; }
	Pt &operator/=(const Double &k) { x /= k; y /= k; return *this; }
	Double abs() const { return sqrt(x * x + y * y); }
	Double abs2() const { return x * x + y * y; }
	Double arg() const { return atan2(y, x); }
	Double dot(const Pt &a) const { return x * a.x + y * a.y; }
	Double det(const Pt &a) const { return x * a.y - y * a.x; }
	friend ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
};
const Double EPS = 1e-10;
const Double INF = 1e+10;
const Double PI = acos(-1.0);
inline int sig(Double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
inline Double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }

Pt proj(const Pt &a, const Pt &b) {
	return a * a.dot(b) / a.abs2();
}
Pt perp(const Pt &a, const Pt &b, const Pt &c) {
	return a + proj(b - a, c - a);
}
Pt refl(const Pt &a, const Pt &b, const Pt &c) {
	return perp(a, b, c) * 2 - c;
}

int iSP(const Pt &a, const Pt &b, const Pt &c) {
	int s = sig((b - a).det(c - a));
	if (s != 0) return s;
	if (sig((b - a).dot(c - a)) < 0) return -2; // c-a-b
	if (sig((a - b).dot(c - b)) < 0) return +2; //   a-b-c
	return 0;
}

Pt pLL(const Pt &a, const Pt &b, const Pt &c, const Pt &d) {
	const Pt ab = b - a, cd = d - c;
	return a + ab * (c - a).det(cd) / ab.det(cd);
}

vector<Pt> pCL(const Pt &a, double r, const Pt &b, const Pt &c) {
	const Pt h = perp(b, c, a);
	const double d = (h - a).abs();
	if (sig(d - r) <= 0) {
		const double y = sqrt(max(r * r - d * d, 0.0));
		const Pt e = (c - b) / (c - b).abs();
		return { h - e * y, h + e * y };
	} else {
		return {};
	}
}


pair<Pt,Pt> OLD_pCL(Pt a, double r, Pt b, Pt c) {
Pt h = b + (c - b) * (c - b).dot(a - b) / (c - b).abs2(); // perp(b, c, a)
double d = (h - a).abs();
double y = sqrt(max(r * r - d * d, 0.0));
Pt e = (c - b) / (c - b).abs();
return make_pair(h - e * y, h + e * y);
}
//	circle (0, r) and triangle 0ab, signed
Double mod(Double t) {
	for (; sig(t - PI * 2.0) >= 0; t -= PI * 2.0);
	for (; sig(t) < 0; t += PI * 2.0);
	return t;
}
Double aCT(Double r, Pt a, Pt b) {
	int s = sig(a.det(b));
	if (s == 0) {
		return 0.0;
	}
	if (s < 0) {
		swap(a, b);
	}
	Double ret;
	const bool iA = (a.abs() <= r);
	const bool iB = (b.abs() <= r);
	// const pair<Pt,Pt> pp = pCL(Pt(0, 0), r, a, b);
	const pair<Pt,Pt> pp = OLD_pCL(Pt(0, 0), r, a, b);
	if (iA && iB) {
		ret = a.det(b) / 2;
	} else if (iA && !iB) {
		const Pt p = pp.second;
		// assert(iSP(a, b, p) == 0);
		ret = a.det(p) / 2 + 0.5 * r * r * mod(b.arg() - p.arg());
	} else if (!iA && iB) {
		const Pt p = pp.first;
		// assert(iSP(a, b, p) == 0);
		ret = 0.5 * r * r * mod(p.arg() - a.arg()) + p.det(b) / 2;
	} else if (iSP(a, b, pp.first) == 0) {
		// assert(iSP(a, b, pp.second) == 0);
		Pt p = pp.first, q = pp.second;
		if ((p - a).dot(b - a) > (q - a).dot(b - a)) {
			swap(p, q);
		}
		ret = 0.5 * r * r * mod(p.arg() - a.arg()) + p.det(q) / 2 + 0.5 * r * r * mod(b.arg() - q.arg());
	} else {
		assert(iSP(a, b, pp.second) != 0);
		ret = 0.5 * r * r * mod(b.arg() - a.arg());
	}
	return s * ret;
}

vector<Pt> convexCut(const vector<Pt> &p, const Pt &a, const Pt &b) {
	const int n = p.size();
	vector<Pt> ret;
	for (int i = 0; i < n; ++i) {
		if (sig(tri(a, b, p[i])) >= 0) ret.push_back(p[i]);
		if (sig(tri(a, b, p[i])) * sig(tri(a, b, p[(i + 1) % n])) < 0) ret.push_back(pLL(a, b, p[i], p[(i + 1) % n]));
	}
	if (ret.size() < 3) return {};
	ret.push_back(ret.front());
	return ret;
}


//	inside: +1, boundary: 0, outside: -1
// int sGP(int n, Pt p[], const Pt &a) {
int sGP(const vector<Pt> &p, const Pt &a) {
  const int n = p.size();
	int side = -1;
	// p[n] = p[0];
	for (int i = 0; i < n; ++i) {
		// Pt p0 = p[i] - a, p1 = p[i + 1] - a;
		Pt p0 = p[i] - a, p1 = p[(i + 1) % n] - a;
		if (sig(p0.det(p1)) == 0 && sig(p0.dot(p1)) <= 0) return 0;
		if (p0.y > p1.y) swap(p0, p1);
		if (sig(p0.y) <= 0 && 0 < sig(p1.y) && sig(p0.det(p1)) > 0) side = -side;
	}
	return side;
}



Double W, H;
int N;
vector<int> V;
vector<vector<Pt>> P;

int ansLen;
int ans[1000010];

int main() {
  for (; ~scanf("%lf%lf%d", &W, &H, &N); ) {
    V.resize(N);
    P.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &V[i]);
      P[i].resize(V[i]);
      for (int j = 0; j < V[i]; ++j) {
        scanf("%lf%lf", &P[i][j].x, &P[i][j].y);
      }
    }
    
    const Pt RECT[4] = {
      Pt(0, 0),
      Pt(W, 0),
      Pt(W, H),
      Pt(0, H),
    };
    
    vector<Double> areas(N);
    for (int i = 0; i < N; ++i) {
      Double area = 0.0;
      for (int j = 0; j < V[i]; ++j) {
        area += P[i][j].det(P[i][(j + 1) % V[i]]);
      }
      if (sig(area) < 0) {
        reverse(P[i].begin() + 1, P[i].end());
      }
      for (int h = 0; h < 4; ++h) {
        P[i] = convexCut(P[i], RECT[h], RECT[(h + 1) % 4]);
      }
      V[i] = P[i].size();
      areas[i] = 0.0;
      for (int j = 0; j < V[i]; ++j) {
        areas[i] += P[i][j].det(P[i][(j + 1) % V[i]]);
      }
      areas[i] /= 2.0;
// cerr<<i<<": "<<V[i]<<"; ";pv(P[i].begin(),P[i].end());
    }
    
    int Q;
    scanf("%d", &Q);
    for (int q = 0; q < Q; ++q) {
      Pt o;
      Double r;
      scanf("%lf%lf%lf", &o.x, &o.y, &r);
// cerr<<o<<" "<<r<<endl;
      Double sum = 0.0;
      ansLen = 0;
      for (int i = 0; i < N; ++i) {
        bool ok = false;
        if (V[i] >= 3 && sGP(P[i], o) >= 0) {
          ok = true;
          goto found;
        }
        if (V[i] >= 1 && sig((P[i][0] - o).abs() - r) <= 0) {
          ok = true;
          goto found;
        }
        for (int j = 0; j < V[i]; ++j) {
          if (sig((P[i][(j + 1) % V[i]] - P[i][j]).abs()) > 0) {
            const auto res = pCL(o, r, P[i][j], P[i][(j + 1) % V[i]]);
            for (const auto &p : res) {
              if (iSP(P[i][j], P[i][(j + 1) % V[i]], p) == 0) {
// cerr<<i<<" "<<j<<endl;
                ok = true;
                goto found;
              }
            }
          }
        }
       found:{}
        if (ok) {
          sum += areas[i];
          ans[ansLen++] = i;
        }
      }
      printf("%.6f %d", sum, ansLen);
      for (int h = 0; h < ansLen; ++h) {
        printf(" %d", ans[h]);
      }
      puts("");
    }
  }
  return 0;
}