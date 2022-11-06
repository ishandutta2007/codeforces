#include <bits/stdc++.h>
#include <math.h>
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
const int N = 1e6 + 10;
int n, cnt, Mn, ans;
int pri[N], mn[N], a[N];
bool vis[N];

void getpri(int n)
{
	mn[1] = 1;
	rep(i, 2, n)
	{
		if (!vis[i]) pri[++ cnt] = i, mn[i] = i;
		for (int  j = 1; j <= cnt && i * pri[j] <= n; j ++)
		{
			vis[i * pri[j]] = 1;
			mn[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}

int main()
{
	getpri(1000000);
	n = read();
	Mn = n;
	ans = n;
	rep(i, 1, cnt)
		if (n % pri[i] == 0)
			Mn = min(Mn, n - pri[i] + 1);
	rep(i, Mn, n)
	{
		int j = i;
		cnt = 0;
		while (j > 1)
		{
			a[++ cnt] = mn[j];
			j /= mn[j];
		}
		rep(j, 1, cnt)
			if (i - a[j] + 1 > 1)
				ans = min(ans, i - a[j] + 1);
	}
	printf("%d\n", ans);
	return 0;
}