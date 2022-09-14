#include<cstdio>
using namespace std;
long long k,l,r,t,x,y;
bool vis[1<<20];
main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&k,&l,&r,&t,&x,&y);
	if(x>y)
	{
		if(k+y<=r)k+=y;
		k-=x;
		if(k<l)
		{
			puts("No");
			return 0;
		}
		long long d=x-y;
		long long day=(k-l)/d;
		puts(t-1<=day?"Yes":"No");
	}
	else if(x==y)
	{
		if(k+y<=r)k+=y;
		k-=x;
		puts(k<l?"No":"Yes");
	}
	else
	{
		if(l+x-1<r-y+1)
		{
			puts("Yes");
			return 0;
		}
		while(t>0)
		{
			if(l+x<=k)
			{
				long long d=(k-l-x)/x+1;
				t-=d;
				k-=d*x;
				if(t<=0)break;
			}
			if(vis[k-l])break;
			vis[k-l]=true;
			if(k+y<=r)
			{
				k+=y-x;
				t--;
			}
			else
			{
				puts("No");
				return 0;
			}
		}
		puts("Yes");
	}
}