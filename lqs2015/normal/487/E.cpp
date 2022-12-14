#include<bits/stdc++.h>
using namespace std;
int bccnt,n,m,q,x,y,z,dfn[111111],low[111111],cnt,bccno[111111],val[222222],wson[222222],sub[222222],beg[222222],ct,dep[222222];
int numchain,pos[222222],head[222222],w[444444],tree[1111111],pa[222222],sz;
vector<int> ng[222222];
vector<int> g[111111];
bool iscut[111111];
stack<pair<int,int> > st;
multiset<int> s[222222];
char c[11];
void dfs(int i,int fa)
{
	int child=0;
	dfn[i]=low[i]=++cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (!dfn[to])
		{
			st.push(make_pair(i,to)); 
			dfs(to,i);
			child++;
			if (low[to]>=dfn[i])
			{
				iscut[i]=1;bccnt++;
				while(!st.empty())
				{
					pair<int,int> e=st.top();st.pop();
					if (bccno[e.first]!=bccnt) 
					{
						ng[bccnt].push_back(e.first);
						ng[e.first].push_back(bccnt);  
						bccno[e.first]=bccnt; 
					}
					if (bccno[e.second]!=bccnt) 
					{
						ng[bccnt].push_back(e.second);
						ng[e.second].push_back(bccnt);  
						bccno[e.second]=bccnt; 
					}
					if (e.first==i && e.second==to) break;
				}
			}
			low[i]=min(low[i],low[to]);
		}
		else if (dfn[to]<low[i])
		{
			low[i]=dfn[to];
			st.push(make_pair(i,to)); 
		}
	}
	if (!fa && child==1) iscut[i]=0;
}
void Init(int i,int fa)
{
	sub[i]=1;dep[i]=dep[fa]+1;pa[i]=fa;
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		if (to==fa) continue;
		Init(to,i);
		if (sub[to]>sub[wson[i]]) wson[i]=to;
		sub[i]+=sub[to];
		if (i>n) 
		{
			val[i]=min(val[i],val[to]);
			s[i].insert(val[to]); 
		}
	}
}
void dft(int i,int fa)
{
	beg[i]=++ct;
	pos[i]=numchain;
	if(wson[i]) dft(wson[i],i);
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		if (to==fa || to==wson[i]) continue;
		head[++numchain]=to;
		dft(to,i);
	}
}
void upd(int x,int y)
{
	int pos=sz-1+x;tree[pos]=y;
	pos>>=1;
	while(pos>=1)
	{
		tree[pos]=min(tree[pos<<1],tree[(pos<<1)|1]);
		pos>>=1;
	}
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 1e9;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
int ask(int x,int y)
{
	int res=1e9;
	while(pos[x]!=pos[y])
	{
		if (dep[head[pos[x]]]<dep[head[pos[y]]])
		{
			res=min(res,query(beg[head[pos[y]]],beg[y],1,sz,1));
			y=pa[head[pos[y]]];
		}
		else
		{
			res=min(res,query(beg[head[pos[x]]],beg[x],1,sz,1));
			x=pa[head[pos[x]]];
		}
	}
	if (beg[x]>beg[y]) swap(x,y);
	res=min(res,query(beg[x],beg[y],1,sz,1));
	if (x>n && pa[x]) res=min(res,query(beg[pa[x]],beg[pa[x]],1,sz,1));
	return res; 
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
	}
	bccnt=n;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0);
	for (int i=n+1;i<=bccnt;i++) val[i]=1e9;
	Init(1,0);
	numchain=1;head[1]=1;
	dft(1,0);
	for (int i=1;i<=bccnt;i++) w[beg[i]]=val[i];
	sz=1;
	while(sz<bccnt) sz*=2;
	for (int i=bccnt+1;i<=sz;i++) w[i]=1e9;
	for (int i=sz;i<2*sz;i++)
	{
		tree[i]=w[i-sz+1];
	}
	for (int i=sz-1;i>=1;i--)
	{
		tree[i]=min(tree[i<<1],tree[(i<<1)|1]);
	}
	while(q--)
	{
		scanf("%s %d %d",c,&x,&y);
		if (c[0]=='A')
		{
			printf("%d\n",ask(x,y));
		}
		else
		{
			if (pa[x])
			{
				s[pa[x]].erase(s[pa[x]].find(val[x]));
				s[pa[x]].insert(y);
				val[pa[x]]=*s[pa[x]].begin();
				upd(beg[pa[x]],val[pa[x]]);
			}
			val[x]=y;
			upd(beg[x],val[x]);
		}
	}
	return 0;
}