#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const double eps = 1e-8;

struct Point {
    double x, y;
    Point (double xx = 0, double yy = 0) : x(xx), y(yy) {}
};

typedef Point Vector;

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

double Crs2s(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double Area2(Point a, Point b, Point c) {
    return fabs(Crs2s(b - a, c - a));
}

const int N = 300005;

int n, maxn, a[N], s[N], s1[N], s2[N];
ll ans;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) { 
		ll t; read(t); 
		while(t > 0) { 
			if(t % 2 == 1) a[i]++;
			t >>= 1;
		}
	}
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++) s1[i] = s1[i - 1] + (s[i] & 1);
	s2[0] = 1;
	for(int i = 1; i <= n; i++) s2[i] = s2[i - 1] + ((s[i] & 1) ^ 1);
	for(int i = 1; i <= n; i++) {
		maxn = 0; int mid = max(1, i - 64);
		for(int j = i; j >= mid; j--) {
			if(a[j] > maxn) maxn = a[j];
			if(((maxn << 1) <= s[i] - s[j - 1]) && (s[i] & 1) == (s[j - 1] & 1)) ans++;
		}
		if(!(mid < 1) && !(mid > 1)) continue;
		int tmp = mid - 2;
		if(s[i] & 1) ans += s1[tmp];
		else ans += s2[tmp];
	}
	cout << ans << endl;
	return 0;
}