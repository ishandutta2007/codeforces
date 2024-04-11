#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 3e3 + 10;
const db eps = 1e-13, PI = 3.1415926535897932384626433832795;
struct  vec {
	db x, y;
	vec() {x = y = 0; }
	vec(db _x, db _y) {x = _x, y = _y; }
	db angle() {return atan2(y, x); }
	db len() {return x * x + y * y; }
	friend vec operator + (const vec &a, const vec &b) {
		return vec(a.x + b.x, a.y + b.y);
	}
	friend vec operator - (const vec &a, const vec &b) {
		return vec(a.x - b.x, a.y - b.y);
	}
	friend vec operator * (const vec &a, const db &b) {
		return vec(a.x * b, a.y * b);
	}
};
db sgn(db x) {return x < -eps ? -1 : x > eps ? 1 : 0; }
db cmp(db x, db y) {return sgn(x - y);}
vec p[N];
vec cur[N];
db dot(vec a, vec b) {return a.x * b.x + a.y * b.y; }
db det(vec a, vec b) {return a.x * b.y - a.y * b.x; }
vec intersect(vec a, vec p, vec b, vec q) {
	vec w = (b - a);
	db t = det(w, q) / det(p, q);
	return a + p * t;
}
int plane(vec a) { return cmp(a.y, 0) < 0 || (cmp(a.y, 0) == 0 && cmp(a.x, 0) > 0); }
int n;
int main() {
	cin >> n;
	int cnt = 0;
	int m = 0;
	for(int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(c == 0) {
			cnt++;
		} else p[++m] = vec(1. * c * a / (a * a + b * b), 1. * c * b / (a * a + b * b));
	}
	ll ans = 0;
	for(int i = 1; i <= m; i++) {
		int tot = 0;
		for(int j = 1; j <= m; j++) if(i != j) cur[++tot] = p[j] - p[i];
		for(int j = 1; j <= tot; j++) if(plane(cur[j])) cur[j] = cur[j] * (-1);
		sort(cur + 1, cur + tot + 1, [&](const vec a, const vec b) {
			return sgn(det(a, b)) > 0;
		});
		for(int l = 1, r; l <= tot; l = r + 1) {
			r = l;
			while(r + 1 <= tot && sgn(det(cur[r + 1], cur[l])) == 0) r++;
			ans += 1ll * (r - l + 1) * (r - l);
		}
	}
	ans /= 6;
	if(cnt >= 2) ans += m;
	cout << ans  << endl;
	return 0;
}