#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,R;
int dp[111];
main()
{
	scanf("%d%d",&N,&R);
	vector<pair<int,int> >A,B;
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b>=0)A.push_back(make_pair(a,b));
		else B.push_back(make_pair(a,b));
	}
	sort(A.begin(),A.end());
	int acnt=0;
	for(pair<int,int>a:A)
	{
		if(R<a.first)
		{
			continue;
		}
		R+=a.second;
		acnt++;
	}
	sort(B.begin(),B.end(),[](pair<int,int>a,pair<int,int>b)
	{
		return a.first+a.second>b.first+b.second;
	});
	for(int i=0;i<=B.size();i++)dp[i]=-1;
	dp[0]=R;
	for(int i=0;i<B.size();i++)
	{
		for(int k=i;k>=0;k--)if(dp[k]>=B[i].first)
		{
			dp[k+1]=max(dp[k+1],dp[k]+B[i].second);
		}
	}
	int bcnt=0;
	for(int k=0;k<=B.size();k++)if(dp[k]>=0)bcnt=k;
	printf("%d\n",acnt+bcnt);
}