#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X firch
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int N = 4005;
int f[N][N], p[N][N], h[N][N];
vector<int> b[N];
int x[N], y[N], w[N];
int n, m;

int dp(int l, int r)
{
	if (l > r) return 0;
	if (f[l][r] != -1) return f[l][r];
	f[l][r] = dp(l + 1, r);

	for(int i = 0; i < b[l].size(); i ++)
		if (b[l][i] < r && dp(l, b[l][i]) + dp(b[l][i], r) > f[l][r])
		{
			f[l][r] = f[l][b[l][i]] + f[b[l][i]][r];
			p[l][r] = b[l][i];
		}
	return f[l][r] += h[l][r] > 0;
}

void dfs(int l, int r)
{
	if (l > r) return;
	if (p[l][r]) dfs(l, p[l][r]), dfs(p[l][r], r);
	else dfs(l + 1, r);
	if (h[l][r]) printf("%d ", h[l][r]);
}

int main()
{
	int i, d, r;
	n = read();
	rep(i, 1, n)
	{
		d = read();
		r = read();
		w[m ++] = x[i] = d - r;
		w[m ++] = y[i] = d + r;
	}
	sort(w, w + m);
	m = unique(w, w + m) - w;
	rep(i, 1, n)
	{
		x[i] = upper_bound(w, w + m, x[i]) - w;
		y[i] = upper_bound(w, w + m, y[i]) - w;
		b[x[i]].push_back(y[i]);
		h[x[i]][y[i]] = i;
	}
	memset(f, -1, sizeof(f));
	printf("%d\n", dp(1, m));
	dfs(1, m);
	return 0;
}