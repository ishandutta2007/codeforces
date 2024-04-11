#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int>G[1010];
int n;
bool f(int u,int p)
{
	bool ans=true;int cnt=0;
	for(int i=0;i<G[u].size();i++)
	{
		if(G[G[u][i]].size()>0)
		{
			ans&=f(G[u][i],u);
		}
		else
		{
			cnt++;
		}
	}
	return cnt>=3&&ans;
}
main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a;scanf("%d",&a);
		a--;G[a].push_back(i);
	}
	cout<<(f(0,-1)?"Yes":"No")<<endl;
}