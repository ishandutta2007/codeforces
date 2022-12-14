#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int n,a[111111],mu[111111],prime[111111],cnt,b[2222222],crt,num,ct[222222];
long long ans;
vector<int> ys[111111];
bool f[111111];
bool cur[111111];
stack<int> s;
void Init()
{
	mu[1]=1;
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=cnt && prime[j]*i<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
	for (int i=1;i<=maxn;i++)
	{
		for (int j=i;j<=maxn;j+=i)
		{
			ys[j].push_back(i);
		}
	}
}
int main()
{
	Init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	cnt=unique(a+1,a+n+1)-a-1;
	for (int i=1;i<=cnt;i++)
	{
		for (int j=0;j<ys[a[i]].size();j++)
		{
			b[++crt]=ys[a[i]][j];
		}
	}
	sort(b+1,b+crt+1);
	crt=unique(b+1,b+crt+1)-b-1;
	for (int i=crt;i>=1;i--)
	{
		num=(int)s.size();
		for (int j=0;j<ys[b[i]].size();j++)
		{
			if (ys[b[i]][j]==1) continue;
			cur[ys[b[i]][j]]=1;
			num+=ct[ys[b[i]][j]]*mu[ys[b[i]][j]];
		}
		if (!num)
		{
			s.push(b[i]);
			for (int j=0;j<ys[b[i]].size();j++)
			{
				ct[ys[b[i]][j]]++;
				cur[ys[b[i]][j]]=0;
			}
			continue;
		}
		while(!s.empty())
		{
			int x=s.top();s.pop();
			for (int j=0;j<ys[x].size();j++)
			{
				ct[ys[x][j]]--;
				if (cur[ys[x][j]] && ys[x][j]!=1) num-=mu[ys[x][j]];
			}
			num--;
			if (!num)
			{
				ans=max(ans,1ll*b[i]*x);
				break;
			}
		}
		s.push(b[i]);
		for (int j=0;j<ys[b[i]].size();j++)
		{
			ct[ys[b[i]][j]]++;
			cur[ys[b[i]][j]]=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}