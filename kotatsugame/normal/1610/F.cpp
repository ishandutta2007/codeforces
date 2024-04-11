#include<iostream>
#include<vector>
using namespace std;
int N,M;
int U[3<<17],V[3<<17],W[3<<17];
int dir[3<<17];
struct dat{
	int u,v;
	vector<int>ei;
};
vector<pair<int,int> >G[3<<17];
int vis[3<<17];
bool usd[3<<17];
int ch[3<<17];
int dfs1(int u)
{
	vis[u]=1;
	ch[u]=G[u].size()%2;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		if(vis[v]!=0)continue;
		ch[u]+=dfs1(v);
	}
	return ch[u];
}
void dfs2(int u)
{
	vis[u]=2;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		if(vis[v]!=1)continue;
		if(ch[v]%2==0)dfs2(v);
		else
		{
			int ei=e.second;
			if(ei<0)ei=~ei;
			usd[ei]=true;
			dfs2(v);
		}
	}
}
vector<dat>f(vector<pair<int,pair<int,int> > >E)
{
	for(int i=0;i<N;i++)G[i].clear(),vis[i]=0;
	for(int i=0;i<E.size();i++)
	{
		int ei=E[i].first;
		int u=E[i].second.first,v=E[i].second.second;
		G[u].push_back(make_pair(v,ei));
		G[v].push_back(make_pair(u,~ei));
	}
	for(int i=0;i<N;i++)if(vis[i]==0)
	{
		dfs1(i);
		dfs2(i);
	}
	for(int i=0;i<N;i++)G[i].clear();
	for(int i=0;i<E.size();i++)
	{
		int ei=E[i].first;
		if(!usd[ei])continue;
		int u=E[i].second.first,v=E[i].second.second;
		G[u].push_back(make_pair(v,ei));
		G[v].push_back(make_pair(u,~ei));
	}
	for(int i=0;i<N;i++)ch[i]=G[i].size()%2;
	vector<dat>ret;
	{
		for(int i=0;i<N;i++)if(ch[i]%2==1)
		{
			int u=i;
			dat now;
			now.u=u;
			do{
				while(true)
				{
					pair<int,int>e=G[u].back();
					G[u].pop_back();
					int ei=e.second;
					if(dir[ei<0?~ei:ei]!=0)continue;
					dir[ei<0?~ei:ei]=ei>=0?1:-1;
					now.ei.push_back(ei<0?~ei:ei);
					u=e.first;
					break;
				}
			}while(ch[u]%2==0);
			now.v=u;
			ret.push_back(now);
			ch[i]--;
			ch[u]--;
		}
	}
	for(int i=0;i<N;i++)G[i].clear();
	for(int i=0;i<E.size();i++)
	{
		int ei=E[i].first;
		if(dir[ei]!=0)continue;
		int u=E[i].second.first,v=E[i].second.second;
		G[u].push_back(make_pair(v,ei));
		G[v].push_back(make_pair(u,~ei));
	}
	{//roop
		for(int i=0;i<N;i++)while(!G[i].empty())
		{
			int ei=G[i].back().second;
			int v=G[i].back().first;
			G[i].pop_back();
			if(dir[ei<0?~ei:ei]!=0)continue;
			dir[ei<0?~ei:ei]=ei>=0?1:-1;
			while(v!=i)
			{
				while(true)
				{
					pair<int,int>e=G[v].back();
					G[v].pop_back();
					int ei=e.second;
					if(dir[ei<0?~ei:ei]!=0)continue;
					dir[ei<0?~ei:ei]=ei>=0?1:-1;
					v=e.first;
					break;
				}
			}
		}
	}
	return ret;
}
int fix[3<<17];
int fix2[3<<17];
int TO[3<<17];
int cnt[3<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	vector<pair<int,pair<int,int> > >E1,E2;
	for(int i=0;i<M;i++)
	{
		cin>>U[i]>>V[i]>>W[i];
		U[i]--,V[i]--;
		if(W[i]==1)E1.push_back(make_pair(i,make_pair(U[i],V[i])));
		else E2.push_back(make_pair(i,make_pair(U[i],V[i])));
	}
	vector<dat>now=f(E1);
	for(int i=0;i<now.size();i++)
	{
		fix[now[i].u]=1;
		fix2[now[i].u]=1;
		TO[now[i].u]=now[i].v;
		fix[now[i].v]=2;
		fix2[now[i].v]=2;
		TO[now[i].v]=now[i].u;
	}
	vector<pair<int,pair<int,int> > >gE2;
	for(int i=0;i<E2.size();i++)
	{
		int u=E2[i].second.first;
		int v=E2[i].second.second;
		if(fix[u]&&fix[v])
		{
			gE2.push_back(E2[i]);
		}
	}
	vector<dat>now2=f(gE2);
	for(int i=0;i<N;i++)G[i].clear();
	for(int i=0;i<now2.size();i++)
	{
		int u=now2[i].u,v=now2[i].v;
		G[u].push_back(make_pair(v,0));
		G[v].push_back(make_pair(u,0));
	}
	for(int i=0;i<now2.size();i++)
	{
		int u=now2[i].u,v=now2[i].v;
		if(fix2[u]==fix2[v])
		{
			while(true)
			{
				fix2[v]=3-fix2[v];
				v=TO[v];
				fix2[v]=3-fix2[v];
				if(G[v].empty())break;
				int w=G[v][0].first;
				if(fix2[v]!=fix2[w])break;
				v=w;
			}
		}
	}
	for(int i=0;i<now.size();i++)
	{
		if(fix[now[i].u]!=fix2[now[i].u])
		{
			for(int ei:now[i].ei)dir[ei]=-dir[ei];
		}
	}
	for(int i=0;i<now2.size();i++)
	{
		int u=now2[i].u,v=now2[i].v;
		if(fix2[u]==1)
		{
			for(int ei:now2[i].ei)
			{
				dir[ei]=-dir[ei];
			}
		}
	}
	for(int i=0;i<M;i++)if(dir[i]!=0)
	{
		int w=W[i];
		if(dir[i]==1)cnt[U[i]]-=w,cnt[V[i]]+=w;
		else cnt[U[i]]+=w,cnt[V[i]]-=w;
	}
	for(int i=0;i<M;i++)if(dir[i]==0)
	{
		if(fix[U[i]])
		{
			if(cnt[U[i]]==1)
			{
				dir[i]=1;
				cnt[U[i]]=-1;
			}
			else
			{
				dir[i]=-1;
				cnt[U[i]]=1;
			}
		}
		else if(fix[V[i]])
		{
			if(cnt[V[i]]==1)
			{
				dir[i]=-1;
				cnt[V[i]]=-1;
			}
			else
			{
				dir[i]=1;
				cnt[V[i]]=1;
			}
		}
		else
		{
			dir[i]=1;
		}
	}
	cout<<now.size()*2<<endl;
	for(int i=0;i<M;i++)cout<<(dir[i]==1?1:2);
	cout<<endl;
}