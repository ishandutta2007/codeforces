#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;
const ld eps = 1e-9;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

struct point {
	ld x, y;
	point(ld X = 0, ld Y = 0) {
		x = X, y = Y;
	}
	point operator+(point a) {
		return point(x + a.x, y + a.y);
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	ld operator*(point a) {
		return x * a.y - y * a.x;
	}
	point operator*(ld k) {
		return point(x * k, y * k);
	}
	ld len() {
		return sqrt(x * x + y * y);
	}
};

bool operator==(point a, point b) {
	return a.x == b.x && a.y == b.y;
}

point norm(point a) {
	ld r = a.len();
	a.x /= r;
	a.y /= r;
	return a;
}

int n;
point p[2100];
int en[2100];
vector<ld> v1;
vector<ld> v2;
vector<point> ans;

int main() {
	point sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
		sum = sum + p[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			point xx = p[i] + p[j];
			if (xx * n == sum * 2) {
				en[i] = 1;
				en[j] = 1;
			}
		}
	}
	int st = -1;
	for (int i = 0; i < n; ++i) {
		if (!en[i]) {
			st = i;
			break;
		}
	}
	if (st == -1) {
		cout << -1 << "\n";
		return 0;
	}
	sum.x /= n;
	sum.y /= n;
	for (int i = 0; i < n; ++i)
		p[i] = p[i] - sum;
	for (int i = 0; i < n; ++i) {
		point xx = norm(p[i] + p[st]);
		v1.clear();
		v2.clear();
		for (int j = 0; j < n; ++j) {
			ld cc = (p[j] * xx);
			if (abs(cc) > eps) {
				if (cc > 0)
					v1.push_back(cc);
				else
					v2.push_back(-cc);
			}
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		if (v1.size() != v2.size())
			continue;
		int fl = 0;
		for (int j = 0; j < v1.size(); ++j) {
			if (abs(v1[j] - v2[j]) >= eps) {
				fl = 1;
				break;
			}
		}
		if (fl) {
			continue;
		}
		ans.push_back(xx);
	}
	int cnt = 0;
	for (int i = 0; i < ans.size(); ++i) {
		int fl = 0;
		for (int j = 0; j < i; ++j) {
			if ((ans[i] - ans[j]).len() <= eps || (ans[i] + ans[j]).len() <= eps) {
				fl = 1;
				break;
			}
		}
		if (!fl)
			++cnt;
	}
	cout << cnt << "\n";
	return 0;
}