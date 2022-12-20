#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=300010;
int fir[maxn],ne[2*maxn],to[2*maxn],vis[maxn],clr[maxn],s[maxn],n,m,ans;
vector<int> v[maxn];
void add(int num,int x,int y)
{
    ne[num]=fir[x];
    fir[x]=num;
    to[num]=y;
}
void dfs(int u,int f)
{
    int now=1;
    for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++)
        if (clr[*it]) vis[clr[*it]]=u;
    for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++)
        if (!clr[*it])
        {
            while (vis[now]==u) now++;
            clr[*it]=now;
            ans=max(ans,now);
            vis[now]=u;
        }
    for (int i=fir[u];i;i=ne[i])
        if (to[i]!=f) dfs(to[i],u);
}
int main()
{
    int x,y;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        for (int j=1;j<=s[i];j++)
        {
            scanf("%d",&x);
            v[i].push_back(x);
        }
    }
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add(i*2,x,y);
        add(i*2+1,y,x);
    }
    dfs(1,-1);
    if (!ans) ans=1;
    printf("%d\n",ans);
    for (int i=1;i<=m;i++)
        printf("%d%c",clr[i]?clr[i]:1,i==m?'\n':' ');
}