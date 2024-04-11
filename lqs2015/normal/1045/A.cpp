#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int head[444444],to[444444],cap[444444],dist[444444],nxt[444444],cur[444444],tnode[444444],mx,ans,tp,cnp,L[444444],R[444444];
int n,m,s,t,cnt,x,y,z;
bool used[444444];
void addedge(int s,int t,int cps,int cpt)
{
    cnt++;
    nxt[cnt]=head[s];head[s]=cnt;
    to[cnt]=t;cap[cnt]=cps;
    cnt++;
    nxt[cnt]=head[t];head[t]=cnt;
    to[cnt]=s;cap[cnt]=cpt;
}
void bfs()
{
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for (int i=head[x];i;i=nxt[i])
        {
            if (!cap[i]) continue;
            if (!~dist[to[i]])
            {
                dist[to[i]]=dist[x]+1;
                q.push(to[i]);
            }
        }
    }
}
int dfs(int i,int f)
{
    if (i==t) return f;
    int tmp=f;
    for (int &j=cur[i];j;j=nxt[j])
    {
        if (!cap[j] || dist[to[j]]!=dist[i]+1) continue;
        int d=dfs(to[j],min(cap[j],f));
        if (d)
        {
            cap[j]-=d;
            cap[j^1]+=d;
            tmp-=d;
            if (!tmp) break;
        }
        else dist[to[j]]=0;
    }
    return f-tmp;
}
int dinic()
{
    int res=0;
    while(1)
    {
		for (int i=1;i<=t;i++) cur[i]=head[i];
        bfs();
        if (!~dist[t]) break;
        res+=dfs(s,1e9);
    }
    return res;
}
void build(int l,int r,int node)
{
	mx=max(mx,node);L[node]=l;R[node]=r;
	if (l==r) 
	{
		tnode[l]=node;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	addedge(node,node<<1,inf,0);
	addedge(node,(node<<1)|1,inf,0);
}
void update(int beg,int en,int l,int r,int node,int p)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		addedge(p,node,1,0);
		return;
	}
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,p);
	update(beg,en,mid+1,r,(node<<1)|1,p);
}
int Search(int l,int r,int node)
{
	if (l==r) return l;
	int mid=(l+r)>>1;
	for (int j=head[node];j;j=nxt[j])
	{
		if (cap[j^1] && ((to[j]==(node<<1)) || (to[j]==((node<<1)|1))))
		{
			cap[j^1]--;
			if (to[j]==(node<<1)) return Search(l,mid,node<<1);
			return Search(mid+1,r,(node<<1)|1);
		}
	}
}
int main()
{
	cnt=1;
	scanf("%d%d",&n,&m);
	build(1,m,1);
	s=n+mx+1;t=s+1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&tp);
		if (!tp)
		{
			scanf("%d",&cnp);
			for (int j=1;j<=cnp;j++)
			{
				scanf("%d",&x);
				addedge(mx+i,tnode[x],1,0);
			}
			addedge(s,mx+i,1,0);
		}
		else if (tp==1)
		{
			scanf("%d%d",&x,&y);
			update(x,y,1,m,1,mx+i);
			addedge(s,mx+i,1,0);
		}
		else
		{
			scanf("%d%d%d",&x,&y,&z);
			used[x]=used[y]=1;ans+=2;
			addedge(mx+i,tnode[x],0,1);
			addedge(mx+i,tnode[y],0,1);
			addedge(mx+i,tnode[z],1,0);
			addedge(s,mx+i,0,2);
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (!used[i]) addedge(tnode[i],t,1,0);
		else addedge(tnode[i],t,0,1);
	}
	ans+=dinic();
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
	{
		for (int j=head[mx+i];j;j=nxt[j])
		{
			if (!cap[j] && to[j]!=s)
			{
				printf("%d %d\n",i,Search(L[to[j]],R[to[j]],to[j]));
			}
		}
	}
	return 0;
}