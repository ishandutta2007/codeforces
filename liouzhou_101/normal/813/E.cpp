#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 100010;
const int LEN = 200;
const int TOT = MAXN/LEN+10;

int n, k, tot;
int a[MAXN];
vector<int> v[MAXN];
int L[MAXN], R[MAXN];
int u[MAXN];

int F[TOT][TOT];

int calc(int c, int x)
{
	return upper_bound(v[c].begin(), v[c].end(), x) - v[c].begin();
}

int calc(int c, int x, int y)
{
	return calc(c, y) - calc(c, x-1);
}

int main()
{
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	int len = LEN;
	for (int i = 1; i <= n; i += len)
	{
		tot ++;
		L[tot] = i;
		R[tot] = min(n, i+len-1);
	}
	for (int i = 1; i <= tot; ++ i)
	{
		int cur = 0;
		for (int j = i; j <= tot; ++ j)
		{
			for (int x = L[j]; x <= R[j]; ++ x)
			{
				u[a[x]] ++;
				if (u[a[x]] <= k)
					cur ++;
			}
			F[i][j] = cur;
		}
		
		for (int x = 1; x <= 100000; ++ x)
			u[x] = 0;
	}
	
	int last = 0;
	int q;
	scanf("%d", &q);
	while (q --)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = (x+last)%n+1;
		y = (y+last)%n+1;
		if (x > y) swap(x, y);
		if (y-x+1 <= 2*LEN)
		{
			int cur = 0;
			for (int i = x; i <= y; ++ i)
			{
				if (u[a[i]]) continue;
				u[a[i]] = calc(a[i], x, y);
				cur = cur+min(u[a[i]], k);
			}
			printf("%d\n", cur);
			last = cur;
			for (int i = x; i <= y; ++ i)
				u[a[i]] = 0;
		}
		else
		{
			int l, r;
			for (int i = 1; i <= tot; ++ i)
				if (L[i] >= x)
				{
					l = i;
					break;
				}
			for (int i = tot; i >= 1; -- i)
				if (R[i] <= y)
				{
					r = i;
					break;
				}
			int cur = F[l][r];
			for (int i = x; i <= L[l]-1; ++ i)
			{
				if (u[a[i]]) continue;
				u[a[i]] = calc(a[i], x, y);
				int tmp = calc(a[i], L[l], R[r]);
				cur = cur-min(tmp, k)+min(u[a[i]], k);
			}
			for (int i = R[r]+1; i <= y; ++ i)
			{
				if (u[a[i]]) continue;
				u[a[i]] = calc(a[i], x, y);
				int tmp = calc(a[i], L[l], R[r]);
				cur = cur-min(tmp, k)+min(u[a[i]], k);
			}
			printf("%d\n", cur);
			last = cur;
			for (int i = x; i <= L[l]-1; ++ i)
				u[a[i]] = 0;
			for (int i = R[r]+1; i <= y; ++ i)
				u[a[i]] = 0;
		}
	}
	
	return 0;
}