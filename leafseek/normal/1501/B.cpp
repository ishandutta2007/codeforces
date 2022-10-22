#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5;
int a[MaxN];
bool usd[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n;
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n)
			scanf("%d",&a[i]);
		rep(i,1,n)
			usd[i]=false;
		dow(i,n,1)
		{
			a[i-1]=max(a[i]-1,a[i-1]);
			if(a[i]>=1)
				usd[i]=true;
		}
		rep(i,1,n)
			printf("%d ",usd[i]);
		printf("\n");
	}
	return 0;
}