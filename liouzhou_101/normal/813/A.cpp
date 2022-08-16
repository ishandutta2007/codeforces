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

const int MAXN = 1111;

int n;
int a[MAXN];
int m;
int x[MAXN], y[MAXN];

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++ i)
		a[i] += a[i-1];
	scanf("%d", &m);
	for (int i = 1; i <= m; ++ i)
	{
		scanf("%d%d", &x[i], &y[i]);
		if (x[i] <= a[n] && a[n] <= y[i])
		{
			printf("%d\n", a[n]);
			return 0;
		}
		if (x[i] >= a[n])
		{
			printf("%d\n", x[i]);
			return 0;
		}
	}
	puts("-1");
	
	return 0;
}