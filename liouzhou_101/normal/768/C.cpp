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

const int MAXN = 1024;

int n, k, x;
int a[2][MAXN];

int main()
{
	
	scanf("%d%d%d", &n, &k, &x);
	for (int i=1; i<=n; ++i)
	{
		int v;
		scanf("%d", &v);
		a[0][v] ++;
	}
	for (int p=1; p<=k; ++p)
	{
		int cur = p&1;
		int pre = cur^1;
		for (int i=0; i<MAXN; ++i)
			a[cur][i] = 0;
		int odd = 0;
		for (int i=0; i<MAXN; ++i)
			if (a[pre][i]&1)
			{
				if (odd)
				{
					a[cur][i] += (a[pre][i]>>1)+1;
					a[cur][i^x] += (a[pre][i]>>1);
				}
				else
				{
					a[cur][i] += (a[pre][i]>>1);
					a[cur][i^x] += (a[pre][i]>>1)+1;
				}
				odd ^= 1;
			}
			else
			{
				a[cur][i] += (a[pre][i]>>1);
				a[cur][i^x] += (a[pre][i]>>1);
			}
	}
	for (int i=MAXN-1; i>=0; --i)
		if (a[k&1][i])
		{
			printf("%d ", i);
			break;
		}
	for (int i=0; i<MAXN; ++i)
		if (a[k&1][i])
		{
			printf("%d\n", i);
			break;
		}
	
	return 0;
}