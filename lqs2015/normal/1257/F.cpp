#include<bits/stdc++.h>
using namespace std;
const int mod1=1e9+7,mod2=998244353,p=993217;//993217 give me power!
int n,a[111],num[111],cur1,cur2;
map<pair<int,int>,int> mp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0;i<(1<<15);i++)
	{
		memset(num,0,sizeof(num));
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<15;k++)
			{
				if ((i&(1<<k)) && !(a[j]&(1<<k))) num[j]++;
				if (!(i&(1<<k)) && (a[j]&(1<<k))) num[j]++;
			}
		}
		for (int j=2;j<=n;j++) num[j]-=num[1];
		num[1]=0;
		cur1=cur2=0;
		for (int j=1;j<=n;j++)
		{
			cur1=(1ll*cur1*p+num[j]+1319)%mod1;
			cur2=(1ll*cur2*p+num[j]+1319)%mod2;
		}
		mp[make_pair((cur1+mod1)%mod1,(cur2+mod2)%mod2)]=i;
	}
	for (int i=0;i<(1<<15);i++)
	{
		memset(num,0,sizeof(num));
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<15;k++)
			{
				if ((i&(1<<k) && !(a[j]&(1<<(15+k))))) num[j]++;
				if (!(i&(1<<k)) && (a[j]&(1<<(15+k)))) num[j]++;
			}
		}
		for (int j=2;j<=n;j++) num[j]=num[1]-num[j];
		num[1]=0;
		cur1=cur2=0;
		for (int j=1;j<=n;j++)
		{
			cur1=(1ll*cur1*p+num[j]+1319)%mod1;
			cur2=(1ll*cur2*p+num[j]+1319)%mod2;
		}
		cur1=(cur1+mod1)%mod1;cur2=(cur2+mod2)%mod2;
		if (mp.find(make_pair(cur1,cur2))!=mp.end())
		{
			printf("%d\n",(i<<15)+mp[make_pair(cur1,cur2)]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}