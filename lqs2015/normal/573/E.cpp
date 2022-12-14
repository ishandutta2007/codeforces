#include<iostream>
#include<cstdio>
using namespace std;
const long long threshold=20;
long long n,a[111111],bit1[444444],bit2[444444],sz,cnt,ans;
bool f[111111];
void update(long long p,long long x,long long *bit)
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
long long query(long long p,long long *bit)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sz=1;
	while(sz<n) sz*=2;
	for (long long i=1;i<=n;i++) update(i,1,bit1);
	for (long long i=1;i<=n;i++) update(sz-i+1,a[i],bit2);
	for (long long i=1;i<=n;i++) f[i]=1;
	for (long long i=1;i<=threshold;i++)
	{
		for (long long j=1;j<=n;j++) 
		{
			if (f[j])
			{
				if (-a[j]*query(j,bit1)-query(sz-j,bit2)>0)
				{
					f[j]=0;
					update(j,-1,bit1);
					update(sz-j+1,-a[j],bit2);
				}
			}
			else
			{
				if (a[j]*(query(j,bit1)+1)+query(sz-j,bit2)>0)
				{
					f[j]=1;
					update(j,1,bit1);
					update(sz-j+1,a[j],bit2);
				}
			}
		}
		for (long long j=n;j>=1;j--) 
		{
			if (f[j])
			{
				if (-a[j]*query(j,bit1)-query(sz-j,bit2)>0)
				{
					f[j]=0;
					update(j,-1,bit1);
					update(sz-j+1,-a[j],bit2);
				}
			}
			else
			{
				if (a[j]*(query(j,bit1)+1)+query(sz-j,bit2)>0)
				{
					f[j]=1;
					update(j,1,bit1);
					update(sz-j+1,a[j],bit2);
				}
			}
		}
	}
	for (long long i=1;i<=n;i++)
	{
		if (f[i])
		{
			cnt++;
			ans+=a[i]*cnt;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}