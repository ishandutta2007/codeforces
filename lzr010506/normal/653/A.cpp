#include <bits/stdc++.h>
using namespace std;
int n;
int a[100], b[100];
int cmp(int a, int b)
{
	return a < b;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
		scanf("%d",&a[i]);
	sort(a + 1, a + n + 1, cmp);
	for(int i = 2; i <= n; i ++)
	{
		int x, y, z;
		x = a[i];
		for(int j = i - 1; j >= 1; j --)
			if(a[j] == x) continue;
			else {x = a[j];break;}
		if(x == a[i]) continue;
		y = a[i];
		for(int j = i + 1; j <= n; j ++)
			if(a[j] == y) continue;
			else {y = a[j];break;}
		if(y == a[i]) continue;
		if(x == a[i] - 1 && y == a[i] + 1)
		{
			printf("YES\n");
			return 0;
		}
	}
		
	printf("NO\n");
	return 0;
}