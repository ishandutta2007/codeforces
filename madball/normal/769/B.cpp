#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> ar(n);
	vector<int> sorted;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &ar[i]);
		sum += ar[i];
		if (ar[i] > 0)
			sorted.push_back(i);
	}
	for (int i = 0; i < n; ++i)
		if (ar[i] == 0)
			sorted.push_back(i);
	if (sum < n - 1 || ar[0] == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n", n - 1);
		int cur = 0;
		for (int i = 1; i < n; ++i)
		{
			printf("%d %d\n", sorted[cur] + 1, sorted[i] + 1);
			if (--ar[sorted[cur]] == 0)
				++cur;
		}
	}
	return 0;
}