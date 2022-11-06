#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).sze()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define N 100010
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int x[N], y[N], xx[N], yy[N], pd[2][2];
int n, m, midx, midy, mx, my;
ll ans;

int main()
{
	n = read();
	m = (n - 1) / 2;
	rep(i, 0, n - 1)
	{
		x[i] = read();
		y[i] = read();
		xx[i] = x[i], yy[i] = y[i];
	}

	sort(x, x + n);
	mx = x[m + 1] - x[m];
	sort(y, y + n);
	my = y[m + 1] - y[m];
	if (n % 2)
	{
		mx = min(mx, x[m] - x[m - 1]);
		my = min(my, y[m] - y[m - 1]);
	}
	midx = x[m], midy = y[m];

	bool flag = 0;
	rep(i, 0, n - 1)
	{
		ans += abs(x[i] - midx) + abs(y[i] - midy);
		pd[xx[i] <= midx][yy[i] <= midy] = 1;
		if (midx == xx[i] && midy == yy[i]) flag = 1;
	}

	if ((n % 2 == 0 || flag) && (pd[0][0] == pd[0][1])) ans = max(ans - mx, ans - my);
	printf("%I64d\n", ans * 2);
	return 0;
}