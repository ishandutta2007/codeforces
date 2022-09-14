#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,Q;
vector<pair<int,char> >G[150000];
char edge[150000];
bool valid=true,two=false;
int outc;
inline int conv(char c)
{
	if(c=='?')return 0;
	else return c-'a'+1;
}
int cnt[150000][27];
pair<int,int>pr[150000];
int cntv[150000][2][27];
int usec[150000],chc[150000];
void dfs(int u,pair<int,int>p)
{
	pr[u]=p;
	pair<int,int>np=p;
	if(G[u].size()==2)
	{
		two=true;
		for(int i=0;i<2;i++)
		{
			np=make_pair(u,i);
			dfs(G[u][i].first,np);
		}
		int As=1,Bs=1;
		int v1=G[u][0].first,v2=G[u][1].first;
		for(int i=0;i<27;i++)
		{
			As+=cntv[u][0][i]=cnt[v1][i];
			Bs+=cntv[u][1][i]=cnt[v2][i];
		}
		cntv[u][0][conv(G[u][0].second)]++;
		cntv[u][1][conv(G[u][1].second)]++;
		if(As!=Bs)
		{
			valid=false;
			return;
		}
		int use=0;
		for(int i=1;i<27;i++)
		{
			cnt[u][i]=max(cntv[u][0][i],cntv[u][1][i]);
			use+=cnt[u][i];
		}
		cnt[u][0]=As-use;
		if(cnt[u][0]<0)outc++;
		chc[u]=As;
		usec[u]=use;
	}
	else if(u==0)
	{
		np=make_pair(u,0);
		int v=G[u][0].first;
		dfs(v,np);
		chc[0]=1;
		for(int i=0;i<27;i++)chc[0]+=cnt[u][i]=cnt[v][i];
		cnt[u][conv(G[u][0].second)]++;
	}
	else if(!G[u].empty())
	{
		int v=G[u][0].first;
		dfs(v,p);
		for(int i=0;i<27;i++)cnt[u][i]=cnt[v][i];
		cnt[u][conv(G[u][0].second)]++;
	}
}
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=1;i<N;i++)
	{
		int p;char c;
		scanf("%d %c",&p,&c);
		edge[i]=c;
		G[p-1].push_back(make_pair(i,c));
	}
	dfs(0,make_pair(-1,-1));
	for(;Q--;)
	{
		int p;char c;
		scanf("%d %c",&p,&c);p--;
		if(!valid)
		{
			puts("Fou");
			continue;
		}
		else if(!two)
		{
			cnt[0][conv(edge[p])]--;
			cnt[0][conv(edge[p]=c)]++;
			int ans=0;
			for(int i=1;i<27;i++)ans+=i*(cnt[0][i]+cnt[0][0]);
			printf("Shi %d\n",ans);
			continue;
		}
		else
		{
			int dec=conv(edge[p]),inc=conv(c);
			edge[p]=c;
			int u=p;
			while(pr[u].first>=0)
			{
				if(pr[u].first==0&&G[0].size()==1)
				{
					if(dec>=1)cnt[0][dec]--;
					if(inc>=1)cnt[0][inc]++;
					break;
				}
				else
				{
					int use=usec[pr[u].first];
					if(dec>=1&&cntv[pr[u].first][pr[u].second][dec]--==cnt[pr[u].first][dec]
						&&cnt[pr[u].first][dec]>cntv[pr[u].first][1-pr[u].second][dec])
					{
						cnt[pr[u].first][dec]--;
						use--;
					}
					else dec=0;
					if(inc>=1&&++cntv[pr[u].first][pr[u].second][inc]>cnt[pr[u].first][inc])
					{
						cnt[pr[u].first][inc]++;
						use++;
					}
					else inc=0;
					u=pr[u].first;
					if(cnt[u][0]<0)outc--;
					cnt[u][0]=chc[u]-use;
					if(cnt[u][0]<0)outc++;
					usec[u]=use;
				}
			}
			int sum=chc[0];
			for(int i=1;i<27;i++)sum-=cnt[0][i];
			cnt[0][0]=sum;
			if(outc!=0||cnt[0][0]<0)
			{
				puts("Fou");
			}
			else
			{
				int ans=0;
				for(int i=1;i<27;i++)ans+=i*(cnt[0][i]+cnt[0][0]);
				printf("Shi %d\n",ans);
			}
		}
	}
}