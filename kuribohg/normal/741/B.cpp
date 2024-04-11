#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define next next2
using namespace std;
const int MAXN=1010;
const int MAXM=1010*1010*2;
int n,m,W,tot,sum;
int w[MAXN],b[MAXN];
int head[MAXN],to[MAXM],next[MAXM],cnt=1;
bool used[MAXN];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
vector<int> v[MAXN];
void DFS(int x)
{
    v[tot].push_back(x);
    used[x]=true;
    for(int i=head[x];i;i=next[i])
        if(!used[to[i]]) DFS(to[i]);
}
int f[1010][1010];
int main()
{
    scanf("%d%d%d",&n,&m,&W);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adde(x,y);
    }
    for(int i=1;i<=n;i++)
        if(!used[i]) ++tot,DFS(i);
    for(int i=1;i<=tot;i++)
    {
        int o=v[i].size(),sumw=0,sumb=0;
        for(int p=W;p>=0;p--) f[i][p]=f[i-1][p];
        for(int j=0;j<o;j++)
        {
            int ww=w[v[i][j]];
            int bb=b[v[i][j]];
            sumw+=ww,sumb+=bb;
            for(int p=W;p>=0;p--)
                if(p>=ww) f[i][p]=max(f[i][p],f[i-1][p-ww]+bb);
        }
        for(int p=W;p>=0;p--)
            if(p>=sumw) f[i][p]=max(f[i][p],f[i-1][p-sumw]+sumb);
    }
    int ans=0;
    for(int i=0;i<=W;i++)
        ans=max(ans,f[tot][i]);
    printf("%d\n",ans);
    return 0;
}