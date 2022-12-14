#include<bits/stdc++.h>
using namespace std;
int n,bit[444444],sz,a[222222],m,ans[222222],x,y,l,r,mid;
pair<int,int> b[222222];
vector<pair<int,int> > v[222222];
void update(int p)
{
	while(p<=sz)
	{
		bit[p]++;
		p+=p&(-p);
	}
}
int query(int p)
{
	int res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sz=1;
	while(sz<n) sz<<=1;
	for (int i=1;i<=n;i++) b[i]=make_pair(-a[i],i);
	sort(b+1,b+n+1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,i));
	}
	for (int i=1;i<=n;i++)
	{
		update(b[i].second);
		for (int j=0;j<v[i].size();j++)
		{
			int val=v[i][j].first,id=v[i][j].second;
			l=1;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (query(mid)<val) l=mid+1;
				else r=mid-1;
			}
			ans[id]=a[l];
		}
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}