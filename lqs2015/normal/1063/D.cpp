#include<iostream>
#include<cstdio>
using namespace std;
long long n,l,r,k,b,s,ans,re,up,b1,s1,d;
int main()
{
	cin>>n>>l>>r>>k;
	if (l<=r) b=r-l+1;
	else b=n-(l-r)+1;
	s=n-b;
	if (k<b) 
	{
		printf("-1\n");
		return 0;
	}
	ans=-1e9;
	if (n<=3000)
	{
		for (long long i=0;i<=s;i++)
		{
			for (long long j=d;j<=b;j++)
			{
				re=k-b-j;
				if (re<0) continue;
				if (re==0) ans=max(ans,i+j);
				else
				{
					if (re%(n+i+j)==0) ans=max(ans,i+j);
				}
			}
		}
	}
	else
	{
		for (long long x=0;x*n<=k;x++)
		{
			re=k-n*x-b;
			if (re<0) continue;
			if (!x)
			{
				if (re<=b && re>=d) ans=max(ans,re+s);
			}
			else
			{
				b1=re%x;s1=re/x-b1;
				if (s1<0 || b1>b) continue;
				if (s1<=s && b1>=d) ans=max(ans,b1+s1);
				else
				{
					long long del=(s1-s+x)/(x+1);
					b1+=del*x;s1-=del*(x+1);
					if (b1<=b && s1>0 && b1>=d) ans=max(ans,b1+s1);
				}
			}
		}
	}
	d=1;k++;
	if (n<=3000)
	{
		for (long long i=0;i<=s;i++)
		{
			for (long long j=d;j<=b;j++)
			{
				re=k-b-j;
				if (re<0) continue;
				if (re==0) ans=max(ans,i+j);
				else
				{
					if (re%(n+i+j)==0) ans=max(ans,i+j);
				}
			}
		}
	}
	else
	{
		for (long long x=0;x*n<=k;x++)
		{
			re=k-n*x-b;
			if (re<0) continue;
			if (!x)
			{
				if (re<=b && re>=d) ans=max(ans,re+s);
			}
			else
			{
				b1=re%x;s1=re/x-b1;
				if (s1<0 || b1>b) continue;
				if (s1<=s && b1>=d) ans=max(ans,b1+s1);
				else
				{
					long long del=(s1-s+x)/(x+1);
					b1+=del*x;s1-=del*(x+1);
					if (b1<=b && s1>0 && b1>=d) ans=max(ans,b1+s1);
				}
			}
		}
	}
	if (ans==-1e9) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}