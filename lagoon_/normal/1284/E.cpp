#include<bits/stdc++.h>
#define re register
#define lb long long
struct pi
{
	lb x,y;
	pi operator+(const pi&A){return (pi){x+A.x,y+A.y};}
	pi operator-(const pi&A){return (pi){x-A.x,y-A.y};}
	lb operator*(const pi&A){return x*A.y-y*A.x;}
	pi operator*(re lb A){return (pi){x*A,y*A};}
	pi operator/(re lb A){return (pi){x/A,y/A};}
	pi rou(){return y>0||(y==0&&x>=0)?*this:(pi){-x,-y};}
}p[3010],q[3010];
bool in[3010];
inline bool cmp(pi A,pi B)
{
	return A.rou()*B.rou()>0;
}
int main()
{
	re int n,n1=0;
	scanf("%d",&n);
	re long long ans=0;
	for(re int i=1;i<=n;i++)scanf("%lld%lld",&p[i].x,&p[i].y);
	for(re int i=1;i<=n;i++)
	{
		re int x1=0;n1=0;
		for(re int j=1;j<=n;j++)if(i!=j)q[++n1]=p[j]-p[i];
		std::sort(q+1,q+n1+1,cmp);
		for(re int j=1;j<=n1;j++)
		{
			if(q[j].y>0||(q[j].y==0&&q[j].x>=0))in[j]=1;
			else in[j]=0;
			x1+=in[j];
		}
		for(re int j=1;j<=n1;j++)
		{
			x1-=in[j];in[j]^=1;
			ans-=1ll*x1*(x1-1)*(x1-2)/6;
			x1=n-2-x1;
			ans-=1ll*x1*(x1-1)*(x1-2)/6;
			x1=n-2-x1;x1+=in[j];
		}
	}
	ans/=2;
	ans+=1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/24;
	printf("%lld\n",ans);
}