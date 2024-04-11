#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<pair<int,int> > v[99999];
vector<pair<int,int> > dp[99999];
const int md=20;
int buc1[20][20],buc2[20][20],buc3[20][20],buc4[20][20];
int n,m,p,x,cur;
int dist(int i,int j,int k,int l)
{
	return abs(i-k)+abs(j-l);
}
int main()
{
	cin>>n>>m>>p;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>x;
			v[x].push_back(make_pair(i,j)); 
		}
	}
	for (int i=0;i<v[1].size();i++)
	{
		dp[1].push_back(make_pair(dist(1,1,v[1][i].first,v[1][i].second),i)); 
	}
	for (int i=2;i<=p;i++)
	{
		sort(dp[i-1].begin(),dp[i-1].end());
		for (int j=0;j<v[i].size();j++)
		{
			cur=1e9;
			for (int k=0;k<min((int)v[i-1].size(),1000);k++)
			{
				cur=min(cur,dp[i-1][k].first+dist(v[i-1][dp[i-1][k].second].first,v[i-1][dp[i-1][k].second].second,v[i][j].first,v[i][j].second));
			}
			dp[i].push_back(make_pair(cur,j));
		}
	} 
	cout<<dp[p][0].first<<endl;
	return 0;
}