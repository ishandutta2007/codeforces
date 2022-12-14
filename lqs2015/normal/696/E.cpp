#include<bits/stdc++.h>
using namespace std;
const long long inf=1e17;
int n,m,q,cur[111111],x,y,re[111111],beg[111111],en[111111],cnt,sub[111111],wson[111111],head[111111],ct,pos[111111];
long long lazy[444444];
int u,v,k,w,tp,dep[111111],pa[111111];
pair<pair<long long,int>,int> tree[444444],res,aw[111111];
vector<int> V[111111],g[111111],ans;
void dfs(int i,int fa)
{
	sub[i]=1;dep[i]=dep[fa]+1;pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
		if (sub[to]>sub[wson[i]]) wson[i]=to;
	}
}
void dft(int i,int fa)
{
	pos[i]=ct;beg[i]=++cnt;
	if (wson[i]) dft(wson[i],i);
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==wson[i] || to==fa) continue;
		ct++;head[ct]=to;
		dft(to,i);
	}
	en[i]=cnt;
}
void pushup(int node)
{
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
void push(int node,long long x)
{
	tree[node].first.first+=x;
	lazy[node]+=x;
}
void pushdown(int node)
{
	if (lazy[node])
	{
		push(node<<1,lazy[node]);
		push((node<<1)|1,lazy[node]);
		lazy[node]=0;
	}
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=aw[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
void update(int beg,int en,int l,int r,int node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		push(node,x);
		return;
	}
	pushdown(node);
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
pair<pair<long long,int>,int> query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return make_pair(make_pair(1e18,1e9),1e9);
	if (l>=beg && r<=en) return tree[node];
	pushdown(node);
	int mid=(l+r)>>1;
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
pair<pair<long long,int>,int> qry(int u,int v)
{
	pair<pair<long long,int>,int> res=make_pair(make_pair(1e18,1e9),1e9);
	while(pos[u]!=pos[v])
	{
		if (dep[head[pos[u]]]<dep[head[pos[v]]])
		{
			res=min(res,query(beg[head[pos[v]]],beg[v],1,n,1));
			v=pa[head[pos[v]]];
		}
		else 
		{
			res=min(res,query(beg[head[pos[u]]],beg[u],1,n,1));
			u=pa[head[pos[u]]];
		}
	}
	if (beg[u]>beg[v]) swap(u,v);
	res=min(res,query(beg[u],beg[v],1,n,1));
	return res;
}
void upd(int x,int l,int r,int node,long long w,int id)
{
	if (l==r)
	{
		tree[node].first.first+=w;
		tree[node].second=id;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	if (x>mid) upd(x,mid+1,r,(node<<1)|1,w,id);
	else upd(x,l,mid,node<<1,w,id);
	pushup(node);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&re[i]);
		V[re[i]].push_back(i); 
	}
	dfs(1,0);
	ct=1;head[1]=1;
	dft(1,0);
	for (int i=1;i<=n;i++)
	{
		if (V[i].empty()) aw[beg[i]]=make_pair(make_pair(1e18,1e9),1e9);
		else aw[beg[i]]=make_pair(make_pair(V[i][0],i),V[i][0]);
	}
	build(1,n,1);
	while(q--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d%d%d",&u,&v,&k);
			ans.clear();
			for (int i=1;i<=k;i++)
			{
				res=qry(u,v);
				if (res.first.first>1e16) break;
				ans.push_back(res.second);
				cur[res.first.second]++;
				if (cur[res.first.second]==(int)V[res.first.second].size()) update(beg[res.first.second],beg[res.first.second],1,n,1,inf);
				else upd(beg[res.first.second],1,n,1,V[res.first.second][cur[res.first.second]]-V[res.first.second][cur[res.first.second]-1],V[res.first.second][cur[res.first.second]]);
			}
			printf("%d ",(int)ans.size());
			for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
			printf("\n");
		}
		else
		{
			scanf("%d%d",&v,&w);
			update(beg[v],en[v],1,n,1,w);
		}
	}
	return 0;
}