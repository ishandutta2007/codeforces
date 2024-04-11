#include<iostream>
#include<string>
using namespace std;
string c,s,ss;
int a[8008][8008],dp[8888],ls,z[8888],ro,r;
void z_func(string &s)
{
	int sz=s.size(),l,r,j,k;
	l=0;r=0;z[0]=sz;
	for (int i=1;i<sz;i++)
	{
		if (i>r)
		{
			for (j=0;j<sz;j++)
			{
				if (s[j]!=s[j+i]) break;
			}
			l=i;r=i+j-1;z[i]=j;
		}
		else
		{
			k=i-l;
			if (z[k]<r-i+1) 
			{
				z[i]=z[k];
			}
			else 
			{
				for (j=r;j<sz;j++)
				{
					if (s[j]!=s[j-i]) break;
				}
				l=i;r=j-1;z[i]=r-l+1;
			}
		}
	}
}
int len(int n)
{
	int res=0;
	while(n)
	{
		n/=10;
		res++;
	}
	return res;
}
int main()
{
	cin>>s;
	ls=s.size();
	for (int i=0;i<ls;i++)
	{
		ss=s.substr(i);
		z_func(ss);
		for (int j=1;j<=ls-i;j++)
		{
			ro=z[j]/j+1;r=i-1;
			for (int k=1;k<=ro;k++)
			{
				r+=j;
				a[i+1][r+1]=max(a[i+1][r+1],k);
			}
		}
	}
	for (int i=0;i<=ls;i++) dp[i]=1e9;
	dp[0]=0;
	for (int i=1;i<=ls;i++)
	{
		for (int j=0;j<i;j++)
		{
			dp[i]=min(dp[i],dp[j]+len(a[j+1][i])+(i-j)/a[j+1][i]);
		}
	}
	cout<<dp[ls]<<endl;
	return 0;
}