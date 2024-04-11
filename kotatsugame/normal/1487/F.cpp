#include<iostream>
#include<algorithm>
using namespace std;
const int off=300;
const int LIM=off*2+1;
int dp[60][LIM][LIM];
string sub(string A,string B)
{
	for(int i=A.size();i--;)
	{
		int j=A.size()-i-1;
		if(j<B.size())A[i]-=B[B.size()-j-1]-'0';
		if(A[i]<'0')
		{
			A[i]+=10;
			A[i-1]--;
		}
	}
	int id=0;
	while(A[id]=='0')id++;
	return A.substr(id);
}
int calc(string N)
{
	N="0"+N;
	for(int i=0;i<=N.size();i++)for(int j=0;j<LIM;j++)for(int k=0;k<LIM;k++)
	{
		dp[i][j][k]=1e9;
	}
	dp[0][off][off]=0;
	for(int i=0;i<N.size();i++)for(int j=0;j<LIM;j++)for(int k=0;k<LIM;k++)
	{
		int u=N[i]-'0';
		u+=(j-off)*10;
		u-=k-off;
		int l=max(u-off,-k);
		int r=min(u+off,2*off-k);
		for(int a=l;a<=r;a++)
		{
			dp[i+1][u-a+off][k+a]=min(dp[i+1][u-a+off][k+a],dp[i][j][k]+abs(a)*(int)(N.size()-i));
		}
	}
	int ans=1e9;
	for(int k=0;k<LIM;k++)ans=min(ans,dp[N.size()][off][k]);
	return ans;
}
main()
{
	string N;
	cin>>N;
	string u(N.size()+1,'1');
	cout<<min(calc(N),calc(sub(u,N))+(int)u.size())<<endl;
}