#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

std::vector<int> v1, v2;

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		int x = (int)(sqrt(a) + 1e-8);
		if(x * x == a)
		{
			if(a != 0) v1.push_back(1);
			else v1.push_back(2);
		}
		else
		{
			v2.push_back(std::min(a - x * x, (x + 1) * (x + 1) - a));
		}
	}
	long long ans = 0;
	if(v1.size() > n / 2)
	{
		std::sort(v1.begin(), v1.end());
		for(int i = 0; i < v1.size() - (n / 2); i++) ans += v1[i];
	}
	else
	{
		std::sort(v2.begin(), v2.end());
		for(int i = 0; i < v2.size() - (n / 2); i++) ans += v2[i];
	}
	printf("%lld\n", ans);
}