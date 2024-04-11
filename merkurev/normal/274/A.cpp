#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

long long a[200500];
set <long long> cb;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);



	long long n, k;
	scanf("%I64d %I64d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i] );
		cb.insert(a[i] );
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		long long x = a[i];
		if (cb.count(x) == 0)
			continue;
		ans++;
		long long X = x * k;
		cb.erase(x * k);
	}
	printf("%I64d", ans);
	return 0;
}