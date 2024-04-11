#include<bits/stdc++.h>
using namespace std;
const int maxn=400000,maxm=800000,inf=1e9;
int n,m,head[maxn],nxt[maxm],to[maxm],cap[maxm],cnt,cur[maxn],dist[maxn],s,t,x,y,z,cnt1,cnt2,cnth,cntd,ans,crt;
int mp[222][222],id1[222][222],id2[222][222],id[222][222][2];
char str[222];
void addedge(int x,int y,int c)
{
    ++cnt;to[cnt]=y;cap[cnt]=c;
    nxt[cnt]=head[x];head[x]=cnt;
    ++cnt;to[cnt]=x;cap[cnt]=0;
    nxt[cnt]=head[y];head[y]=cnt;
}
bool In(int x,int y)
{
	return (x<=n && y<=m);
}
void bfs()
{
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    queue<int> q;
    q.push(s);
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
        int d=dfs(to[j],min(tmp,cap[j]));
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
        bfs();
        if (!~dist[t]) return res;
        for (int i=1;i<=t;i++) cur[i]=head[i];
        res+=dfs(s,inf);
    }
    return res;
}
int main()
{
	scanf("%d%d",&n,&m);cnt=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);
		for (int j=1;j<=m;j++)
		{
			if (str[j-1]=='#') mp[i][j]=1;
			else mp[i][j]=0;
		}
	}
    /*for (int i=1;i<=n;i++)
    {
    	for (int j=1;j<=m;j++)
    	{
    		if (!mp[i][j]) continue;
    		if (j>1 && mp[i][j-1]) id1[i][j]=id1[i][j-1];
    		else id1[i][j]=++cnt1;
		}
	}
	for (int j=1;j<=m;j++)
	{
		for (int i=1;i<=n;i++)
		{
			if (!mp[i][j]) continue;
    		if (i>1 && mp[i-1][j]) id2[i][j]=id2[i-1][j];
    		else id2[i][j]=++cnt2;
		}
	}
	s=cnt1+cnt2+1;t=s+1;
	for (int i=1;i<=cnt1;i++) addedge(s,i,1);
	for (int i=1;i<=cnt2;i++) addedge(cnt1+i,t,1);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (mp[i][j]) 
			{
				addedge(id1[i][j],cnt1+id2[i][j],1);
			}
		}
	}
    printf("%d\n",dinic());*/
    for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (!mp[i][j]) continue;
			crt++;
			if (In(i,j+1) && mp[i][j+1]) id[i][j][0]=++cnth;
			if (In(i+1,j) && mp[i+1][j]) id[i][j][1]=++cntd; 
		}
	}
	s=cnth+cntd+1;t=s+1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (!mp[i][j] || !mp[i][j+1]) continue;
			if (mp[i+1][j]) addedge(id[i][j][0],cnth+id[i][j][1],1);
			if (mp[i-1][j]) addedge(id[i][j][0],cnth+id[i-1][j][1],1);
			if (mp[i+1][j+1]) addedge(id[i][j][0],cnth+id[i][j+1][1],1);
			if (mp[i-1][j+1]) addedge(id[i][j][0],cnth+id[i-1][j+1][1],1);
		}
	}
	for (int i=1;i<=cnth;i++) addedge(s,i,1);
	for (int i=cnth+1;i<s;i++) addedge(i,t,1);
	ans=s-1-dinic();	
	printf("%d\n",crt-ans);
    return 0;
}