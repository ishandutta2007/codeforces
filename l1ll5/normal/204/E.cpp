#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k;
ll ans[N];
char s[N];
struct zgz
{
    int next,to;
}edge[N<<1];
int cnt=1,head[N<<1];
void add_e(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
namespace SAM
{
    #define M 200010
    int ch[M][26],fail[M];
    int mx[M],kind[M];
    int vis[M],col[M];
    int tot=1,last=1;
    int np,p,q,nq;
    void add(int x,int t)
    {
        np=++tot,p=last;
        kind[np]=t,last=np,mx[np]=mx[p]+1;
        while(p&&!ch[p][x])ch[p][x]=np,p=fail[p];
        if(p==0){fail[np]=1;return ;}
        q=ch[p][x];
        if(mx[q]==mx[p]+1){fail[np]=q;return ;}
        nq=++tot,mx[nq]=mx[p]+1,vis[nq]=vis[q],col[nq]=col[q];
        memcpy(ch[nq],ch[q],sizeof(ch[q]));
        fail[nq]=fail[q],fail[q]=fail[np]=nq;
        while(p&&ch[p][x]==q)ch[p][x]=nq,p=fail[p];
    }
    void Col(int t)
    {
        int now=np;
        while(now&&vis[now]!=t)vis[now]=t,col[now]++,now=fail[now];
    }
    ll sum[M];
    void dfs(int x)
    {
        if(col[x]>=k)sum[x]=mx[x]-mx[fail[x]];
        sum[x]+=sum[fail[x]],ans[kind[x]]+=sum[x];
        for(int i=head[x];i;i=edge[i].next)
        dfs(edge[i].to);
    }
    void count()
    {
        for(int i=2;i<=tot;i++)add_e(fail[i],i);
        dfs(1);
    }
}
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        for(int j=1;j<=len;j++)
        {
            SAM::add(s[j]-'a',i);
            SAM::Col(i);
        }
        SAM::last=1;
    }
    SAM::count();
    for(int i=1;i<=n;i++)
    printf("%lld ",ans[i]);
}