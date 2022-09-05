#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 5e5 + 5, INF = 0x7fffffff;

struct ele {
	int a, b;
	ele (int x = 0, int y = 0) : a(x), b(y) {}
} a[N];

char c[N];
int n, lx, rx, ly, ry;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", c + 1);
		int len = strlen(c + 1);
		for (int j = 1; j <= len; j++) {
			if (c[j] == 'B') ++a[i].a;
			else ++a[i].b;
		}
		// cout << a[i].a << " " << a[i].b << endl;
	}
	int l = 0, r = 500000, ans = -1, ansx, ansy;
	while (l <= r) {
		int mid = (l + r) >> 1, lim1 = -INF, lim2 = INF;
		lx = ly = -INF; rx = ry = INF;
		for (int i = 1; i <= n; i++) {
			lx = max(lx, a[i].a - mid); rx = min(rx, a[i].a + mid);
			ly = max(ly, a[i].b - mid); ry = min(ry, a[i].b + mid);
			lim1 = max(lim1, a[i].a - a[i].b - mid); lim2 = min(lim2, a[i].a - a[i].b + mid);
		}
		lim1 = max(lim1, lx - ry);
		lim2 = min(lim2, rx - ly);
		if (lx <= rx && ly <= ry && lim1 <= lim2) {
			int tmp = rx - ry;
			// cout << mid << " " << lim1 << " " << lim2 << endl;
			lim1 = max(lim1, min(lim2, tmp));
			lim2 = min(lim2, max(lim1, tmp));
			if (rx - lim1 <= ry && rx >= 0 && rx - lim1 >= 0) {
				ansx = rx; ansy = rx - lim1;
				ans = mid; r = mid - 1;
				continue;
			} else if (lim2 + ry >= 0 && ry >= 0) {
				ansx = lim2 + ry; ansy = ry;
				ans = mid; r = mid - 1;
				continue;
			}
		}
		l = mid + 1;
	}
	// cout << ansx << " " << ansy << endl;
	print(ans, '\n');
	for (int i = 1; i <= ansx; i++) putchar('B');
	for (int i = 1; i <= ansy; i++) putchar('N');
	putchar('\n');
	return 0;
}