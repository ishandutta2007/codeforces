#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		for (int i=n-1;i>=0;i--)
		printf("%d ",a[i]);
		printf("\n");
	}
}