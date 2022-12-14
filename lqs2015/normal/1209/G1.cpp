#include<bits/stdc++.h>
using namespace std;
int n,q,a[222222],l[222222],r[222222],cnt,mx,ans,L;
vector<int> v[222222];
pair<pair<int,int>,int> b[222222];
vector<int> cur;
int get(int x,int l,int r)
{
	int p=lower_bound(v[x].begin(),v[x].end(),l)-v[x].begin();
	int q=lower_bound(v[x].begin(),v[x].end(),r+1)-v[x].begin();
	return q-p;
}
void process(int l,int r)
{
	int mx=0;
	for (int j=0;j<cur.size();j++)
	{
		mx=max(mx,get(cur[j],l,r));
	}
	ans+=(r-l+1-mx);
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
	}
	for (int i=1;i<=200000;i++) 
	{
		l[i]=1e9;r[i]=-1e9;
	}
	for (int i=1;i<=n;i++)
	{
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
	}
	for (int i=1;i<=200000;i++)
	{
		if (r[i]>0)
		{
			cnt++;
			b[cnt]=make_pair(make_pair(l[i],r[i]),i);
		}
	}
	sort(b+1,b+cnt+1);
	mx=b[1].first.second;cur.push_back(b[1].second);L=b[1].first.first;
	for (int i=2;i<=cnt;i++)
	{
		if (b[i].first.first>mx)
		{
			process(L,mx);
			mx=0;cur.clear();L=b[i].first.first;
		}
		mx=max(mx,b[i].first.second);cur.push_back(b[i].second);
	}
	if (L<=mx) process(L,mx);
	printf("%d\n",ans);
	return 0;
}