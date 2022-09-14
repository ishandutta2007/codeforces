#include<iostream>
#include<tuple>
#include<vector>
using namespace std;
int T,N,M;
string S;
tuple<int,int,int>memo2[10][10],memo3[10][10][10];
bool dp[1001];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		for(int i=0;i<10;i++)for(int j=0;j<10;j++)
		{
			memo2[i][j]=make_tuple(-1,-1,-1);
			for(int k=0;k<10;k++)memo3[i][j][k]=make_tuple(-1,-1,-1);
		}
		cin>>N>>M;
		for(int t=0;t<N;t++)
		{
			cin>>S;
			for(int i=0;i<M;i++)
			{
				if(i+1<M)
				{
					int a=S[i]-'0',b=S[i+1]-'0';
					if(get<0>(memo2[a][b])==-1)memo2[a][b]=make_tuple(i+1,i+2,t+1);
				}
				if(i+2<M)
				{
					int a=S[i]-'0',b=S[i+1]-'0',c=S[i+2]-'0';
					if(get<0>(memo3[a][b][c])==-1)memo3[a][b][c]=make_tuple(i+1,i+3,t+1);
				}
			}
		}
		cin>>S;
		for(int i=0;i<=M;i++)dp[i]=false;
		dp[0]=true;
		for(int i=0;i<M;i++)if(dp[i])
		{
			if(i+1<M)
			{
				int a=S[i]-'0',b=S[i+1]-'0';
				if(get<0>(memo2[a][b])!=-1)dp[i+2]=true;
			}
			if(i+2<M)
			{
				int a=S[i]-'0',b=S[i+1]-'0',c=S[i+2]-'0';
				if(get<0>(memo3[a][b][c])!=-1)dp[i+3]=true;
			}
		}
		if(!dp[M])
		{
			cout<<"-1\n";
			continue;
		}
		vector<tuple<int,int,int> >ans;
		int idx=M;
		while(idx>0)
		{
			if(idx>=2&&dp[idx-2])
			{
				int a=S[idx-2]-'0',b=S[idx-1]-'0';
				idx-=2;
				ans.push_back(memo2[a][b]);
				continue;
			}
			else
			{
				int a=S[idx-3]-'0',b=S[idx-2]-'0',c=S[idx-1]-'0';
				idx-=3;
				ans.push_back(memo3[a][b][c]);
			}
		}
		cout<<ans.size()<<"\n";
		for(int i=ans.size();i--;)cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<"\n";
	}
}