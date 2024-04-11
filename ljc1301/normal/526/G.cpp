#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=100005;
const int maxlogL=30;
const int maxnode=maxn*maxlogL*4;
// either x-y z-w or x-z w-y (or both; the longer sum) intersect.
// y paths -> 2y chains start at u (at least two chains share no common edge)
// u=1 partition edges into chains; 1st~kth longest chains
// u!=1 the partition changes only if cover some edge in 1-u or cover u
int n,L,he[maxn],ne[maxn<<1],to[maxn<<1],val[maxn<<1],tot;
int fa[maxn],dep[maxn],depu[maxn],depl[maxn],maxl[maxn][2],top[maxn];
// depu: max dep in subtree of u; depl: max dep; maxl: 1st/2nd longest chain starts at u; top: chain
int rta[maxn],rtd[maxn],rt,sz[maxnode],sum[maxnode],lc[maxnode],rc[maxnode];
inline void add_edge(int u,int v,int c) { to[tot]=v,val[tot]=c,ne[tot]=he[u],he[u]=tot++; }
void insert(int &rt,int l,int r,int x,bool f) // f: whether add node
{
    if(!rt || f) tot++,lc[tot]=lc[rt],rc[tot]=rc[rt],sz[tot]=sz[rt],sum[tot]=sum[rt],rt=tot;
    sz[rt]++,sum[rt]+=x;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(x<=mid) insert(lc[rt],l,mid,x,f);
    else insert(rc[rt],mid+1,r,x,f);
}
// void print(int rt,int l,int r)
// {
//     if(!rt) return;
//     if(l==r)
//     {
//         for(r=0;r<sz[rt];r++)
//             printf("%d ",l);
//         return;
//     }
//     int mid=(l+r)>>1;
//     print(lc[rt],l,mid),print(rc[rt],mid+1,r);
// }
// void print(int rt1,int rt2,int rt3,int l,int r)
// {
//     if(!rt1 && !rt2) return;
//     if(l==r)
//     {
//         for(r=0;r<sz[rt1]+sz[rt2]-sz[rt3];r++)
//             printf("%d ",l);
//         return;
//     }
//     int mid=(l+r)>>1;
//     print(lc[rt1],lc[rt2],lc[rt3],l,mid),print(rc[rt1],rc[rt2],rc[rt3],mid+1,r);
// }
inline pii query(int rt1,int rt2,int rt3,int k) // rt1+rt2-rt3
{
    int l=0,r=L,s=0,mid;
    if(k>sz[rt1]+sz[rt2]-sz[rt3]) return make_pair(-1,sum[rt1]+sum[rt2]-sum[rt3]);
    for(;l<r;)
    {
        mid=(l+r)>>1;
        if(sz[rc[rt1]]+sz[rc[rt2]]-sz[rc[rt3]]>=k) rt1=rc[rt1],rt2=rc[rt2],rt3=rc[rt3],l=mid+1;
        else
        {
            s+=sum[rc[rt1]]+sum[rc[rt2]]-sum[rc[rt3]],k-=sz[rc[rt1]]+sz[rc[rt2]]-sz[rc[rt3]];
            rt1=lc[rt1],rt2=lc[rt2],rt3=lc[rt3],r=mid;
        }
    }
    return make_pair(l,s+k*l);
}
void dfs1(int u)
{
    int i;
    depl[u]=dep[u],depu[u]=u,maxl[u][0]=maxl[u][1]=0;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[u])
        {
            dep[to[i]]=dep[u]+val[i],fa[to[i]]=u;
            dfs1(to[i]);
            if(depl[to[i]]>depl[u]) depl[u]=depl[to[i]],depu[u]=depu[to[i]];
            if(maxl[u][0]<maxl[to[i]][0]+val[i]) maxl[u][1]=maxl[u][0],maxl[u][0]=maxl[to[i]][0]+val[i];
            else maxl[u][1]=max(maxl[u][1],maxl[to[i]][0]+val[i]);
        }
}
// void dfs2(int u,int tofa/*,int temp*/)
// {
//     int i;
//     if(maxl[u][0]<tofa) maxl[u][1]=maxl[u][0],maxl[u][0]=tofa;
//     else maxl[u][1]=max(maxl[u][1],tofa);
//     if(u==1) top[u]=1;
//     else if(depu[u]==depu[fa[u]]) top[u]=top[fa[u]];
//     else top[u]=fa[u];
//     rta[u]=rta[fa[u]],rtd[u]=rtd[fa[u]];
//     if(u!=1 && (depu[u]!=depu[fa[u]] || fa[u]==1)) insert(rtd[u],0,L,depl[u]-dep[top[u]],1);
//     if(u!=1) insert(rta[u],0,L,tofa,1);
//     for(i=he[u];~i;i=ne[i])
//         if(to[i]!=fa[u] && /*depu[to[i]]==depu[u]*/depl[to[i]]-dep[u]>tofa)
//             dfs2(to[i],((maxl[u][0]==maxl[to[i]][0]+val[i])?maxl[u][1]:maxl[u][0])+val[i]/*,temp*/);
//     // if(u!=1) insert(rta[u],0,L,/*temp+dep[u]*/tofa,1);
//     if(u!=1) insert(rtd[u],0,L,tofa,1);
//     for(i=he[u];~i;i=ne[i])
//         if(to[i]!=fa[u] && depu[to[i]]!=depu[u] && depl[to[i]]-dep[u]<=tofa)
//             dfs2(to[i],((maxl[u][0]==maxl[to[i]][0]+val[i])?maxl[u][1]:maxl[u][0])+val[i]/*,max(temp,depl[u]-(dep[u]<<1))*/);
//     if(u!=1) insert(rta[u],0,L,depl[u]-dep[u],1);
//     for(i=he[u];~i;i=ne[i])
//         if(to[i]!=fa[u] && depu[to[i]]==depu[u] && depl[to[i]]-dep[u]<=tofa)
//             dfs2(to[i],((maxl[u][0]==maxl[to[i]][0]+val[i])?maxl[u][1]:maxl[u][0])+val[i]/*,max(temp,depl[u]-(dep[u]<<1))*/);
//     // if(u!=1) insert(rta[u],0,L,depl[u]-dep[u],1);
//     if(u!=1) insert(rta[u],0,L,tofa,1);
// }
void dfs2(int u,int tofa)
{
    int i;
    if(maxl[u][0]<tofa) maxl[u][1]=maxl[u][0],maxl[u][0]=tofa;
    else maxl[u][1]=max(maxl[u][1],tofa);
    if(u==1) top[u]=1;
    else if(depu[u]==depu[fa[u]]) top[u]=top[fa[u]];
    else top[u]=fa[u];
    rta[u]=rta[fa[u]],rtd[u]=rtd[fa[u]];
    if(u!=1) insert(rta[u],0,L,depl[u]-dep[u],1),insert(rtd[u],0,L,depl[u]-dep[fa[u]],1),
        insert(rta[u],0,L,tofa,1),insert(rtd[u],0,L,tofa-(dep[u]-dep[fa[u]]),1);
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[u])
            dfs2(to[i],((maxl[u][0]==maxl[to[i]][0]+val[i])?maxl[u][1]:maxl[u][0])+val[i]);
}
int main()
{
    int q,i,u,v,c,ans=0;
    pair<int,int> res;
    scanf("%d%d",&n,&q);
    for(tot=0,i=1;i<=n;i++) he[i]=-1;
    for(i=1,L=0;i<n;i++) scanf("%d%d%d",&u,&v,&c),add_edge(u,v,c),add_edge(v,u,c),L+=c;
    dep[1]=0,fa[1]=0,rta[0]=rtd[0]=0,dfs1(1),tot=0,sz[0]=sum[0]=0,lc[0]=rc[0]=0,dfs2(1,0/*,0*/);
    for(rt=0,i=1;i<=n;i++) if(depu[i]==i) insert(rt,0,L,dep[i]-dep[top[i]],0);
    // print(rt,0,L),printf("\n");
    // for(i=1;i<=n;i++)
    // {
    //     // printf("%d +: ",i),print(rta[i],0,L),printf("\n");
    //     // printf("%d -: ",i),print(rtd[i],0,L),printf("\n");
    //     printf("%d: ",i),print(rt,rta[i],rtd[i],0,L),printf("\n");
    // }
    // for(i=1;i<=n;i++) if(depu[i]==i) printf("%d-%d(%d) ",top[i],i,dep[i]-dep[top[i]]); printf("\n");
    while(q--)
    {
        scanf("%d%d",&u,&c),u=(u+ans-1)%n+1,c=(c+ans-1)%n+1,c=min(2*c,n);
        res=query(rt,rta[u],rtd[u],c);
        // printf("? %d\n",maxl[u][1]);
        printf("%d\n",ans=res.second-max(0,res.first-maxl[u][1]));
    }
    return 0;
}