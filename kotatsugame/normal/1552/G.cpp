#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
using bit=unsigned long long;
int N,K;
bit I[10];
bit msk[10][41];
int cnt[10];
int usd[40];
void ans(bool flag)
{
	cout<<(flag?"ACCEPTED":"REJECTED")<<endl;
	exit(0);
}
void dfs(int k,bit now)
{
	if(k==K)
	{
		now++;
		bit low=now&-now;
		if(low!=now)ans(false);
	}
	else
	{
		int nc=__builtin_popcountll(now&I[k]);
		now&=~I[k];
		for(int i=0;i<=cnt[k];i++)
		{
			dfs(k+1,now|msk[k][nc+i]);
		}
	}
}
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)usd[i]=-1;
	for(int i=0;i<K;i++)
	{
		int q;cin>>q;
		vector<int>id(q);
		for(int j=0;j<q;j++)
		{
			cin>>id[j];
			id[j]--;
			I[i]|=1LL<<id[j];
			if(usd[id[j]]==-1)
			{
				usd[id[j]]=i;
				cnt[i]++;
			}
		}
		msk[i][0]=0;
		for(int j=0;j<q;j++)
		{
			msk[i][j+1]=msk[i][j]|1LL<<id[j];
		}
	}
	if(N==1)ans(true);
	for(int i=0;i<N;i++)if(usd[i]==-1)ans(false);
	dfs(0,0);
	ans(true);
}