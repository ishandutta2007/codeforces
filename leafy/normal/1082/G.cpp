#include<bits/stdc++.h>
using namespace std;  
typedef long long ll;
const int N=120005;  
const int M=400005;  
const int inf=2100000000;  
int n,m,S,T;  
ll from[M],to[M],nxt[M],w[M],lj[N],cnt=-1;  
void insert(int f,int t,int p)  {  
    to[++cnt]=t;  
    nxt[cnt]=lj[f];  
    lj[f]=cnt;  
    w[cnt]=p;  
    to[++cnt]=f;  
    nxt[cnt]=lj[t];  
    lj[t]=cnt;  
    w[cnt]=0;  
}  
int d[N],q[N*2];  
bool bfs()  
{  
    memset(d,0,sizeof(d));  
    int h=1,t=1,x,j;  
    q[1]=S,d[S]=1;  
    while(h!=t+1)  
    {  
        x=q[h];  
        for(int i=lj[x];i>=0;i=nxt[i])  
        if(w[i]&&!d[to[i]])  
        {  
            d[to[i]]=d[x]+1;  
            q[++t]=to[i];  
            if(t==N) t=0;  
        }  
        if(++h==N) h=0;  
    }  
    if(d[T]) return true;  
    return false;   
}  
ll dfs(int x,ll v) {  
    if(x==T||v==0) return v;  
    ll f,ret=0;  
    for(int i=lj[x];i>=0;i=nxt[i])  
    if(d[to[i]]==d[x]+1)  
    {  
        f=dfs(to[i],min(w[i],v));  
        w[i]-=f;  
        w[i^1]+=f;  
        v-=f;  
        ret+=f;  
        if(v==0) break;  
    }  
    return ret;  
}  
int main()  
{  
    scanf("%d%d",&n,&m);  
    T=m+n+1,S=0;  
    int x,y,p;  
    for(int i=0;i<=T;i++) lj[i]=-1;  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&x);  
        insert(0,i,x);  
    }  
    ll sum=0,ans=0;  
    for(int i=1;i<=m;i++)  
    {  
        scanf("%d%d%d",&x,&y,&p);  
        insert(n+i,T,p);  
        insert(x,n+i,inf);  
        insert(y,n+i,inf);  
        sum+=p;  
    }  
    while(bfs()) ans+=dfs(S,inf);  
    printf("%lld",sum-ans);  
}