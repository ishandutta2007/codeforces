#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		while (!s.empty())
		{
			ans = max(ans, s.top() ^ x);
			if (s.top() > x)
				break;
			s.pop();
		}
		s.push(x);
	}
	printf("%d", ans);
	return 0;
}