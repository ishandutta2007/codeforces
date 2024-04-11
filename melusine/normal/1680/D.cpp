#include<iostream>
#include<cstdio>
#include<cstring>
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
int qmax[100005],qmin[100005];
int a[100005];
signed main()
{
	int n,k;
	n=read();
	k=read();
	qmax[0]=qmin[0]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==0)
		{
			qmax[i]=qmax[i-1]+k;
			qmin[i]=qmin[i-1]-k;
		}
		else
		{
			qmax[i]=qmax[i-1]+a[i];
			qmin[i]=qmin[i-1]+a[i];
		}
	}
	if(qmin[n]>0||qmax[n]<0)
	{
		printf("-1\n");
		return 0;
	}
	int ans=0;
	for(int l=0;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			if(qmax[l]<0||qmax[n]-qmax[r]<0||qmin[r]-qmin[l]>0)continue; 
			//printf("%lld %lld %Lld\n",l,r,min(-qmin[r]+qmin[l],qmax[l]+qmax[n]-qmax[r]));
			ans=max(ans,min(-qmin[r]+qmin[l],qmax[l]+qmax[n]-qmax[r]));
		}
	}
	for(int i=1;i<=n;i++)
	{
		swap(qmin[i],qmax[i]);
		qmin[i]=-qmin[i];
		qmax[i]=-qmax[i];
	} 
	for(int l=0;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			if(qmax[l]<0||qmax[n]-qmax[r]<0||qmin[r]-qmin[l]>0)continue; 
			//printf("%lld %lld %Lld\n",l,r,min(-qmin[r]+qmin[l],qmax[l]+qmax[n]-qmax[r]));
			ans=max(ans,min(-qmin[r]+qmin[l],qmax[l]+qmax[n]-qmax[r]));
		}
	}
	printf("%lld\n",ans+1);
	return 0;
}