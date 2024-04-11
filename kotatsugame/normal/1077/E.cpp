#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
int dp[4<<17];
main()
{
	scanf("%d",&N);
	map<int,int>mp;
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		mp[A]++;
	}
	vector<int>C;
	for(pair<int,int>p:mp)C.push_back(p.second);
	sort(C.begin(),C.end());
	int ans=0;
	for(int i=C.size();i--;)
	{
		for(int j=1;j<=C[i];j++)
		{
			dp[j]=max(dp[j],j+dp[j*2]);
			ans=max(ans,dp[j]);
		}
	}
	printf("%d\n",ans);
}