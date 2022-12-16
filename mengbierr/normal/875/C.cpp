#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=100005;

int n,m,vis[N],last[N],len[N],cnt;
vector<int> s[N];
struct edge{int to,next;}e[N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void addedge(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

bool dfs(int x)
{
    if (vis[x]==1) return 1;
    if (vis[x]==2) return 0;
    vis[x]=1;
    for (int i=last[x];i;i=e[i].next)
        if (!dfs(e[i].to)) return 0;
    return 1;
}

bool solve()
{
    for (int i=1;i<n;i++)
    {
        int pos=0;
        while (pos<len[i]&&pos<len[i+1]&&s[i][pos]==s[i+1][pos]) pos++;
        if (pos==len[i+1]&&pos<len[i]) return 0;
        if (pos==len[i]||pos==len[i+1]) continue;
        int x=s[i][pos],y=s[i+1][pos];
        if (x<y)
        {
            addedge(y,x);
            if (vis[y]==1&&!dfs(x)) return 0;
        }
        else
        {
            if (vis[y]==1) return 0;
            vis[y]=2;
            if (!dfs(x)) return 0;
        }
    }
    return 1;
}

int main()
{
    n=read();m=read();
    for (int i=1;i<=n;i++)
    {
        len[i]=read();
        for (int j=1;j<=len[i];j++)
        {
            int x=read();
            s[i].push_back(x);
        }
    }
    if (!solve()) puts("No");
    else
    {
        puts("Yes");
        int ans=0;
        for (int i=1;i<=m;i++) if (vis[i]==1) ans++;
        printf("%d\n",ans);
        for (int i=1;i<=m;i++) if (vis[i]==1) printf("%d ",i);
    }
    return 0;
}