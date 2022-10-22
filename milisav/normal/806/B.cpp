#include <bits\stdc++.h>
using namespace std;
long long int n;
long long a[150][5];
long long ma=1000000008;
bool moze(long long int m)
{
	long long int b=0,c=0;
	long long int v=0,p=0;
	long long int lb,ub;
	long long int cd=0;
	for(long long int j=0;j<5;j++)
	{
		c=n;
		for(long long int i=0;i<n;i++)
		{
			if(a[i][j]>=0) b++;
		}
		if((b)*2>m+c) ub=0;
		else
		{
			if((b)*4>m+c) ub=1;
			else
			{
				if((b)*8>m+c) ub=2;
				else
				{
					if((b)*16>m+c) ub=3;
					else
					{
						if((b)*32>m+c) ub=4;
						else ub=5;
					}
				}
			}
		}
		lb=ub;
		if(a[0][j]>=0)
		{
			if((m+b)*2>m+c) lb=0;
			else
			{
				if((m+b)*4>m+c) lb=1;
				else
				{
					if((m+b)*8>m+c) lb=2;
					else
					{
						if((m+b)*16>m+c) lb=3;
						else
						{
							if((m+b)*32>m+c) lb=4;
							else lb=5;
						}
					}
				}
			}
		}
		long long int bd;
		for(long long int k=lb;k<=ub;k++)
		{
			v=(a[0][j]>=0 ? 2*(k+1)*(250-a[0][j]) : 0);
			p=(a[1][j]>=0 ? 2*(k+1)*(250-a[1][j]) : 0);
			if(k==lb || v-p>bd) bd=v-p;
		}
		cd+=bd;
		b=0;
	}
	if(cd>0) return true;
	else return false;
}
long long int binary()
{
	long long int m=0;
	for(int m=0;m<=50*n;m++) if(moze(m)) return m;
	return -1;
}
bool ab()
{
	long long int b=0,c=0;
	long long int v=0,p=0;
	long long int cd=0;
	for(long long int j=0;j<5;j++)
	{
		for(long long int i=0;i<n;i++)
		{
			if(a[i][j]>=0) b++;
		}
		if((b)*2>n) c=0;
		else
		{
			if((b)*4>n) c=1;
			else
			{
				if((b)*8>n) c=2;
				else
				{
					if((b)*16>n) c=3;
					else
					{
						if((b)*32>n) c=4;
						else c=5;
					}
				}
			}
		}
		v=(a[0][j]>=0 ? 2*(c+1)*(250-a[0][j]) : 0);
		p=(a[1][j]>=0 ? 2*(c+1)*(250-a[1][j]) : 0);
		cd+=(v-p);
		b=0;
	}
	if(cd>0) return true;
	else return false;
}
int main()
{
	scanf("%lld",&n);
	for(long long int i=0;i<n;i++) scanf("%lld %lld %lld %lld %lld",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	if(ab()) printf("0");
	else printf("%lld",binary());
	return 0;
}