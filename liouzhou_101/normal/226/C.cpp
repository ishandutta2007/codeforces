#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

long long m,x,y,k;
long long A[2][2]={{1,1},{1,0}};
long long v[2][2],t[2][2];
long long get=1;

void check(long long p)
{
	if (y/p-(x-1)/p>=k) get=max(get,p);
}

void calc(long long n)
{
	if (n==1)
	{
		for (int i=0;i<2;++i)
			for (int j=0;j<2;++j)
				v[i][j]=A[i][j];
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
				(v[i][j]+=t[i][k]*t[k][j])%=m;
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
					(v[i][j]+=A[i][k]*t[k][j])%=m;
	}
}

int main()
{
	cin>>m>>x>>y>>k;
	long long p=sqrt(x);
	for (int i=1;i<=p;++i)
	{
		check(i);
		check(x/i);
	}
	p=sqrt(y);
	for (int i=1;i<=p;++i)
	{
		check(i);
		check(y/i);
	}
	if (get<=2)
		cout<<1%m<<endl;
	else
	{
		calc(get-2);
		cout<<(v[0][0]+v[0][1])%m<<endl;
	}
	return 0;
}