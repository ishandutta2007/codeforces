#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

typedef pair<int, int> P;
typedef long long LL;
typedef double db;
const int N = 1e5 + 10;
int n, p[N];
int pmx[N], smx[N], l[N], r[N];
int main() {
	cin >> n;
	rep(i, 1, n) cin >> p[i];
	l[1] = 1;
	rep(i, 2, n) {
		l[i] = l[i - 1];
		if(p[i] < p[i - 1]) l[i] = i;
	}
	r[n] = n;
	per(i, n - 1, 1) {
		r[i] = r[i + 1];
		if(p[i] < p[i + 1]) r[i] = i;
	}
	int dln = 1, iln = 1;
	pmx[1] = 1;
	rep(i, 2, n) {
		pmx[i] = pmx[i - 1];
		if(p[i] > p[i - 1]) iln++, dln = 1;
		else dln++, iln = 1;
		pmx[i] = max(pmx[i], max(iln, dln));
	}
	dln = 1, iln = 1;
	smx[n] = 1;
	per(i, n - 1, 1) {
		smx[i] = smx[i + 1];
		if(p[i] > p[i + 1]) iln++, dln = 1;
		else dln++, iln = 1;
		smx[i] = max(smx[i], max(iln, dln));
	}
	int cnt = 0; 
	rep(i, 2, n - 1) {
		if(p[i - 1] > p[i] || p[i] < p[i + 1]) continue;
		int last = max(pmx[l[i]], smx[r[i]]);
		int le = i - l[i] + 1, ri = r[i] - i + 1;
		int now = max(le, ri);
		if(now <= last) continue;
		if(le & 1) le--;
		if(ri & 1) ri--;
		if(r[i] - i + 1 <= le) continue;
		if(i - l[i] + 1 <= ri) continue;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}