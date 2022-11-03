#include <bits/stdc++.h>
using namespace std;
// d[u]<=2 => rings and chains
typedef long long ll;
const int kcz=1000000007;
const int maxn=100005;
const int maxm=maxn<<1;
int n,cur,pow2[maxn],he[maxn],ne[maxm],to[maxm],val[maxm],tot,cnt,d[maxn]; // u->v (u<0)*2+(v<0)
bool vis[maxn],scir[maxn]; // f[cur][start][end][xorsum]
ll ans,t,f[2][2][2][2];
inline void add_edge(int u,int v,int c) { to[tot]=v,val[tot]=c,ne[tot]=he[u],he[u]=tot++,d[u]++; }
inline void add_edge(int u,int v) { add_edge(abs(u),abs(v),((u<0)<<1)|(v<0));  }
inline int nex(int u,int pre)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if((i^pre)!=1)
            return i;
    return -1;
}
inline void solve(int u)
{
    int j,pre,p,q,r,s,v;
    vis[u]=1,pre=-1,cur=0,cnt=1;
    memset(f[cur],0,sizeof(f[cur]));
    f[cur][0][0][0]=f[cur][1][1][scir[u]]=1;
    // printf("%d ",u);
    for(;j=nex(u,pre),j!=-1 && !vis[v=to[j]];pre=j,vis[v]=1,u=v/*,printf("%d ",v)*/,cnt++)
        for(p=0,cur^=1;p<=1;p++)
        {
            for(q=0;q<=1;q++)
                for(r=0;r<=1;r++)
                    for(f[cur][p][q][r]=0,s=0;s<=1;s++)
                        (f[cur][p][q][r]+=f[cur^1][p][s][r^(((s<<1)|q)!=val[j])])%=kcz;
            if(scir[v]) swap(f[cur][p][1][0],f[cur][p][1][1]);
        }
    t=(f[cur][0][0][1]+f[cur][0][1][1]+f[cur][1][0][1]+f[cur][1][1][1])%kcz;
    if(j!=-1) (t+=kcz-f[cur][val[j]&1][val[j]>>1][1]+f[cur][val[j]&1][val[j]>>1][0])%=kcz,t=(kcz+pow2[cnt]-t)%kcz;
    ans=(ans*(pow2[cnt]+kcz-t)+t*(pow2[tot]+kcz-ans))%kcz;
    // printf("%lld %d\n",t,cnt);
    tot+=cnt;
}
int main()
{
    int i,m,u,v;
    scanf("%d%d",&m,&n);
    for(tot=0,pow2[0]=1,i=1;i<=n;i++) pow2[i]=(pow2[i-1]<<1)%kcz,he[i]=-1,vis[i]=0,scir[i]=0,d[i]=0;
    ans=0;
    while(m--)
        if(scanf("%d%d",&i,&u),i==1) scir[abs(u)]^=1,ans=(u<0)?ans^1:ans;
        else
        {
            scanf("%d",&v);
            if(u+v==0) ans^=1;
            else if(u==v) scir[abs(u)]^=1,ans=(u<0)?ans^1:ans;
            else add_edge(u,v),add_edge(v,u);
        }
    for(tot=0,i=1;i<=n;i++)
        if(!vis[i] && d[i]==1)
            solve(i);
    for(i=1;i<=n;i++)
        if(!vis[i])
            solve(i);
    printf("%lld\n",ans);
    return 0;
}