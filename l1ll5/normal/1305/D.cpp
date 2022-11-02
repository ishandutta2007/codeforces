#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
struct zgz
{
    int next,to;
}edge[N<<1];
int cnt=1,head[N];
void add(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
int son[N],f[N];
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue ;
        dfs(to,x);
        son[x]++;
    }
    f[x]=fa;
}
bool del[N];
int lca;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y),add(y,x);
    }
    dfs(1,0);
    int rem=n;
    while(1)
    {
        int a=0,b=0;
        bool ok=0;
        for(int i=1;i<=n;i++)
        if(son[i]==0 && del[i]==0)
        {
            if(!a) a=i;
            else if(!b)
            {
                b=i;
                ok=1;
                break ;
            }
        }
        if(!ok)
        {
            if(rem==1)
            {
                for(int i=1;i<=n;i++)
                if(!del[i])
                {
                    printf("! %d\n",i);
                    fflush(stdout);
                    return 0;
                }
            }
            else
            {
                int left=0;
                for(int i=1;i<=n;i++)
                if(son[i]==0 && del[i]==0) left=i;

                a=1,b=left;
                printf("? %d %d\n",a,b);
                fflush(stdout);
                lca=0;
                scanf("%d",&lca);
                printf("! %d\n",lca);
                fflush(stdout);
                return 0;
            }
        }
        son[f[a]]--,son[f[b]]--;
        del[a]=del[b]=1;
        rem-=2;
        printf("? %d %d\n",a,b);
        fflush(stdout);
        lca=0;
        scanf("%d",&lca);
        if(lca==a||lca==b)
        {
            printf("! %d\n",lca);
            fflush(stdout);
            return 0;
        }
    }
}