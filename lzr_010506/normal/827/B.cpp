#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
const int N = 2e5 + 10;
const int MOD = 1e9 + 9;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, k, a[N], b[N], c[N], dn = 1, Mx = 0;
ll ans;
vector<int> aa[N];
void dfs(int x, int fa, int len)
{
	if(len > Mx) Mx = len, dn = x;
	int nn = aa[x].size() - 1;
	rep(i, 0, nn)
	{
		if(aa[x][i] == fa) continue;
		dfs(aa[x][i], x, len + 1);
	}
}
int main()
{
	n = read();
	k = read();
	int now = 0;
	rep(i, 2, k + 1)
		a[++ now] = i, b[now] = 1;
	rep(i, k + 2, n)
		a[++ now] = i - k, b[now] = i;
	rep(i, 1, now)
	{
		int x = a[i];
		int y = b[i];
		aa[x].pb(y);
		aa[y].pb(x);
	}
	dfs(1, -1, 1);
	Mx = 0;
	dfs(dn, -1, 1);
	cout << Mx - 1 << endl;
	rep(i, 1, now)
		cout << a[i] << " " << b[i] << endl;
	return 0;
}