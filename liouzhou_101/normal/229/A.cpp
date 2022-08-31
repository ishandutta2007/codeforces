#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=110;
const int MaxM=10010;
const int INF=1000000000;

int n,m;
vector<int> v[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		char s[MaxM];
		scanf("%s",s+1);
		for (int j=1;j<=m;++j)
			if (s[j]=='1') v[i].push_back(j);
		if (v[i].empty())
		{
			puts("-1");
			return 0;
		}
	}
	int ans=INF;
	for (int j=1;j<=m;++j)
	{
		int get=0;
		for (int i=1;i<=n;++i)
		{
			int t=lower_bound(v[i].begin(),v[i].end(),j)-v[i].begin();
			int now=INF;
			if (t<v[i].size())
				now=min(now,v[i][t]-j);
			else
				now=min(now,m-j+v[i][0]);
			if (t)
				now=min(now,j-v[i][t-1]);
			else
				now=min(now,m-v[i][v[i].size()-1]+j);
			get+=now;
		}
		ans=min(ans,get);
	}
	cout<<ans<<endl;
	return 0;
}