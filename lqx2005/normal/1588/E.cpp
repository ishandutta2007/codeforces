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
const db eps = 1e-8, PI = 3.1415926535897932384626433832795;
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
};
db dot(vec a, vec b) {return a.x * b.x + a.y * b.y; }
db det(vec a, vec b) {return a.x * b.y - a.y * b.x; }
vec a[N];
bool able[N][N];
pair<db, int> cur[N * 3];
int main() {
	int n;
	db R;
	scanf("%d%lf", &n, &R);
	for(int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
	memset(able, 1, sizeof(able));
	for(int i = 1; i <= n; i++) {
		int tot = 0, cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			vec t = a[j] - a[i];
			db dis = sqrt(t.len());
			db ang = t.angle();
			if(ang < 0) ang += 2 * PI;
			cur[++tot] = {ang, j};
			if(dis <= R) continue;
			db d = asin(R / dis);
			db l = ang - d, r = ang + d;
			if(l < 0) l += 2 * PI;
			if(r >= 2 * PI) r -= 2 * PI;
			if(l <= r) cnt++;
			cur[++tot] = {l, -1}, cur[++tot] = {r, -2};
		}
		sort(cur + 1, cur + tot + 1);
		for(int j = 1; j <= tot; j++) {
			if(cur[j].y > 0) able[i][cur[j].y] &= !cnt, able[cur[j].y][i] &= !cnt;
			else cnt += cur[j].y == -1 ? -1 : 1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			ans += able[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}