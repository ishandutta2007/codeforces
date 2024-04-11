#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,cnt,l,r,flg,mx;
const int maxn=1e9,md=5e5+3;
long long ans[333333];
vector<pair<int,int> > v[555555];
pair<pair<int,int>,pair<int,int> > a[333333];
void process(int mul,int flg,int x)
{
	int cur=x%md;
	for (int j=0;j<v[cur].size();j++)
	{
		if (v[cur][j].first==x)
		{
			if (flg>0)
			{
				ans[v[cur][j].second]-=mul;
				ans[++v[cur][j].second]+=mul;
			}
			else
			{
				ans[v[cur][j].second]-=mul;
				ans[--v[cur][j].second]+=mul;
			}
			if (!v[cur][j].second) v[cur].erase(v[cur].begin()+j);
			return;
		}
	}
	v[cur].push_back(make_pair(x,1));
	ans[1]+=mul; 
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		x+=maxn;y+=maxn;
		a[++cnt]=make_pair(make_pair(x,1),make_pair(y,y+k-1));
		a[++cnt]=make_pair(make_pair(x+k,-1),make_pair(y,y+k-1));
	}
	sort(a+1,a+cnt+1);
	mx=a[cnt].first.first;
	for (int i=1;i<=cnt;i++)
	{
		x=a[i].first.first;flg=a[i].first.second;l=a[i].second.first;r=a[i].second.second;
		for (int j=l;j<=r;j++)
		{
			process(mx-x+1,flg,j);
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}