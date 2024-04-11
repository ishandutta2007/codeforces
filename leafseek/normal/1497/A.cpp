#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN];
bool usd[MaxN],flag[MaxN],pre[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n;
	while(T--)
	{
		scanf("%d",&n);
		rep(i,0,n)
			usd[i]=flag[i]=pre[i]=false;
		rep(i,1,n)
			scanf("%d",&a[i]),usd[a[i]]=true;
		register int Mex=0;
		while(usd[Mex])
			++Mex;
		sort(a+1,a+n+1);
		rep(i,1,n)
		{
			if(flag[a[i]])
				continue;
			if(a[i]>=Mex)
				break;
			flag[a[i]]=true,pre[i]=true;
		}
		rep(i,1,n)
			if(pre[i])
				printf("%d ",a[i]);
		rep(i,1,n)
			if(!pre[i])
				printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}