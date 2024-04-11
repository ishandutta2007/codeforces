#include <bits/stdc++.h>
using namespace std;
char buf[300005];
int par[300005],con[300005],cnt[2][300005],col[300005],f[300005];
vector<int> v[300005],s[300005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y,int c)
{
	c^=(col[x]==col[y]);
	x=find(x);
	y=find(y);
	if (s[x].size()>s[y].size())
	swap(x,y);
	par[x]=y;
	for (int i:s[x])
	{
		col[i]^=c;
		s[y].push_back(i);
	}
	cnt[0][y]+=cnt[c][x];
	cnt[1][y]+=cnt[(c^1)][x];
	if (f[x]!=-1)
	f[y]=(f[x]^c);
	if (f[y]==-1)
	con[y]=min(cnt[0][y],cnt[1][y]);
	else
	con[y]=cnt[f[y]][y];
}
int main()
{
	int n,k,ans=0;
	scanf("%d%d %s",&n,&k,buf);
	string ss(buf);
	for (int i=0;i<k;i++)
	{
		int c;
		scanf("%d",&c);
		while (c--)
		{
			int a;
			scanf("%d",&a);
			v[a].push_back(i);
		}
		s[i].push_back(i);
		par[i]=i;
		cnt[0][i]=1;
		f[i]=-1;
	}
	for (int i=1;i<=n;i++)
	{
		if (v[i].empty())
		goto out;
		if (v[i].size()==1)
		{
			int tmp=find(v[i][0]);
			ans-=con[tmp];
			f[tmp]=(col[v[i][0]]^(ss[i-1]=='1'));
			con[tmp]=cnt[f[tmp]][tmp];
			ans+=con[tmp];
		}
		else
		{
			if (find(v[i][0])==find(v[i][1]))
			goto out;
			ans-=con[find(v[i][0])];
			ans-=con[find(v[i][1])];
			Union(v[i][0],v[i][1],ss[i-1]-'0');
			ans+=con[find(v[i][0])];
		}
		out: printf("%d\n",ans);
	}
}