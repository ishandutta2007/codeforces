#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
struct jz
{
	int a[7][7];
};
int mod;
struct jz operator*(struct jz x,struct jz y)
{
	struct jz ans;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			ans.a[i][j]=0;
			for(int k=1;k<=6;k++)
			{
				ans.a[i][j]=(ans.a[i][j]+1LL*x.a[i][k]*y.a[k][j]%mod)%mod;
			}
		}
	}
	return ans;
}
struct jz ksm(struct jz n,int k)
{
	struct jz ans;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			if(i==j)ans.a[i][j]=1;
			else ans.a[i][j]=0;
		}
	}
	while(k>=1)
	{
		if(k&1)ans=ans*n;
		k>>=1;
		n=n*n;
	}
	return ans;
}
struct jz sth;
int xl[7];
signed main()
{
	int sx,sy,dx,dy,t;
	mod=read();
	sx=read();
	sy=read();
	dx=read();
	dy=read();
	t=read();
	sth.a[1][1]=3;
	sth.a[2][1]=1;
	sth.a[3][1]=mod-1;
	sth.a[5][1]=1;
	sth.a[1][2]=1;
	sth.a[2][2]=3;
	sth.a[4][2]=mod-1;
	sth.a[5][2]=1;
	sth.a[1][3]=1;
	sth.a[2][4]=1;
	sth.a[6][6]=1;
	sth.a[6][5]=1;
	sth.a[5][5]=1;
	sth=ksm(sth,t);
	xl[1]=sx;
	xl[2]=sy;
	xl[3]=(sx-dx+mod)%mod;
	xl[4]=(sy-dy+mod)%mod;
	xl[5]=0;
	xl[6]=1;
	int ansx=0,ansy=0;
	for(int i=1;i<=6;i++)
	{
		ansx=(ansx+1LL*xl[i]*sth.a[i][1]%mod)%mod;
		ansy=(ansy+1LL*xl[i]*sth.a[i][2]%mod)%mod;
		//printf("%lld %lld\n",ansx,ansy);
		//printf("%lld ",xl[i]);
	}
	//printf("\n");
	printf("%lld %lld\n",(ansx+mod-1)%mod+1,(ansy+mod-1)%mod+1);
	return 0;
}