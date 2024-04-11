#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int kcz=998244353;
// const ll inv2=(kcz+1)>>1;
const int maxn=500005;
int n,he[maxn],ne[maxn<<1],to[maxn<<1],tot;
ll ans;
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
// first: P(some vector only contains x_i)
// second: vector from i generates x_fa[i]
#define div2(x) ((((x)&1)?(x+kcz):x)>>1)
pii solve(int u,int fa)
{
    int i;
    pii temp;
    ll p=1,pfa=1;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
        {
            temp=solve(to[i],u);
            // (p*=kcz+1-inv2*temp.second%kcz)%=kcz;
            // (pfa*=inv2*(1+temp.first)%kcz)%=kcz;
            (p*=kcz+1-div2(temp.second))%=kcz;
            (pfa*=div2(1+temp.first))%=kcz;
        }
    // p=(kcz+1-p)%kcz,(ans+=p)%=kcz;
    // /*if(fa!=-1)*/ (ans+=/*inv2*(*/kcz+1-pfa/*)*/)%=kcz;
    if((p=1-p)<0) p+=kcz;
    ans=(ans+p+kcz+1-pfa)%kcz;
    return make_pair(p,pfa);
}
int main()
{
    int i,u,v;
    scanf("%d",&n);
    for(tot=0,i=1;i<=n;i++) he[i]=-1;
    for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    ans=0,solve(1,-1);
    for(i=1;i<n;i++) (ans<<=1)%=kcz;
    printf("%lld\n",ans);
    return 0;
}