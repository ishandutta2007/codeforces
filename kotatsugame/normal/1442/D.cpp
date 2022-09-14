#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
vector<int>A[3030];
long long S[3030];
long long ans;
void f(int l,int r,vector<long long>dp)
{
	if(l+1==r)
	{
		long long s=0;
		ans=max(ans,dp[K]);
		for(int i=0;i<K&&i<A[l].size();i++)
		{
			s+=A[l][i];
			ans=max(ans,dp[K-i-1]+s);
		}
		return;
	}
	vector<long long>L=dp,R=dp;
	int mid=(l+r)/2;
	for(int i=l;i<mid;i++)
	{
		int T=A[i].size();
		for(int k=K-T;k>=0;k--)L[k+T]=max(L[k+T],L[k]+S[i]);
	}
	for(int i=mid;i<r;i++)
	{
		int T=A[i].size();
		for(int k=K-T;k>=0;k--)R[k+T]=max(R[k+T],R[k]+S[i]);
	}
	f(l,mid,R);
	f(mid,r,L);
}
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int T;scanf("%d",&T);
		A[i].reserve(T);
		for(int j=0;j<T;j++)
		{
			int a;scanf("%d",&a);
			A[i].push_back(a);
			S[i]+=a;
		}
	}
	vector<long long>dp(K+1,0);
	f(0,N,dp);
	printf("%lld\n",ans);
}