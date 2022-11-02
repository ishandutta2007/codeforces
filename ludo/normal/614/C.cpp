#include <iostream>
#include <cmath>

using namespace std;

typedef double NUM; // either double or long long
struct pt
{
	NUM x, y;

	pt() : x(0), y(0) {}
	pt(NUM _x, NUM _y) : x(_x), y(_y) {}
	pt(const pt &p) : x(p.x), y(p.y) {}

	pt operator*(NUM scalar) const
	{ return pt(scalar * x, scalar * y); // scalar
	}
	NUM operator*(const pt &rhs) const {
		return x * rhs.x + y * rhs.y; // dot product
	}
	NUM operator^(const pt &rhs) const {
		return x * rhs.y - y * rhs.x; // cross product
	}
	pt operator+(const pt &rhs) const {
		return pt(x + rhs.x, y + rhs.y); // addition
	}
	pt operator-(const pt &rhs) const {
		return pt(x - rhs.x, y - rhs.y); // subtraction
	}

	double distSq(const pt &rhs) const {
		return (*this - rhs).normSq();
	}

	double normSq() const {
		return x * x + y * y;
	}
};

istream& operator>>(istream &in, pt &p)
{
	return in >> p.x >> p.y;
}

double sqDistPointLine(pt a, pt b, pt c)
{
	a = a - b; c = c - b;
	return (a ^ c) * (a ^ c) / c.normSq();
}

double sqDistPointSegment(pt a, pt b, pt c)
{
	a = a - b;
	c = c - b;
	NUM dot = a * c;
	if (dot <= 0) return a.normSq();
	NUM len = c * c;
	if (dot >= len) return (a - c).normSq();
	return a * a - dot * dot / ((double) len);
	// pt proj = c * dot / ((double) len);
}

int N;

#define MAXN 100000

pt p0, pts[MAXN];
double maxd = -1e50, mind = 1e50;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> p0;
    for (int i = 0; i < N; i++) {
		cin >> pts[i];
    }
    for (int i = 0; i < N; i++) {
		maxd = max(maxd, (p0 - pts[i]).normSq());
		mind = min(mind, (p0 - pts[i]).normSq());
    }

    for (int i = 0, j = N - 1; i < N; j = i++) {
		mind = min(mind, sqDistPointSegment(p0, pts[i], pts[j]));
    }
//	cerr << mind << " " << maxd << endl;
	double ans = acos(-1) * (maxd - mind);
	cout.precision(18);
	cout << ans << endl;
    return 0;
}