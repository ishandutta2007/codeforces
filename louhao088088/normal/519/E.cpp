#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct node
{
	int v,nex;
}e[maxn*2];
int head[maxn],s[maxn],h[maxn],f[maxn*10][20],n,cnt=0,m,x,y,c,d,w;
void add(int u,int v){e[++cnt].v=v,e[cnt].nex=head[u],head[u]=cnt;}
void dfs(int x,int fa){
    s[x]=1,h[x]=h[fa]+1,f[x][0]=fa;
    for(int i=1;i<18;i++) f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nex)
	{
        if(e[i].v==fa) continue;
        dfs(e[i].v,x);s[x]+=s[e[i].v];
    }
}
void lca(int x,int y)
{
    if(x==y)printf("%d\n",s[1]);
    else if((abs(h[x]-h[y]))%2==1)puts("0");
    else if(h[x]==h[y])
	{
        for(int i=18;i>=0;i--)if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
        printf("%d\n",s[1]-s[x]-s[y]);
    }
    else
    {
    	if(h[x]<h[y])swap(x,y);c=x,d=y;
		for(int i=18;i>=0;i--)if(h[f[x][i]]>=h[y]) x=f[x][i]; 
		for(int i=18;i>=0;i--)if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		if(x!=y)x=f[x][0];w=(h[c]-h[x]+h[d]-h[x])/2;w=h[c]-w;
		for(int i=18;i>=0;i--)if(h[f[c][i]]>w) c=f[c][i];
		printf("%d\n",s[f[c][0]]-s[c]); 
    }
}
int main()
{  
    scanf("%d",&n);
    for(int i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(1,1);scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),lca(x,y);
    return 0;
}