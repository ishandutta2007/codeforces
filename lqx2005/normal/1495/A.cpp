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
int t, n;
db x[N], y[N];

void work() {
	scanf("%d", &n);
	int xn = 0, yn = 0;
	rep(i, 1, 2 * n) {
		db X, Y;
		scanf("%lf%lf", &X, &Y);
		if(X == 0) y[++yn] = Y;
		else x[++xn] = X;
	}
	rep(i, 1, n) x[i] = abs(x[i]), y[i] = abs(y[i]);
	sort(x + 1, x + n + 1), sort(y + 1, y + n + 1);
	db ans = 0;
	rep(i, 1, n) ans += sqrt(x[i] * x[i] + y[i] * y[i]);
	printf("%.15lf\n", ans);
	return;
}

int main() {
	for(scanf("%d", &t); t--; ) work();
	return 0;
}