#include<iostream>
#include<vector>
using namespace std;
string A,B;
long long dp[3][5050];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,X,Y;
		cin>>N>>X>>Y;
		cin>>A>>B;
		vector<int>ids;
		for(int i=0;i<N;i++)if(A[i]!=B[i])
		{
			ids.push_back(i);
		}
		if(ids.size()%2==1)
		{
			cout<<"-1\n";
			continue;
		}
		if(Y<=X)
		{
			if(ids.size()==2&&ids[0]+1==ids[1])
			{
				if(ids[0]>=2||ids[1]+2<N)
				{
					cout<<min(Y*2,X)<<"\n";
				}
				else if(ids[0]==1&&ids[1]==N-2)
				{
					cout<<min((long long)Y*3,(long long)X)<<"\n";
				}
				else cout<<X<<"\n";
			}
			else cout<<(long long)Y*(ids.size()/2)<<"\n";
		}
		else
		{
			for(int j=0;j<3;j++)for(int i=0;i<=ids.size();i++)dp[j][i]=1e18;
			int now=0;
			dp[now][0]=0;
			for(int i=0;i<ids.size();i++)
			{
				int nxt=(now+1)%3;
				for(int j=0;j<2&&j<=ids.size();j++)
				{
					if(j>0)dp[nxt][j-1]=min(dp[nxt][j-1],dp[now][j]);
					if(j+1<=ids.size())dp[nxt][j+1]=min(dp[nxt][j+1],dp[now][j]+Y);
				}
				if(i+1<ids.size())
				{
					int nnxt=(nxt+1)%3;
					long long c=(long long)X*(ids[i+1]-ids[i]);
					for(int j=0;j<=ids.size();j++)dp[nnxt][j]=min(dp[nnxt][j],dp[now][j]+c);
				}
				for(int j=0;j<=ids.size();j++)dp[now][j]=1e18;
				now=nxt;
			}
			cout<<dp[now][0]<<"\n";
		}
	}
}