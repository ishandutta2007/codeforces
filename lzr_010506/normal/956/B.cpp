#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n;
ll u, a[200010];

int main()
{
	n = read();
	u = read1();
	rep(i, 0, n - 1) a[i] = read();
	double ans = 0;
	int can = 0;
	int j = 0;
	rep(i, 0, n - 1)
	{
		while (j + 1 < n && a[j + 1] - a[i] <= u) j ++;
		if (i + 1 >= j) continue;
		can = 1;
		ans = max(ans, (a[j] - a[i + 1]) * 1.0 / (a[j] - a[i]));
	}
	if (!can) puts("-1");
	else printf("%.12lf\n", ans);

	return 0;
}