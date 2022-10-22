#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> par;
typedef long long LL;
typedef double db;
const int N = 1e5 + 10;
const LL inf = 6e18;
int n;
LL x[N], y[N], z[N];
LL ansx, ansy, ansz;

void ckmax(LL &x, LL y) {
	if(x < y) x = y;
}
void ckmin(LL &x, LL y) {
	if(x > y) x = y;
}


int chk(LL X, LL L) {
	LL l = -inf, r = inf, u = -inf, d = inf;
	rep(i, 1, n) {
		LL S = L - abs(x[i] - X);
		if(S < 0) return 0;
		LL nx = y[i] + z[i], ny = z[i] - y[i];
		ckmax(u, nx - S), ckmin(d, nx + S), ckmax(l, ny - S), ckmin(r, ny + S);
		if(u > d || l > r) return 0;
	}
	LL ax, ay;
	if(u == d) {
		if((u & 1) ^ (l & 1)) l++;
		if(l > r) return 0;
		ax = u, ay = l;
	} else {
		if((u & 1) ^ (l & 1)) u++;
		ax = u, ay = l;
	}
	ansz = (ax + ay) / 2;
	ansy = (ax - ay) / 2;
	return 1;
}

int even(LL l[4], LL r[4], LL &x, LL &y, LL &z) {
	rep(i, 0, 3) {
		if(l[i] & 1) l[i]++;
		if(r[i] & 1) r[i]--;
		if(l[i] > r[i]) return 0;
		l[i] /= 2, r[i] /= 2;
	}
	l[3] += l[0], r[3] += r[0];
	LL mn = l[1] + l[2], mx = r[1] + r[2];
	ckmax(mn, l[3]), ckmin(mx, r[3]);
	if(mn > mx) return 0;
	y = min(r[1], mn - l[2]);
	z = mn - y;
	l[3] -= l[0], r[3] -= r[0];
	mn = - r[0], mx = - l[0];
	ckmax(mn, l[3] - y - z);
	ckmin(mx, r[3] - y - z);
	if(mn > mx) return 0;
	x = - mx;
	x *= 2, y *= 2, z *= 2;
	return 1;
}

int odd(LL l[4], LL r[4], LL &x, LL &y, LL &z) {
	rep(i, 0, 3) {
		l[i]++, r[i]++;
		if(l[i] & 1) l[i]++;
		if(r[i] & 1) r[i]--;
		if(l[i] > r[i]) return 0;
		l[i] /= 2, r[i] /= 2;
	}
	l[3] += l[0], r[3] += r[0];
	LL mn = l[1] + l[2], mx = r[1] + r[2];
	ckmax(mn, l[3]), ckmin(mx, r[3]);
	if(mn > mx) return 0;
	y = min(r[1], mn - l[2]);
	z = mn - y;
	l[3] -= l[0], r[3] -= r[0];
	mn = - r[0], mx = - l[0];
	ckmax(mn, l[3] - y - z);
	ckmin(mx, r[3] - y - z);
	if(mn > mx) return 0;
	x = - mx;
	x = x * 2 - 1, y = y * 2 - 1, z = z * 2 - 1;
	return 1;
}


int check(LL L) {
	LL l[4], r[4], tmp1[4], tmp2[4];
	rep(i, 0, 3) l[i] = -inf, r[i] = inf;
	rep(i, 1, n) {
		ckmax(l[0], x[i] + y[i] + z[i] - L);
		ckmin(r[0], x[i] + y[i] + z[i] + L);
		ckmax(l[1], x[i] + y[i] - z[i] - L);
		ckmin(r[1], x[i] + y[i] - z[i] + L);
		ckmax(l[2], x[i] - y[i] + z[i] - L);
		ckmin(r[2], x[i] - y[i] + z[i] + L);
		ckmax(l[3], x[i] - y[i] - z[i] - L);
		ckmin(r[3], x[i] - y[i] - z[i] + L);
	}
	rep(i, 0, 3) if(l[i] > r[i]) return 0;
	memcpy(tmp1, l, sizeof(l));
	memcpy(tmp2, r, sizeof(r));
//	x
//	y
//	z
//	(y + z) / 2
//	(x - z) / 2
//	(x - y) / 2
//	y + z - x
	LL nx = 0, ny = 0, nz = 0;
	if(!(even(l, r, nx, ny, nz) || odd(tmp1, tmp2, nx, ny, nz))) return 0;	
	ansx = (ny + nz) / 2, ansy = (nx - nz) / 2, ansz = (nx - ny) / 2;
	return 1;
}

void work() {
	cin >> n;	
	rep(i, 1, n) cin >> x[i] >> y[i] >> z[i];
	LL l = 0, r = 3e18, best = r;
	while(l <= r) {
		LL mid = (l + r) / 2;
		if(check(mid)) best = mid, r = mid - 1;
		else l = mid + 1;
	}
	check(best);
	cout << ansx <<" " << ansy <<" " << ansz << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; ) work();
	return 0;
}