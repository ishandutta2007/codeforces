#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int h[1010],nxt[60010],to[60010],cost[60010],K=1;
int dfn[1011],low[1010],dfs=0,ans1,ans2;int n,m;
int bridge[60100][2],S,T,cnt=0;int path[1010][3];bool Found=0;
bool used[1001],val[60010];int lst[60010];
void ins(int u,int v,int c){nxt[++K]=h[u];h[u]=K;to[K]=v;cost[K]=c;val[K]=1;}
void del(int u,int v,int k){for(int i=h[u];i;i=nxt[i])if(to[i]==v&&i==k){val[i]=0;return;}}
void _ins(int u,int v,int k){for(int i=h[u];i;i=nxt[i])if(to[i]==v&&i==k){val[i]=1;return;}}
bool tarjan(int x,int k)
{
	dfn[x]=++dfs;low[x]=dfn[x];bool ok=0;//cout<<x<<" ";
//for(int i=1;i<=6;i++)cout<<low[i]<<" "<<dfn[i]<<" ";cout<<endl; 
	for(int i=h[x];i;i=nxt[i])
	{
		if(val[i]==0)continue;
		if(i==(k^1))continue;int y=to[i];
		if(dfn[y])low[x]=min(low[x],dfn[y]);
		else
		{
			bool okk=tarjan(y,i);ok=ok==true?true:okk;
			low[x]=min(low[x],low[y]);
			if(dfn[y]==low[y]&&okk)bridge[++cnt][0]=cost[i],bridge[cnt][1]=i>>1;
		}
	}
	if(x==T)ok=1;return ok;
}
bool check(int u)
{
	used[u]=1;bool ok=0;if(u==T){return 1;}
	for(int i=h[u];i;i=nxt[i]){if(val[i]==0)continue;if(used[to[i]])continue;ok=ok==true?true:check(to[i]);}
	return ok;
}
void Find(int u,int t)
{
	used[u]=1;
	if(u==T){Found=1;return;}
	for(int i=h[u];i;i=nxt[i])
	{
		if(val[i]==0)continue;if(Found)return;if(used[to[i]]){continue;}
		path[t][0]=u;path[t][1]=to[i];path[t][2]=i;Find(to[i],t+1);
	}
}
/*void print()
{
	for(int i=1;i<=62;i++)
	{
		cout<<i<<":";
	
	for(int j=h[i];j;j=nxt[j])
	{
		cout<<to[j]<<" "<<val[j]<<"  ";
	}cout<<endl;}
}*/
int solve()
{
	int ans=2147483647;//if(n==1000)exit(0);
	Find(S,1);if(!Found)return 0;
	for(int i=1;path[i][0]!=0;i++)
	{
		memset(used,0,sizeof(used));
		del(path[i][0],path[i][1],path[i][2]);del(path[i][1],path[i][0],path[i][2]^1);int y=path[i][2];
		if(!check(S))
			if(ans>cost[y])ans=cost[y],ans1=y>>1;
		_ins(path[i][0],path[i][1],path[i][2]);_ins(path[i][1],path[i][0],path[i][2]^1);
	}
	for(int i=1;path[i][0]!=0;i++)
	{
		cnt=0;memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));dfs=0;memset(used,0,sizeof(used));
		del(path[i][0],path[i][1],path[i][2]);del(path[i][1],path[i][0],path[i][2]^1);int y=path[i][2];
		tarjan(S,0);//for(int oo=1;oo<=6;oo++)cout<<low[oo]<<" "<<dfn[oo]<<endl;
		for(int j=1;j<=cnt;j++)
		{//cout<<bridge[j][1]<<" ";
			if(ans>cost[y]+bridge[j][0])ans=cost[y]+bridge[j][0],ans1=y>>1,ans2=bridge[j][1];
		}
		_ins(path[i][0],path[i][1],path[i][2]);_ins(path[i][1],path[i][0],path[i][2]^1);
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(int i=1;i<=m;i++){int x,y,c;scanf("%d%d%d",&x,&y,&c);ins(x,y,c);ins(y,x,c);}
	for(int i=1;i<=n;i++)
	for(int j=h[i],last;j;last=j,j=nxt[j])if(j!=h[i])lst[j]=last;
	int ans=solve();if(ans==2147483647)return 0*puts("-1");
	printf("%d\n",ans);
	if(ans1==0)puts("0");
	else if(ans2==0){puts("1");printf("%d",ans1);}
	else {puts("2");printf("%d %d",ans1,ans2);}
	return 0;
 }