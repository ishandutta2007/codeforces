#include <bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;

ll a[N], sum, ans, cnt;
int n, k, x;
map<int,bool> ss;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	n = read();
	k = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read(), cnt += a[i];
	for(int i = 1; i <= n; i ++)
	{
		if(i == n) ans += a[i] * a[1];
		else ans += a[i] * a[i + 1];
	}
	while(k --)
	{
		x = read();
		int l, r;
		if(x == 1) l = n;
		else l = x - 1;
		if(x == n) r = 1;
		else r = x + 1;
		ans += a[x] * cnt - a[x] * a[x];
		ans -= a[x] * sum + a[x] * a[l] + a[x] * a[r];
		if(ss[l]) ans += a[x] * a[l];
		if(ss[r]) ans += a[x] * a[r];		
		sum += a[x];
		ss[x] = 1;
	}
	printf("%I64d", ans);
	return 0;
}