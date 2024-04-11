#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100010];
ll bit[2][100010];

inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int lowbit(int x)
{
	return x & (-x);
}

void update(int i, ll val, bool f)
{
	while(i < 100010)
	{
		bit[f][i] += val;
		i += lowbit(i);
	}
}

ll query(int i, bool f)
{
	ll ret = 0;
	while(i)
	{
		ret += bit[f][i];
		i -= lowbit(i);
	}
	return ret;
}

int main()
{
	ll n, i;
	n = read();
	for(i = 1; i <= n; i ++)
		a[i] = read();
	update(a[1], 1, 0);
	update(a[1], 1, 1);

	ll tot = n * (n + 1) / 2;
	double ans = 0;
	for(i = 2; i <= n; i ++)
	{
		double t = ((double)(n + 1 - i)) / ((double)tot);
		t *= i * (i - 1) / 2;
		t /= 2;
		ll cnt = i - 1 - query(a[i],0);
		ll sum = i * (i - 1) / 2 - query(a[i],1);
		t += (cnt - ((double)sum * (n + 1 - i)) / ((double)tot));
		ans += t;
		update(a[i], 1, 0);
		update(a[i], i, 1);
	}
	printf("%.12lf\n",ans);
	return 0;
}