#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
using namespace std;

const int N = 200010;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n;
struct Node
{
	int x, y;
}a[N];
bool cmp(Node a,Node b)
{
	return a.x < b.x;
}
bool cmp1(Node a,Node b)
{
	return a.y < b.y;
}
int main()
{
	n = read();
	rep(i, 1, n)
	{
		int x = read();
		int l = 0, r = 40000, ans;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(mid * mid <= x) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		a[i].x = min(x - ans * ans, (ans + 1) * (ans + 1) - x);
		if(!a[i].x)
			if(!x) a[i].y = 2;
			else a[i].y = 1;
		else a[i].y = 0;
	}
	sort(a + 1, a + n + 1, cmp);
	ll ans = 0;
	rep(i, 1, n / 2) ans += a[i].x;
	int t = n / 2 + 1;
	while(t <= n && !a[t].x) t ++;
	if(t > n / 2 + 1)
	{
		sort(a + 1, a + t, cmp1);
		for(int i = 1; i <= t - 1 - n / 2; i ++) ans += a[i].y;
	}
	printf("%lld\n", ans);
	return 0;
}