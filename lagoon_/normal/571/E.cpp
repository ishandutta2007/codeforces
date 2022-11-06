#include<bits/stdc++.h>
#define re register
const int mod=1e9+7;
int a[110],b[110],a2[110],b2[110],n,n1,q[1000100],xa[110][110],xb[110][110],xc[110];
int xx,yy;
bool cp(re int b,re int c)
{
	if(b){xx=c/b;if(xx<0)puts("-1"),exit(0);return 1;}
	if(c)puts("-1"),exit(0);
	return 0;
}
int ex(re int a,re int b)
{
	re int ans=1;
	for(;b;b>>=1,a=(long long)a*a%mod)if(b&1)ans=(long long)ans*a%mod;
	return ans;
}
long long exgcd(re long long x,re long long y,re long long&a,re long long&b)
{
	if(!y){a=1;b=0;return x;}
	re long long k=exgcd(y,x%y,b,a);
	b-=(x/y)*a;
	return k;
}
long long mul(re long long a,re long long b,re long long p)
{
	re long long ans=0;
	for(;b;b>>=1,a=a*2%p)if(b&1)ans=(ans+a)%p;
	return ans;
}
bool eql(re int i,re int j)
{
	re int b=xb[1][1],a=-xb[j][1],c=xa[j][1]-xa[1][1];
	re int b1=xb[1][i],a1=-xb[j][i],c1=xa[j][i]-xa[1][i];
	if(!a&&cp(b,c))return 1;
	if(!a1&&cp(b1,c1))return 1;
	if((!b||!b1)&&(a||a1))
	{
		std::swap(xa[1],xa[j]);std::swap(xb[1],xb[j]);std::swap(a2[1],a2[j]);std::swap(b2[1],b2[j]);
		if(!b&&cp(a,c))return 1;
		if(!b1&&cp(a1,c1))return 1;
	}
	if(a*b1==a1*b)
	{
		if(a*c1==a1*c)return 0;
		puts("-1"),exit(0);
	}
	xx=(c*a1-c1*a)/(b*a1-b1*a);
	if(xx<0)puts("-1"),exit(0);
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);a2[i]=a[i];b2[i]=b[i];
		re int j=a[i];
		for(re int i1=2;i1*i1<=j;i1++)if(!(j%i1))
		{
			q[++n1]=i1;
			while(!(j%i1))j/=i1;
		}
		if(j!=1)q[++n1]=j;
		j=b[i];
		for(re int i1=2;i1*i1<=j;i1++)if(!(j%i1))
		{
			q[++n1]=i1;
			while(!(j%i1))j/=i1;
		}
		if(j!=1)q[++n1]=j;
	}
	std::sort(q+1,q+n1+1);
	n1=std::unique(q+1,q+n1+1)-q-1;
	if(n1>15)puts("-1"),exit(0);
	for(re int i=1;i<=n1;i++)
	{
		re int xx=q[i];
		for(re int j=1;j<=n;j++)while(!(a[j]%xx))a[j]/=xx,xa[j][i]++;
		for(re int j=1;j<=n;j++)while(!(b[j]%xx))b[j]/=xx,xb[j][i]++;
	}
	while(n1)
	{
		re int i=1;
		for(;i<=n;i++)
		{
			if(xb[i][1]!=0)break;
			if(i!=1&&xa[i][1]!=xa[i-1][1])puts("-1"),exit(0);
		}
		if(i<=n)break;
		for(i=1;i<=n;i++)std::swap(xa[i][1],xa[i][n1]),std::swap(xb[i][1],xb[i][n1]);
		n1--;
	}
	if(!n1)printf("%d",a2[1]),exit(0);
	for(re int i=2;i<=n1;i++)
	{
		for(re int j=2;j<=n;j++)if(eql(i,j))
		{
			xc[1]=xx;
			for(re int j1=2;j1<=n;j1++)xc[j1]=-1;
			for(re int i1=1;i1<=n1;i1++)
				for(re int j1=2;j1<=n;j1++)
				{
					if(xc[j1]==-1&&xb[j1][i1])
					{
						xc[j1]=(xb[1][i1]*xx+xa[1][i1]-xa[j1][i1])/xb[j1][i1];
						if(xc[j1]<0)puts("-1"),exit(0);
					}
					if(xb[1][i1]*xx+xa[1][i1]!=xb[j1][i1]*xc[j1]+xa[j1][i1])puts("-1"),exit(0);
				}
			re int ans=(long long)a2[1]*ex(b2[1],xx)%mod;
			printf("%d\n",ans);exit(0);
		}
	}
	for(re int i=1;i<=n;i++)if(xb[i][1]==0)
	{
		for(re int j=1;j<=n;j++)
		{
			if(xb[j][1]!=0){xx=(xa[i][1]-xa[j][1])/xb[j][1];if(xx<0)puts("-1"),exit(0);}
			if(xa[j][1]+xb[j][1]*xx!=xa[i][1])puts("-1"),exit(0);
		}
		for(re int j=1;j<=n;j++)if(xb[j][1]!=0)
		{
			xx=(xa[i][1]-xa[j][1])/xb[j][1];
			re int ans=(long long)a2[j]*ex(b2[j],xx)%mod;
			printf("%d\n",ans);exit(0);
		}
		printf("%d\n",a2[1]);exit(0);
	}
	re long long a=0,p=1,a1,p1,pp,aa,gd,xx1,yy1;
	for(re int i=1;i<=n;i++)
	{
		p1=xb[i][1];a1=xa[i][1]%p1;
		if(a>a1)std::swap(p,p1),std::swap(a,a1);
		gd=exgcd(p,p1,xx1,yy1);pp=p/gd*p1;
		if((a1-a)%gd)puts("-1"),exit(0);
		exgcd(p/gd,p1/gd,aa,xx1);aa=(aa+pp)%pp;
		aa=(mul(mul(aa,(a1-a)/gd,pp),p,pp)+a)%pp;
		a=aa;p=pp;
	}
	for(re int i=1;i<=n;i++)while(xa[i][1]>a)a+=p;
	re int ans=(long long)a2[1]*ex(b2[1],(a-xa[1][1])/xb[1][1]%(mod-1))%mod;
	printf("%d\n",ans);
}