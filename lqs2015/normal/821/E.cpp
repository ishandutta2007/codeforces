#include<iostream>
using namespace std;
const long long mod=1e9+7;
long long n,k,a[111],b[111],c[111],sz,tim,lqs[111],ans,res[111];
struct mat
{
	long long ma[111][111];
	mat operator * (const mat &a) const
	{
		mat res;
		for (long long i=0;i<=sz;i++)
		{
			for (long long j=0;j<=sz;j++)
			{
				res.ma[i][j]=0LL;
				for (long long k=0;k<=sz;k++)
				{
					res.ma[i][j]=(res.ma[i][j]+ma[i][k]*a.ma[k][j])%mod; 
				}
			}
		}
		return res;
	} 
}aaa,pp;
mat qs(mat m,long long t)
{
	mat p=m,res;
	for (long long i=0;i<=sz;i++)
	{
		for (long long j=0;j<=sz;j++)
		{
			if (i==j) res.ma[i][j]=1LL;
			else res.ma[i][j]=0LL;
		}
	}
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
} 
int main()
{
	cin>>n>>k;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	lqs[0]=1LL;
	for (long long i=1;i<=n;i++)
	{
		sz=c[i];
		for (long long j=0;j<=sz;j++)
		{
			for (long long k=0;k<=sz;k++)
			{
				aaa.ma[j][k]=0LL;
			}
		}
		aaa.ma[0][0]=aaa.ma[0][1]=aaa.ma[sz][sz-1]=aaa.ma[sz][sz]=1LL;
		for (long long j=1;j<sz;j++) 
		{
			aaa.ma[j][j-1]=aaa.ma[j][j]=aaa.ma[j][j+1]=1LL;
		}
		if (i==n) tim=k-a[i];
		else tim=b[i]-a[i];
		pp=qs(aaa,tim);
		for (long long j=0;j<=sz;j++)
		{
			res[j]=0LL;
			for (long long k=0;k<=sz;k++)
			{
				res[j]=(res[j]+pp.ma[j][k]*lqs[k])%mod;
			}
		}
		for (long long j=0;j<=sz;j++) lqs[j]=res[j];
		for (long long j=sz+1;j<=15;j++) lqs[j]=0LL;
	}
	cout<<lqs[0]<<endl;
	return 0;
}