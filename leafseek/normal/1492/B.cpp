#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int arr[MaxN],Max[MaxN],val[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n;
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n)
		{
			scanf("%d",&arr[i]);
			Max[i]=max(Max[i-1],arr[i]);
		}
		register int Last=n+1,cur=0;
		dow(i,n,1)
		{
			if(!(Max[Last-1]==arr[i]))
				continue;
			rep(j,i,Last-1)
				val[++cur]=arr[j];
			Last=i;
		}
		rep(i,1,n)
			printf("%d ",val[i]);
		printf("\n");
	}
	return 0;
}