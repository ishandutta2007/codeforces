#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
const int maxn=630,INF=1e9;
int prime[666],cnt,ans,st[666],cs,test,arr[666],res;
vector<int> v;
bool f[1111];
long long cur,rr;
void Init()
{
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}
int ask(long long x)
{
	int res;
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int main()
{
	Init();
	cur=1;st[cs=1]=1;
	for (int i=1;i<=cnt;i++)
	{
		if (cur>inf/prime[i]) 
		{
			st[++cs]=i;
			cur=1;
		}
		cur*=prime[i];
	}
	st[++cs]=cnt+1;
	scanf("%d",&test);
	while(test--)
	{
		v.clear();
		for (int i=1;i<cs;i++)
		{
			cur=1;
			for (int j=st[i];j<st[i+1];j++)
			{
				cur*=prime[j];
			}
			ans=ask(cur);
			for (int j=st[i];j<st[i+1];j++)
			{
				if (ans%prime[j]==0)
				{
					v.push_back(j);
				}
			}
		}
		memset(arr,0,sizeof(arr));
		for (int i=0;i<v.size();i+=2)
		{
			cur=1;
			while(1)
			{
				if (cur*prime[v[i]]>INF) break;
				cur*=prime[v[i]];
			}
			rr=cur;
			if (i+1<v.size())
			{
				cur=1;
				while(1)
				{
					if (cur*prime[v[i+1]]>INF) break;
					cur*=prime[v[i+1]];
				}
				rr*=cur;
			}
			ans=ask(rr);
			while(ans%prime[v[i]]==0)
			{
				ans/=prime[v[i]];
				arr[i]++;
			}
			if (i+1<v.size())
			{
				while(ans%prime[v[i+1]]==0)
				{
					ans/=prime[v[i+1]];
					arr[i+1]++;
				}
			}
		}
		res=1;
		for (int i=0;i<v.size();i++) res*=(arr[i]+1);
		if (res==1) answer(8);
		else if (res==2) answer(9);
		else answer(res<<1);
	}
	return 0;
}