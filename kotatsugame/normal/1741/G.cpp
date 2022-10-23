#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N,M,F,K;
vector<int>G[10000];
int H[10000];
bool ok[10000];
int P[6];
bool dp[1<<6];
queue<int>Q;
vector<int>f(int st)
{
	vector<int>ret(N,(int)1e9);
	Q.push(st);
	ret[st]=0;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for(int v:G[u])if(ret[v]>ret[u]+1)
		{
			ret[v]=ret[u]+1;
			Q.push(v);
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=0;i<M;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cin>>F;
		for(int i=0;i<F;i++)
		{
			cin>>H[i];
			H[i]--;
			ok[i]=true;
		}
		cin>>K;
		for(int i=0;i<K;i++)
		{
			cin>>P[i];
			P[i]--;
			ok[P[i]]=false;
		}
		vector<int>d0=f(0);
		sort(P,P+K,[&d0](int l,int r){return d0[H[l]]<d0[H[r]];});
		vector<vector<int> >dP(K);
		for(int i=0;i<K;i++)dP[i]=f(H[P[i]]);
		for(int i=0;i<1<<K;i++)dp[i]=false;
		dp[(1<<K)-1]=true;
		for(int u=0;u<F;u++)if(ok[u])
		{
			for(int i=0;i<1<<K;i++)if(dp[i])
			{
				for(int j=i;j>0;j=j-1&i)
				{
					bool ok=true;
					int from=-1;
					for(int k=0;k<K;k++)if(j>>k&1)
					{
						if(from==-1&&d0[H[P[k]]]+dP[k][H[u]]==d0[H[u]])from=k;
						else if(from!=-1&&dP[from][H[P[k]]]+dP[k][H[u]]==dP[from][H[u]])from=k;
						else
						{
							ok=false;
							break;
						}
					}
					if(ok)dp[i^j]=true;
				}
			}
		}
		int ans=K;
		for(int i=0;i<1<<K;i++)if(dp[i])ans=min(ans,__builtin_popcount(i));
		cout<<ans<<"\n";
	}
}