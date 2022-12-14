#include<bits/stdc++.h>
using namespace std;
int test,n,a[222222];
bool f;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		f=0;
		for (int i=2;i<=n;i++)
		{
			if (a[i]!=a[1]) f=1;
		}
		if (f) printf("1\n");
		else printf("%d\n",n);
	}
	return 0;
}