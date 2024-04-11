#include<cstdio>
#include<vector>
using namespace std;
const long long mod=998244353;
const int W=100000,B=300;
const int off=B;
int N,K;
int b[W],sumb[W/B],q[W/B][2*off+1];
int dp[W+1];
void eval(int id)
{
	for(int i=0;i<=2*off;i++)q[id][i]=0;
	int t=0;
	for(int i=id*B+B-1;i>=id*B;i--)
	{
		t+=b[i];
		q[id][t+off]+=dp[i];
		if(q[id][t+off]>=mod)q[id][t+off]-=mod;
	}
	sumb[id]=t;
	for(int i=0;i<2*off;i++)
	{
		q[id][i+1]+=q[id][i];
		if(q[id][i+1]>=mod)q[id][i+1]-=mod;
	}
}
vector<int>ids[W];
main()
{
	scanf("%d%d",&N,&K);
	dp[0]=1;
	for(int i=0;i<N;i++)
	{
		if(i>0&&i%B==0)eval(i/B-1);
		int a;scanf("%d",&a);a--;
		if(ids[a].size()>=2)
		{
			int id=ids[a][ids[a].size()-2];
			b[id]=0;
			if(id/B<i/B)eval(id/B);
		}
		if(ids[a].size()>=1)
		{
			int id=ids[a].back();
			b[id]=-1;
			if(id/B<i/B)eval(id/B);
		}
		ids[a].push_back(i);
		b[i]=1;
		int id=i;
		int t=0;
		int now=0;
		do{
			t+=b[id];
			if(t<=K)
			{
				now+=dp[id];
				if(now>=mod)now-=mod;
			}
		}while(id--%B);
		while(id>=0)
		{
			int x=K-t;
			if(-off<=x)
			{
				now+=q[id/B][min(x,off)+off];
				if(now>=mod)now-=mod;
			}
			t+=sumb[id/B];
			id-=B;
		}
		dp[i+1]=now;
	}
	printf("%d\n",dp[N]);
}