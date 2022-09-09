#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

struct Point {
    double x, y;
    Point (double xx = 0, double yy = 0) : x(xx), y(yy) {}
};

typedef Point Vector;
typedef long long ll;

int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}

bool operator == (const Point a, const Point b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

Point operator + (const Point a, const Vector b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator - (const Point a, const Vector b) {
    return Point(a.x - b.x, a.y - b.y);
}

Vector operator * (const Vector a, const double x) {
    return Vector(a.x * x, a.y * x);
}

Vector operator / (const Vector a, const double x) {
    return Vector(a.x / x, a.y / x);
}

bool operator < (const Point a, const Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double Dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double Length(Vector a) {
    return sqrt(Dot(a, a));
}

double Angle(Vector a, Vector b) {
    return acos(Dot(a, b) / Length(a) / Length(b));
}

double Cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double Area2(Point a, Point b, Point c) {
    return fabs(Cross(b - a, c - a));
}

const int N = 1005;

ll n, m, k;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin >> n >> m >> k;
    ll x = n, y = m, K = k;
    ll nn = n, mm = m, kk = k;
    ll d = gcd(n, k); n /= d, k /= d;
    d = gcd(m, k); m /= d, k /= d;
    if(k != 1 && k != 2) {
    	cout << "NO" << endl;
    	return 0;
	}
	if(k == 2) {
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << "0 " << m << endl;
		cout << n << " 0" << endl;
		return 0;
	} else {
    	d = gcd(y, K); y /= d, K /= d;
		d = gcd(x, K); x /= d, K /= d;
		if(n * 2ll <= nn) {
			cout << "YES" << endl;
			cout << "0 0" << endl;
			cout << "0 " << m << endl;
			cout << n * 2ll << " 0" << endl;
			return 0;
		}
		if(y * 2ll <= mm) {
			cout << "YES" << endl;
			cout << "0 0" << endl;
			cout << "0 " << y * 2ll << endl;
			cout << x << " 0" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}