#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
int dp[3005][3005],z[3005];
void Z(string s)
{
	reverse(s.begin(),s.end());
	int l,r;
	l=r=0;
	z[0]=s.size();
	for (int i=1;i<s.size();i++)
	{
		if (i>r)
		{
			l=r=i;
			while (r<s.size() && s[r]==s[r-l])
			r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if (z[k]<r-i+1)
			z[i]=z[k];
			else
			{
				l=i;
				while (r<s.size() && s[r]==s[r-l])
				r++;
				z[i]=r-l;
				r--;
			}
		}
	}
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	string s="";
	for (int r=1;r<=n;r++)
	{
		getchar();
		char c=getchar();
		s+=c;
		Z(s);
		int mx=0;
		for (int i=1;i<r;i++)
		mx=max(mx,z[i]);
		dp[r][r-1]=1;
		for (int l=r;l>0;l--)
		{
			int cur=1;
			for (int m=r;m>=max(r-3,l);m--)
			{
				cur=cur*2+s[m-1]-'0';
				if (cur!=28 && cur!=26 && cur!=23 && cur!=31)
				dp[l][r]=(dp[l][r]+dp[l][m-1])%mod;
			}
			if (l<=r-mx)
			ans=(ans+dp[l][r])%mod;
		}
		printf("%d\n",ans);
	}
}