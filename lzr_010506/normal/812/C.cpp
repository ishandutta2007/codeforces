#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, S;
int a[100010];
ll b[100010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

ll check(int k)
{
	for(int i = 1; i <= n; i ++)
		b[i] = (ll)a[i] + i * (ll)k;
	sort(b + 1, b + n + 1);
	ll now = 0;
	for(int i = 1; i <= k; i ++)
		now += b[i];
	return now;
}

int main()
{
	n = read();
	S = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	int l = 0, r = n;
	int ans = 0;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid) <= S) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << " " << check(ans);
	return 0;
}