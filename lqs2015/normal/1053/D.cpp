#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=2e6,mod=1e9+7;
int n,a[222222],mx[2222222],can[2222222];
int cnt[2222222],cur[2222222],f,fl;
vector<int> v;
vector<pair<int,int> > g[2222222];
long long ans;
multiset<int> s[2222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=maxn;i++)
	{
		if (mx[i]) continue; 
		for (int j=i+i;j<=maxn;j+=i) mx[j]=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (cnt[a[i]])
		{
			a[i]--;
			v.clear();
			while(mx[a[i]])
			{
				int x=mx[a[i]];
				v.push_back(x);
				while(a[i]%x==0)
				{
					cur[x]++;
					a[i]/=x;
				}
			}
			if (a[i]>1)
			{
				v.push_back(a[i]);
				cur[a[i]]++;
			}
			for (int j=0;j<v.size();j++)
			{
				cnt[v[j]]=max(cnt[v[j]],cur[v[j]]);
				g[i].push_back(make_pair(v[j],cur[v[j]]));
				cur[v[j]]=0;
			}
		}
		else 
		{
			cnt[a[i]]++;
			g[i].push_back(make_pair(a[i],1)); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			s[g[i][j].first].insert(g[i][j].second); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			s[g[i][j].first].erase(s[g[i][j].first].find(g[i][j].second));
		}
		fl=0;
		for (int j=0;j<g[i].size();j++)
		{
			if (can[g[i][j].first]<g[i][j].second && (s[g[i][j].first].empty() || *s[g[i][j].first].rbegin()<g[i][j].second)) 
			{
				fl=1;
				break;
			}
		}
		if (!fl) 
		{
			f=1;
			break;
		}
		for (int j=0;j<g[i].size();j++)
		{
			can[g[i][j].first]=max(can[g[i][j].first],g[i][j].second);
		}
	}
	ans=1;
	for (int i=2;i<=maxn;i++)
	{
		for (int j=1;j<=cnt[i];j++)
		{
			ans=ans*(long long)i%mod;
		}
	}
	ans=(ans+(long long)f)%mod;
	printf("%I64d\n",ans);
	return 0;
}