#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long mod=1e9+7;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int N;
long long X[1<<17];
vector<int>G[1<<17];
long long ans;
void dfs(int u,int p,vector<pair<long long,int> >A)
{
	long long now=X[u];
	vector<pair<long long,int> >B;
	B.push_back(make_pair(now,1));
	(ans+=now)%=mod;
	for(int i=(int)A.size()-1;i>=0;i--)
	{
		long long tmp=now;
		now=gcd(now,A[i].first);
		(ans+=now%mod*A[i].second)%=mod;
		if(tmp!=now)B.push_back(make_pair(now,A[i].second));
		else B.back().second+=A[i].second;
	}
	reverse(B.begin(),B.end());
	for(int v:G[u])
	{
		if(v!=p)dfs(v,u,B);
	}
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%I64d",X+i);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<pair<long long,int> >dammy;
	dfs(0,-1,dammy);
	printf("%lld\n",ans);
}