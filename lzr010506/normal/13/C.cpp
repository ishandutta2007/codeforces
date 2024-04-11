#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	ll ans = 0;
	scanf("%d", &n);
	priority_queue<int> q;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		scanf("%d",&x);
		if (!q.empty() && q.top() > x)
		{
			ans += q.top() - x;
			q.pop();
			q.push(x);
		}
		q.push(x);
	}
	printf("%I64d\n", ans);
	return 0;
}