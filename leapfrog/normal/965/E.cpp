#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt,ans,t[100005][26];char b[100005],c[100005];priority_queue<int>q[100005];
inline void dfs(int x,int d)
{
	for(int i=0;i<26;i++)
		if(t[x][i])
		{
			dfs(t[x][i],d+1);
			while(!q[t[x][i]].empty()) q[x].push(q[t[x][i]].top()),q[t[x][i]].pop();
		}
	if(x&&!b[x]) ans-=q[x].top()-d,q[x].pop(),q[x].push(d);
}
int main()
{
	scanf("%d",&n),memset(b,0,sizeof(b)),cnt=0;
	for(int k=1,x;k<=n;k++)
	{
		x=0,scanf("%s",c+1),m=strlen(c+1);
		for(int i=1;i<=m;i++) {if(!t[x][c[i]-'a']) t[x][c[i]-'a']=++cnt;x=t[x][c[i]-'a'];}
		b[x]=1,q[x].push(m),ans+=m;
	}
	return dfs(0,0),printf("%d\n",ans),0;
}