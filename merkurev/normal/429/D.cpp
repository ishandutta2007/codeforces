#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 1e5 + 100;
int a[maxn];

int inf = 1e9;
int n;

int getAns(int d)
{
	int answer = inf;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i + 1; j <= i + d && j < n; j++)
		{
			sum += a[j];
			if (abs(sum) > 1e4)
				continue;
			int d = j - i;
			int curans = d * d + sum * sum;
			answer = min(answer, curans);
		}
	}
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	int x = getAns(50);
	int d = 0;
	while (d * d <= x)
		d++;
	d = min(d, 3334);
	int ans = getAns(d);
	printf("%d\n", ans);
	return 0;
}