#include <iostream>
using namespace std;


int n, k;
int cur[10];
bool used[10], rc[10];


long long mod = 1000000007;

int getAns(int pos)
{
	int ans = 0;
	if (pos == k)
	{
		for (int X = 0; X < k; X++)
		{
			int x = X;
			memset(rc, false, sizeof rc);
			while (!rc[x] )
			{
				rc[x] = true;
				x = cur[x];
				if (x == 0)
					break;
			}
			if (x != 0)
				return 0;
		}
		return 1;
	}
	for (int i = 0; i < k; i++)
	{
		if (used[i] )
			continue;

		cur[pos] = i;

		ans += getAns(pos + 1);

		used[i] = false;
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &k);

	long long ans = getAns(0);



	for (int i = 0; i < n - k; i++)
	{
		ans *= (n - k);
		ans %= mod;
	}
	printf("%I64d", ans);



	return 0;
}