#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int N,M;
int s[5001];
int cL[5000],cR[5000];
int cc[5000][5005];
long long mod=1e9+7,anscnt;
int ans=-1;
int pre[5000];
int ac[5000];
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
pair<int,int>calc(int j,int l,int r)
{
	if(l>r)swap(l,r);
	int w=1,c=0;
	if(cc[j][l]>=1&&cc[j][r]>=2)
	{
		w=cc[j][l]*(cc[j][r]-1);
		c=2;
	}
	else if(cc[j][l]>=1&&cc[j][r]<2)
	{
		w=2;
		c=1;
	}
	else if(cc[j][l]<1&&cc[j][r]>=2)
	{
		w=cc[j][r];
		c=1;
	}
	else if(cc[j][l]<1&&cc[j][r]<2)
	{
		if(cc[j][r]>=1)
		{
			c=1;
		}
	}
	return make_pair(w,c);
}
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&s[i]);
		s[i]--;
	}
	for(int i=0;i<M;i++)
	{
		int f,h;scanf("%d%d",&f,&h);
		f--;
		cc[f][h]++;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<=N;j++)cc[i][j]+=cc[i][j-1];
	}
	for(int i=0;i<N;i++)cR[s[i]]++;
	int nowans=0;
	long long way=1;
	for(int i=0;i<=N;i++)
	{
		if(i==0)
		{
			for(int j=0;j<N;j++)
			{
				int l=cL[j],r=cR[j];
				pair<int,int>ret=calc(j,l,r);
				pre[j]=ret.first;
				ac[j]=ret.second;
				way=way*pre[j]%mod;
				nowans+=ac[j];
			}
			ans=nowans;
			anscnt=way;
		}
		else
		{
			int S=s[i-1];
			int l=cL[S]++,r=cR[S]--;
			pair<int,int>cr=calc(S,l,r-1);
			pair<int,int>cl=calc(S,l+1,r-1);
			way=way*power(pre[S],mod-2)%mod;
			pre[S]=cl.first;
			way=way*pre[S]%mod;
			nowans-=ac[S];
			ac[S]=cl.second;
			nowans+=ac[S];
			if(ans<nowans)
			{
				ans=nowans;
				anscnt=way;
			}
			else if(ans==nowans)
			{
				if(cr.second<cl.second)
				{
					anscnt=(anscnt+way)%mod;
				}
				else if(cr.first<cl.first)
				{
					anscnt=(anscnt+way*power(cl.first,mod-2)%mod*(cl.first-cr.first)%mod)%mod;
				}
			}
		}
	}
	printf("%d %lld\n",ans,anscnt);
}