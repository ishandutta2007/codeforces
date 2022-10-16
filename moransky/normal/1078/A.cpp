#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

int a, b, c, x1, y1, x2, y2;

long double ans;

typedef pair<long double, long double> PDD;

PDD t1, t2;

PDD inline get1(long double x) {
	return mp(x, (-c - a * x) / b); 
}

PDD inline get2(long double y) {
	return mp((-c - b * y) / a, y);
}

long double Abs(long double x) {
	return x < 0 ? -x : x;
}

long double inline d(PDD A, PDD B) {
	return Abs(A.fi - B.fi) + Abs(A.se - B.se);
}

long double inline dis(PDD A, PDD B) {
	return sqrt((A.fi - B.fi) * (A.fi - B.fi) + (A.se - B.se) * (A.se - B.se));
}

int main() {
    
    read(a), read(b), read(c);
    read(x1), read(y1), read(x2), read(y2);
    t1 = mp(x1, y1), t2 = mp(x2, y2);
	ans = (long double)abs(x1 - x2) + abs(y1 - y2);
	if (a == 0 || b == 0) {
		printf("%.10Lf\n", ans);
	} else {
		PDD w = get1(x1), x = get2(y1);
		PDD y = get1(x2), z = get2(y2);
		chkMin(ans, d(t1, w) + dis(w, y) + d(y, t2));
		chkMin(ans, d(t1, w) + dis(w, z) + d(z, t2));
		chkMin(ans, d(t1, x) + dis(x, z) + d(z, t2));
		chkMin(ans, d(t1, x) + dis(x, y) + d(y, t2));
		printf("%.10Lf\n", ans);
	}
    
}