#include<iostream>
#include<algorithm>
using namespace std;
int T,N,M;
int X[10];
string S[10];
int ans[10000];
pair<int,int>coef[10000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)cin>>X[i];
		for(int i=0;i<N;i++)cin>>S[i];
		int score=-2e9;
		for(int i=0;i<1<<N;i++)
		{
			int now=0;
			for(int j=0;j<N;j++)now+=i>>j&1?X[j]:-X[j];
			for(int k=0;k<M;k++)coef[k]=make_pair(0,k);
			for(int j=0;j<N;j++)
			{
				int add=i>>j&1?-1:1;
				for(int k=0;k<M;k++)if(S[j][k]=='1')coef[k].first+=add;
			}
			sort(coef,coef+M);
			for(int k=0;k<M;k++)now+=(k+1)*coef[k].first;
			if(score<now)
			{
				score=now;
				for(int k=0;k<M;k++)ans[coef[k].second]=k+1;
			}
		}
		for(int i=0;i<M;i++)cout<<ans[i]<<(i+1==M?"\n":" ");
	}
}