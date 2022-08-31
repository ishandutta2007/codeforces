#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int n,m,ans;
vector<int> v[100010];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;++i)
		ans+=v[i].size()%2;
	ans/=2;
	for (int i=1;i<=n;++i)
	{
		if (v[i].size()!=2) continue;
		int x=v[i][0],y=v[i][1];
		if (x==y)
		{
			v[x].clear();
			++ans;
			continue;
		}
		v[x][v[x][1]==i]=y;
		v[y][v[y][1]==i]=x;
	}
	cout<<ans<<" "<<m<<endl;
	return 0;
}