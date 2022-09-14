#include<cstdio>
using namespace std;
int ans[4<<17];
bool f(int a,int b,int c,int d)
{
	if(!(a+c==b+d||a+c==b+d+1))return false;
	if(a>b)
	{
		if(a==b+1&&c==0&&d==0)
		{
			for(int i=0;i<a;i++)ans[i*2]=0;
			for(int i=0;i<b;i++)ans[i*2+1]=1;
			return true;
		}
		return false;
	}
	for(int i=0;i<a;i++)ans[i*2]=0;
	for(int i=0;i<a;i++)ans[i*2+1]=1;
	for(int i=0;i<c;i++)ans[a*2+i*2]=2;
	int sz=a*2+1;
	for(int i=a;i<b;i++)
	{
		ans[sz]=1;
		sz+=2;
	}
	for(int i=0;i<d;i++)
	{
		ans[sz]=3;
		sz+=2;
	}
	return true;
}
main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int N=a+b+c+d;
	if(!f(a,b,c,d))
	{
		if(!f(d,c,b,a))
		{
			puts("NO");
			return 0;
		}
		for(int i=0;i<N;i++)ans[i]=3-ans[i];
	}
	puts("YES");
	for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
}