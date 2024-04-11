#include <cstdio>
#include <iostream>
#define MN 101000

long long len[MN];
long long lst[MN];
long long Min[MN];
char c[MN];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &len[i]);
	scanf("%s", c + 1);
	bool swim = 0;
	long long sum = 0;
	long long ans = 0;
	
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == 'G')
		{
			sum += len[i];
			ans += len[i] * 5;
		}
		if(c[i] == 'W')
		{
			swim = 1;
			sum += len[i];
			ans += len[i] * 3;
		}
		if(c[i] == 'L')
		{
			if(sum < len[i])
			{
				ans += (len[i] - sum) * (swim ? 3 : 5);
				sum = len[i];
			}
			sum -= len[i];
			ans += len[i];
		}
		lst[i] = sum;
	}
	
	long long mmin = sum;
	for(int i = n; i >= 1; i--)
	{
		mmin = std::min(mmin, lst[i]);
		Min[i] = mmin;
	}
	
	long long used = 0;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == 'G')
		{
			long long fly = std::min(len[i] * 2, Min[i] - used);
			used += fly;
			ans -= 2 * fly;
		}
		lst[i] = lst[i] - used;
	}
	
	mmin = sum - used;
	for(int i = n; i >= 1; i--)
	{
		mmin = std::min(mmin, lst[i]);
		Min[i] = mmin;
	}
	
	used = 0;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == 'W')
		{
			long long fly = std::min(len[i] * 2, Min[i] - used);
			used += fly;
			ans -= fly;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}

//
// 
//