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

const int N = 2e5 + 5;

struct ele {
	ll a, b, p;
	bool operator < (const ele A) const { return b < A.b; }
};

vector <ele> tmpx, tmpy;
vector <int> ansx, ansy;
ll t[N], x[N], y[N];
int n, l;

ll divdown(ll x, ll y) {
	if (y < 0) x = -x, y = -y;
	if (x % y == 0) return x / y;
	if (x >= 0) return x / y;
	return x / y - 1;
}

ll divup(ll x, ll y) {
	if (y < 0) x = -x, y = -y;
	if (x % y == 0) return x / y;
	if (x >= 0) return x / y + 1;
	return x / y;
}

vector <int> solve(vector <ele> a) {
	a.push_back((ele) {0, 0, 0}); a.push_back((ele) {-1, l, 0});
	sort(a.begin(), a.end());
	// for (int i = 0; i < (int)a.size(); i++) {
	// 	fprintf(stderr, "a = %lld, b = %lld, p = %lld\n", a[i].a, a[i].b, a[i].p);
	// }
	ll l = 0, r = ::l;
	for (int i = 0; i < (int)a.size() - 1; i++) {
		ll da = a[i + 1].a - a[i].a;
		ll db = a[i + 1].b - a[i].b;
		ll dp = a[i + 1].p - a[i].p;
		if (da == 0) {
			if (dp < 0 || db - dp < 0) {
				printf("NO\n");
				exit(0);
			}
			continue;
		}
		if (-da > 0) {
			l = max(l, divup(dp, da));
			r = min(r, divdown(db - dp, -da));
		} else {
			l = max(l, divup((db - dp), -da));
			r = min(r, divdown(dp, da));
		}
		// fprintf(stderr, "l = %lld, r = %lld, da = %lld, db = %lld, dp = %lld\n", l, r, da, db, dp);
	}
	if (l > r) {
		printf("NO\n");
		exit(0);
	}
	vector <int> ans(::l, 0);
	for (int i = 0; i < (int)a.size() - 1; i++) {
		ll cnt = a[i + 1].p - a[i + 1].a * l - a[i].p + a[i].a * l;
		for (int j = a[i].b; j <= a[i].b + cnt - 1; j++) ans[j] = 1;
	}
	return ans;
}

int main() {
	read(n); read(l);
	for (int i = 1; i <= n; i++) {
		ll tx, ty;
		read(t[i]); read(tx); read(ty);
		x[i] = tx + ty; y[i] = tx - ty;
		if ((t[i] + x[i]) & 1) {
			printf("NO\n");
			return 0;
		}
		x[i] = (x[i] + t[i]) / 2;
		y[i] = (y[i] + t[i]) / 2;
		tmpx.push_back((ele) {t[i] / l, t[i] % l, x[i]});
		tmpy.push_back((ele) {t[i] / l, t[i] % l, y[i]});
	}
	ansx = solve(tmpx); ansy = solve(tmpy);
	// printf("YES\n");
	for (int i = 0; i < l; i++) {
		// cout << ansx[i] << " " << ansy[i] << endl;
		if (ansx[i] == 1 && ansy[i] == 1) putchar('R');
		if (ansx[i] == 1 && ansy[i] == 0) putchar('U');
		if (ansx[i] == 0 && ansy[i] == 1) putchar('D');
		if (ansx[i] == 0 && ansy[i] == 0) putchar('L');
	}
	putchar('\n');
    return 0;
}