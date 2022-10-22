#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,k,m;
int a[5005];
ll dp[5005][5005];
deque <pair<ll,int> >que[5005];

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dp[0][0]=-1LL*inf*inf;
	dp[0][1]=a[0];
	que[1].push_back(mp(a[0],0));
	for(int i=1;i<n;i++)
	{
//		cout<<dp[i][0]<<endl;
		dp[i][0]=-1LL*inf*inf;
		dp[i][1]=(i<=k-1?a[i]:-1LL*inf*inf);
//		cout<<i<</*' '<<que[1].size()<<endl;*/' '<<(que[1].front().second)<<endl;
		for(int j=m;j>=2;j--)
		{
			dp[i][j]=-inf;
			while(que[j-1].size() && que[j-1].front().second<i-k)
			{
//				if(j-1==1) cout<<i<<endl;
				que[j-1].pop_front();
			}
			if(que[j-1].size()) dp[i][j]=que[j-1].front().first+a[i];
			if(dp[i][j]<0)
			{
				dp[i][j]=-1LL*inf*inf;
			}
			while(que[j].size() && que[j].back().first<dp[i][j])
			{
//				if(j==1) cout<<i<<endl;
				que[j].pop_back();
			}
			que[j].push_back(mp(dp[i][j],i));
//			for(int o=max(i-k,0);o<i;o++)
//			{
////				if(i<0 || j<0 || o<0 || j-1<0) cout<<"FUCK";
//				dp[i][j]=max(dp[i][j],dp[o][j-1]+a[i]);
//			}
/*
			while(que[j-1].front().second<i-k)
			{
				que[j-1].pop_front();
			}
//			cout<<j<<endl;
			dp[i][j]=que[j-1].front().first+a[i];
			while(!que[j].empty() && dp[i][j]>que[j].back().first)
			{
				que[j].pop_back();
			}
//			cout<<j<<endl;
			que[j].push_back(mp(dp[i][j],i));*/
		}
		if(i<=k-1)
		{
			while(que[1].size() && que[1].back().first<a[i])
			{
//				cout<<i<<endl;
				que[1].pop_back();
			}
			que[1].push_back(mp(a[i],i));
		}
	}
	ll res=-1;
//	for(int i=0;i<100;i+=100)
//	{
//		cout<<dp[i][m]<<endl;
//	}
	for(int i=n-k;i<n;i++)
	{
//		cout<<dp[i][m]<<endl;
		res=max(res,dp[i][m]);
	}
	cout<<max(res,-1LL)<<endl;
	return 0;
}