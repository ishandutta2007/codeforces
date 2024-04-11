#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int MAXN=400010;
int n,w[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int ans[10000010],tot;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
    int ch=0;
    ans[++tot]=x;
    w[x]=-w[x];
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            ch++;
            DFS(to[i],x);
            if(w[to[i]]==-1)
            {
                ans[++tot]=to[i];
                ans[++tot]=x;
                w[to[i]]=-w[to[i]];
                w[x]=-w[x];
            }
        }
    ans[++tot]=fa;
    w[fa]=-w[fa];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    int o=0;
    for(int i=1;i<=n;i++) if(w[i]==1) o++;
    if(o==n) {puts("1");return 0;}
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS(1,0);
    tot--;
    if(w[1]==1) tot--;
    for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
    return 0;
}