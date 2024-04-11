#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,m;
struct mat
{
	long long a[111][111];
	mat()
	{
		for (long long i=0;i<m;i++)
		{
			for (long long j=0;j<m;j++)
			{
				a[i][j]=(i==j);
			}
		}
	}
	mat operator * (const mat &u) const
	{
		mat res;
		for (long long i=0;i<m;i++)
		{
			for (long long j=0;j<m;j++)
			{
				res.a[i][j]=0;
				for (long long k=0;k<m;k++)
				{
					res.a[i][j]=(res.a[i][j]+a[i][k]*u.a[k][j])%mod;
				}
			}
		}
		return res;
	}
}ma;
mat binpow(mat a,long long t)
{
	mat res,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
int main()
{
	cin>>n>>m;
	memset(ma.a,0,sizeof(ma.a));
	for (long long i=1;i<m;i++)
	{
		ma.a[i][i-1]=1;
	}
	ma.a[0][m-1]=1;ma.a[0][0]=1;
	ma=binpow(ma,n);
	printf("%lld\n",ma.a[0][0]);
	return 0;
}