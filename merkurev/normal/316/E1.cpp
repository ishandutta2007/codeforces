#include <iostream>
#include <set>
using namespace std;


long long mod = 1e9;

int val[105];

long long fi[105];

int main()
{

	fi[0] = 1;
	fi[1] = 1;
	for (int i = 2; i < 105; i++)
	{
		fi[i] = (fi[i - 2] + fi[i - 1] ) % mod;
	}

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val[i] );
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1)
		{
			int pos, x;
			scanf("%d%d", &pos, &x);
			val[pos - 1] = x;
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			r--;
			long long ans = 0;
			for (int i = 0; i <= r - l; i++)
			{
				ans += val[i + l] * fi[i];
				ans %= mod;
			}
			printf("%I64d\n", ans);
		}
	}



	return 0;
}