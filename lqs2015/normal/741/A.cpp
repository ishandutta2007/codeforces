#include<bits/stdc++.h>
using namespace std;
int n,nxt[111],a[111],cnt,num;
bool used[111],f;
long long ans,cur,apc;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&nxt[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			f=0;num=0;
			for (int j=i;;j=nxt[j])
			{
				if (used[j] && j!=i)
				{
					f=1;
					break;
				}
				if (used[j]) break;
				used[j]=1;
				num++;
			}
			if (f)
			{
				printf("-1\n");
				return 0;
			}
			a[++cnt]=num;
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		if (a[i]%2==0) a[i]/=2;
	}
	ans=1;
	for (int i=1;i<=cnt;i++) 
	{
		ans=lcm(ans,a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}