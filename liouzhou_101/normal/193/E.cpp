#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

long long gcd(long long a,long long b)
{
	return (!b)?a:gcd(b,a%b);
}

const long long pow1=8192;
const long long pow2=1953125;
const long long time1=12288;
const long long time2=7812500;
const long long time0=15000000000000LL;
const long long _GCD=gcd(time1,time2);
const long long _LCM=time1/_GCD*time2;
const long long MOD=10000000000000LL;

long long f,f1,f2;
vector<long long> v1,v2;
long long a[time2];

void build(long long f,long long p,long long t,vector<long long> &v)
{
	a[0]=0;
	a[1]=1;
	for (int i=2;i<t;++i)
	{
		a[i]=a[i-1]+a[i-2];
		if (a[i]>=p) a[i]-=p;
	}
	for (int i=0;i<t;++i)
		if (a[i]==f) v.push_back(i);
}

long long ans=time0;
long long A[2][2]={{1,1},{1,0}},v[2][2],t[2][2];

long long mul(long long a,long long b)
{
	long long ans=0;
	for (int i=0;i<=60;++i)
	{
		if (b&(1LL<<i))
			if ((ans+=a)>=MOD) ans-=MOD;
		if ((a+=a)>=MOD) a-=MOD;;
	}
	return ans;
}

void calc(long long n)
{
	if (!n)
	{
		memset(v,0,sizeof(v));
		v[0][0]=v[1][1]=1;
		return;
	}
	calc(n>>1);
	for (int i=0;i<2;++i)
		for (int j=0;j<2;++j)
		{
			t[i][j]=v[i][j];
			v[i][j]=0;
		}
	for (int i=0;i<2;++i)
		for (int j=0;j<2;++j)
			for (int k=0;k<2;++k)
			{
				v[i][j]+=mul(t[i][k],t[k][j]);
				if (v[i][j]>=MOD) v[i][j]-=MOD;
			}
	if (n&1)
	{
		for (int i=0;i<2;++i)
			for (int j=0;j<2;++j)
			{
				t[i][j]=v[i][j];
				v[i][j]=0;
			}
		for (int i=0;i<2;++i)
			for (int j=0;j<2;++j)
				for (int k=0;k<2;++k)
				{
					v[i][j]+=mul(t[i][k],A[k][j]);
					if (v[i][j]>=MOD) v[i][j]-=MOD;
				}
	}
}

void exgcd(long long a,long long b,long long &x,long long &y,long long t)
{
	if (!b)
	{
		x=t/a;
		y=0;
		return;
	}
	long long tx,ty;
	exgcd(b,a%b,tx,ty,t);
	x=ty;
	y=tx-a/b*ty;
}

void solve(long long x1,long long x2)
{
	long long tx=(x2-x1+_LCM)%_LCM;
	if (tx%_GCD) return;
	long long t1,t2;
	exgcd(time1,time2,t1,t2,tx);
	t1=(t1%_LCM+_LCM)%_LCM;
	for (long long index=(time1*t1+x1)%_LCM;index<time0;index+=_LCM)
	{
		calc((index)?index-1:_LCM-1);
		if (v[0][0]==f)
		{
			ans=min(ans,index);
			return;
		}
	}
}

int main()
{
	cin>>f;
	f1=f%pow1;
	f2=f%pow2;
	build(f1,pow1,time1,v1);
	build(f2,pow2,time2,v2);
	for (int i=0;i<v1.size();++i)
		for (int j=0;j<v2.size();++j)
			solve(v1[i],v2[j]);
	if (ans==time0) ans=-1;
	cout<<ans<<endl;
	return 0;
}