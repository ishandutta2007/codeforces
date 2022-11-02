#include <bits/stdc++.h>
using namespace std;
int G[70][70];
int n,m,k;
int dp[5000];

void knapsack(int row, vector<int> &v)
{
    int i,j;
	for(i=0;i<5000;i++)
	{
		dp[i] = -1;
	}
	dp[0] = 0;
	for(i=0;i<m;i++)
	{
		for(j=4999;j>=0;j--)
		{
			if(dp[j]>=0 && dp[j] < m/2)
			{
			    if(dp[j+G[row][i]] != -1)
				    dp[j+G[row][i]] = min(dp[j+G[row][i]], dp[j]+1);
				else
				    dp[j+G[row][i]] = dp[j]+1;
			}
		}
	}
	map<int,int> mp;
	for(i=4999;i>=0;i--)
	{
		if(dp[i]>=0 && mp.count(i%k)==0)
		{
		    //cout<<i<<' '<<row<<endl;
			mp.insert({i%k,dp[i]});
			v.push_back(i);
		}
	}
	//cout<<"Done with row "<<row<<endl;
}

set<int> reach[71];
vector<int> ks[71];

int main() {
	int i,j;
	cin>>n>>m>>k;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>G[i][j];
	
	for(i=0;i<n;i++)
		knapsack(i,ks[i]);
	
	
	reach[0].insert(0);
	for(i=1;i<=n;i++)
	{
		auto it = reach[i-1].begin();
		while(it != reach[i-1].end())
		{
			int cur_val = *it;
			//cout<<i<<' '<<cur_val<<endl;
			for(auto e: ks[i-1])
			{
			    //cout<<e<<endl;
				if(reach[i].count(cur_val + e) == 0)
					reach[i].insert(cur_val+e);
			}
			it++;
		}
	}
	int maxi=0;
	auto it = reach[n].begin();
	while(it != reach[n].end())
	{
		int val = *it;
		if(val%k==0)
			maxi = val;
		it++;
	}
	cout<<maxi;
	return 0;
}