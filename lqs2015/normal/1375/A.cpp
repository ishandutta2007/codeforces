#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[111];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
		}
		for (int i=1;i<=n;i++)
		{
			if (i&1) printf("%d ",abs(a[i]));
			else printf("%d ",-abs(a[i]));
		}
		printf("\n");
	}
	return Accepted;
}