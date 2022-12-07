#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		int y, mn = 0x7f7f7f7f;
		for(int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			if(i == 1) y = x;
			else mn = min(mn, x);
		}
		if(y <= mn) puts("Bob");
		else puts("Alice");
	}
	return 0;
}