#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5;
int arr[MaxN];
int main()
{
	register int n,m,cnt0=0,cnt1=0,x;
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%d",&arr[i]);
		if(arr[i]==0) ++cnt0;
		else ++cnt1;
	}
	register int t,p;
	rep(i,1,m)
	{
		scanf("%d%d",&t,&p);
		if(t==1)
		{
			if(arr[p]==0)
				--cnt0,++cnt1;
			else
				++cnt0,--cnt1;
			arr[p]=1-arr[p];
		}
		else if(t==2)
		{
			if(cnt1>=p)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}