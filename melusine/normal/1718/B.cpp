#include<iostream>
#include<cstdio>
#include<map>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int fib[105],maxf;
int a[105];
signed main()
{
	int t,k,het=0,nsl=0,las,maxn,mpos;
	t=read();
	fib[1]=1;
	fib[2]=1;
	for(int i=3;;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		//printf("%lld %lld\n",i,fib[i]);
		if(fib[i]>1000000000)
		{
			maxf=i;
			break;
		}
	}
	//printf("%lld\n",maxf);
	for(int greg=1;greg<=t;greg++)
	{
		k=read();
		het=0;
		for(int i=1;i<=k;i++)
		{
			a[i]=read();
			het+=a[i];
		}
		nsl=0; 
		for(int i=1;i<=maxf;i++)
		{
			het-=fib[i];
			//printf("%lld\n",het);
			if(het==0)
			{
				nsl=i;
				break;
			}
			if(het<0)break;
		}
		//printf("%lld\n",nsl);
		if(nsl==0)
		{
			printf("No\n");
			continue;
		}
		las=0;
		maxn=0;
		mpos=0;
		bool flag=true;
		for(int i=nsl;i>=1;i--)
		{
			maxn=0;
			mpos=0;
			for(int j=1;j<=k;j++)
			{
				if(j==las)continue;
				if(a[j]>maxn)
				{
					maxn=a[j];
					mpos=j;
				}
			}
			if(maxn<fib[i])
			{
				flag=false;
				break;
			}
			a[mpos]-=fib[i];
			las=mpos;
		}
		if(flag==false)printf("No\n");
		else printf("Yes\n");
	}
}