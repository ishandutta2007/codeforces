#include<bits/stdc++.h>
using namespace std;
int n,x,y,con[111111],p0,p1,s0,s1;
char s[111111];
long long cur,ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='0') con[i]=0;
		else if (s[i-1]=='1') con[i]=1;
		else con[i]=2;
	}
	scanf("%d%d",&x,&y);ans=1e18;
	if (x<y)//01
	{
		for (int i=1;i<=n;i++)
		{
			if (con[i]==1) 
			{
				p1++;
				cur+=(1ll*x*p0);
			}
			else
			{
				p0++;
				cur+=(1ll*y*p1);
			}
		}
		ans=cur;
		for (int i=n;i>=1;i--)
		{
			if (con[i]==2)
			{
				cur-=(1ll*x*s1+1ll*y*p1);
				cur+=(1ll*x*(p0-1)+1ll*y*s0);
				ans=min(ans,cur);
			}
			if (con[i]==0)
			{
				p0--;
				s0++;
			}
			else if (con[i]==1)
			{
				p1--;
				s1++;
			}
			else
			{
				p0--;
				s1++;
			}
		}
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (con[i]==1) 
			{
				p1++;
				cur+=(1ll*x*p0);
			}
			else
			{
				p0++;
				cur+=(1ll*y*p1);
			}
		}
		s0=p0;s1=p1;p0=p1=0;
		ans=cur;
		for (int i=1;i<=n;i++)
		{
			if (con[i]==2)
			{
				cur-=(1ll*x*s1+1ll*y*p1);
				cur+=(1ll*x*p0+1ll*y*(s0-1));
				ans=min(ans,cur);
			}
			if (con[i]==0)
			{
				s0--;
				p0++;
			}
			else if (con[i]==1)
			{
				s1--;
				p1++;
			}
			else
			{
				s0--;
				p1++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}