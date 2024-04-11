#include <iostream>
#include <algorithm>
using namespace std;
long long dp[11][64][1024];
string convert(long long n,int base)
{
	string ret="";
	while (n)
	{
		ret+=n%base+'0';
		n/=base;
	}
	reverse(ret.begin(),ret.end());
	int i=0;
	while (i<ret.size() && ret[i]=='0')
	i++;
	return ret.substr(i,ret.size());
}
int b;
string s;
long long go(int idx,int mask,int st,bool eq)
{
	if (idx==s.size())
	return (mask==0);
	if (!eq && !st)
	return dp[b][s.size()-idx][mask];
	long long ans=0;
	for (int i=st;i<=(eq? s[idx]-'0':b-1);i++)
	ans+=go(idx+1,mask^(1<<i),0,(eq && i==s[idx]-'0'));
	return ans;
}
long long go()
{
	long long ans=0;
	for (int i=0;i<s.size();i++)
	ans+=go(i,0,1,!i);
	return ans;
}
int main()
{
	for (int i=2;i<=10;i++)
	{
		dp[i][0][0]=1;
		for (int x=1;x<64;x++)
		{
			for (int mask=0;mask<1024;mask++)
			{
				for (int l=0;l<i;l++)
				dp[i][x][mask]+=dp[i][x-1][(mask^(1<<l))];
			}
		}
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		long long l,r;
		scanf("%I64d%I64d%I64d",&b,&l,&r);
		s=convert(r,b);
		long long ans=go();
		s=convert(l-1,b);
		ans-=go();
		printf("%I64d\n",ans);
	}
}