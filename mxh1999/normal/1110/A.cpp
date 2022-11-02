#include<bits/stdc++.h>
using namespace std;

int b,k;
int a[100010];
int main()
{
	scanf("%d%d",&b,&k);
	for (int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	int ans=0;
	if (b&1)
	{
		for (int i=1;i<=k;i++)
			ans^=(a[i]&1);
	}	else	ans=(a[k]&1);
	if (ans)	printf("odd\n");else printf("even\n");
	return 0;
}