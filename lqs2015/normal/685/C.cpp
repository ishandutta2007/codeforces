#include<bits/stdc++.h>
using namespace std;
const long long inf=4e18;
long long t,n,x,y,z,l,r,mid,X,Y,Z,w;
long long a[111111],b[111111],c[111111],d[111111];
long long L[4],R[4],lm,rm;
void fuck(long long x,long long y,long long z)
{
	L[z]=max(L[z],x-y);
	R[z]=min(R[z],x+y);
}
bool check(long long mid)
{
	L[0]=L[1]=L[2]=L[3]=-inf;
	R[0]=R[1]=R[2]=R[3]=inf;
	for (long long i=1;i<=n;i++)
	{
		fuck(a[i],mid,0);
		fuck(b[i],mid,1);
		fuck(c[i],mid,2);
		fuck(d[i],mid,3);
	}
	for (long long i=0;i<4;i++)
	{
		if (L[i]>R[i]) return 0;
	}
	lm=max(L[0],L[1]+L[2]+L[3]);
	rm=min(R[0],R[1]+R[2]+R[3]);
	for (long long i=lm;i<=lm+20 && i<=rm;i++)
	{
		w=i;
		for (long long j=min(R[1],i-L[2]-L[3]);j>=min(R[1],i-L[2]-L[3])-20 && j>=L[1];j--)
		{
			if ((j&1)!=(w&1)) continue;
			for (long long k=min(R[2],i-j-L[3]);k>=min(R[2],i-j-L[3])-20 && k>=L[2];k--)
			{
				if ((k&1)!=(w&1)) continue;
				long long h=i-j-k;
				if ((h&1)!=(w&1) || (h<L[3] || h>R[3])) continue;
				X=j;Y=k;Z=h;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for (long long i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i]=x+y+z;b[i]=x+y-z;c[i]=x-y+z;d[i]=-x+y+z;
		}
		l=0;r=inf;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (check(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%lld %lld %lld\n",(X+Y)/2,(X+Z)/2,(Y+Z)/2);
	}
	return 0;
}