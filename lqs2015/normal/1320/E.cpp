#include<bits/stdc++.h>
using namespace std;
int n,q,x,y,dep[1111111],beg[1111111],cnt,an[1111111][22],k,top,lc,ct,dst,all,rt,sub[1111111];
int id[444444],fuck[444444],imp[444444],ca,cb,v[444444],s[444444],gg[444444],pre[444444],nxt[444444];
pair<int,int> pr[444444],nt[444444];
vector<int> g[1111111];
vector<pair<int,int> > ng[1111111];
pair<int,int> poi[1111111],st[1111111];
pair<int,int> dp[1111111],DP[1111111];
int inform[1111111];
struct item
{
	int d,id,t;
	bool operator < (const item &u) const
	{
		if ((d+v[id]-1)/v[id]!=(u.d+v[u.id]-1)/v[u.id]) return (d+v[id]-1)/v[id]>(u.d+v[u.id]-1)/v[u.id];
		if (id!=u.id) return id>u.id;
		return t>u.t;
	}
};
struct items
{
	int d,id;
	bool operator < (const items &u) const
	{
		if (id>1e8) return 0;
		if (u.id>1e8) return 1;
		if ((d+v[id]-1)/v[id]!=(u.d+v[u.id]-1)/v[u.id]) return (d+v[id]-1)/v[id]<(u.d+v[u.id]-1)/v[u.id];
		return id<u.id;
	}
}d[444444];
priority_queue<item> pq;
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
	{
		if (dep[an[x][i]]>=dep[y]) x=an[x][i];
	}
	for (int i=20;i>=0;i--)
	{
		if (an[x][i]!=an[y][i])
		{
			x=an[x][i];
			y=an[y][i];
		}
	}
	if (x!=y) return an[x][0];
	return x;
}
void dfs(int i,int fa)
{
	an[i][0]=fa;
	for (int j=1;j<=20;j++) an[i][j]=an[an[i][j-1]][j-1];
	beg[i]=++cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dep[to]=dep[i]+1;
		dfs(to,i);
	}
}
int dist(int x,int y)
{
	return abs(dep[x]-dep[y]);
}
void construct(int k)
{
	sort(poi+1,poi+k+1);
	top=1;
	st[top]=make_pair(poi[1].second,1);
	ct=k;
	for (int i=1;i<=k;i++)
	{
		id[poi[i].second]=i;
		fuck[i]=poi[i].second;
	}
	int cid;
	for (int i=2;i<=k;i++)
	{
		lc=lca(st[top].first,poi[i].second);
		while(top>1 && dep[st[top-1].first]>dep[lc])
		{
			dst=dist(st[top].first,st[top-1].first);
			if (st[top].second!=st[top-1].second)
			{
				ng[st[top].second].push_back(make_pair(st[top-1].second,dst));
				ng[st[top-1].second].push_back(make_pair(st[top].second,dst));
			}
			top--;  
		}
		if (st[top].first!=lc)
		{
			if (!id[lc]) 
			{
				ct++;
				id[lc]=ct;
				fuck[ct]=lc;
				cid=ct;
			}
			else cid=id[lc];
			if (cid!=st[top].second)
			{
				dst=dist(st[top].first,lc);
				ng[st[top].second].push_back(make_pair(cid,dst));
				ng[cid].push_back(make_pair(st[top].second,dst));
				st[top]=make_pair(lc,cid); 
			}
		}
		st[++top]=make_pair(poi[i].second,i);
	}
	while(top>1)
	{
		dst=dist(st[top].first,st[top-1].first);
		if (st[top].second!=st[top-1].second)
		{
			ng[st[top].second].push_back(make_pair(st[top-1].second,dst));
			ng[st[top-1].second].push_back(make_pair(st[top].second,dst));
		}
		top--;  
	}
	rt=st[top].second;
}
void bfs()
{
	for (int i=1;i<=ca;i++)
	{
		d[id[s[i]]]=(items){0,i};
		item u=(item){0,i,id[s[i]]};
		pq.push(u);
	}
	while(!pq.empty())
	{
		item u=pq.top();pq.pop();
		if (u.d!=d[u.t].d || u.id!=d[u.t].id) continue;
		int x=u.t,y=u.d,z=u.id;
		for (int i=0;i<ng[x].size();i++)
		{
			int to=ng[x][i].first,val=ng[x][i].second;
			items cr=(items){y+val,z};
			if (cr<d[to])
			{
				d[to]=cr;
				pq.push((item){cr.d,cr.id,to});
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dep[1]=1;
	dfs(1,0);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&ca,&cb);
		k=0;
		for (int i=1;i<=ca;i++)
		{
			scanf("%d%d",&s[i],&v[i]);
			imp[++k]=s[i];
		}
		for (int i=1;i<=cb;i++)
		{
			scanf("%d",&gg[i]);
			imp[++k]=gg[i];
		}
		sort(imp+1,imp+k+1);
		k=unique(imp+1,imp+k+1)-imp-1;
		for (int i=1;i<=k;i++) poi[i]=make_pair(beg[imp[i]],imp[i]);
		construct(k);
		for (int i=1;i<=ct;i++)
		{
			d[i]=(items){1000000000,1000000000};
		}
		bfs();
		for (int i=1;i<=cb;i++)
		{
			printf("%d ",d[id[gg[i]]].id);
		}
		printf("\n");
		for (int i=1;i<=ct;i++) ng[i].clear();
		for (int i=1;i<=ct;i++) id[fuck[i]]=0;
	}
	return 0;
}