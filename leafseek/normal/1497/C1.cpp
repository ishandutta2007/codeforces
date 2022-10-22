#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n,m,k;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		dow(i,k,4)
			a[i]=1;
		n-=(k-3);
		if(n&1)
		{
			a[1]=(n>>1);
			a[2]=(n>>1);
			a[3]=1;
		}
		else
		{
			m=(n>>1);
			if(m&1)
			{
				a[1]=(m-1);
				a[2]=(m-1);
				a[3]=2;
			}
			else
			{
				a[1]=m;
				a[2]=(m>>1);
				a[3]=(m>>1);
			}
		}
		rep(i,1,k)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}