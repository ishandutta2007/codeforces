#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n;
ll a[100010], Sum, Min, Ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = n; i > 1; i --)
		a[i] = abs(a[i] - a[i - 1]);
	for(int i = 1; i < n; i ++)
		a[i] = a[i + 1];
	Sum = Min = 0;
	for(int i = 1; i < n; i ++)
	{
		if(i & 1) Sum += a[i];
		else Sum -= a[i];
		Min = min(Min, Sum);
		Ans = max(Ans, Sum - Min);
	}
	Sum = Min = 0;
	for(int i = 1; i < n; i ++)
	{
		if(i & 1) Sum -= a[i];
		else Sum += a[i];
		Min = min(Min, Sum);
		Ans = max(Ans, Sum - Min);
	}
	cout << Ans;
	return 0;
}