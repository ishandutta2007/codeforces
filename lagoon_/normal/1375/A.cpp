#include<bits/stdc++.h>
#define re register
int main()
{
	re int n,t,x;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		for(re int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			printf("%d ",(i&1)?abs(x):(-abs(x)));
		}
		puts("");
	}
}