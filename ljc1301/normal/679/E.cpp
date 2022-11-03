#include <bits/stdc++.h>
using namespace std;
// time complexity: phi=#(times of remained adding(calucate once between adjacent same element))
typedef long long ll;;
const ll K=42;
const int maxn=100005<<2;
int n;
ll tagcn[maxn],tagcd[maxn],tagsub[maxn],nex[maxn],minn[maxn]/*,maxx[maxn]*/,val[maxn];
inline void pushup(int rt) { minn[rt]=min(minn[rt<<1],minn[(rt<<1)|1]),/*maxx[rt]=max(maxx[rt<<1],maxx[(rt<<1)|1])*/val[rt]=(val[rt<<1]==val[(rt<<1)|1])?val[rt<<1]:-1; }
inline void push(int rt,ll ne,ll x) { minn[rt]=/*maxx[rt]=*/x,val[rt]=ne-x,nex[rt]=ne,tagcn[rt]=ne,tagcd[rt]=x; }
inline void push(int rt,ll s) { minn[rt]-=s,/*maxx[rt]-=x*/val[rt]=(val[rt]==-1)?-1:(val[rt]+s),tagsub[rt]+=s,tagcd[rt]-=s; }
inline void pushdown(int rt)
{
    if(tagcn[rt]!=-1) push(rt<<1,tagcn[rt],tagcd[rt]),push((rt<<1)|1,tagcn[rt],tagcd[rt]),tagsub[rt]=0,tagcn[rt]=-1;
    else if(tagsub[rt]) push(rt<<1,tagsub[rt]),push((rt<<1)|1,tagsub[rt]),tagsub[rt]=0;
}
void build(int rt,int l,int r)
{
    tagcn[rt]=-1,tagsub[rt]=0;
    if(l==r)
    {
        scanf("%lld",&/*minn[rt]*/val[rt]);
        for(nex[rt]=1;nex[rt]<=/*minn[rt]*/val[rt];nex[rt]*=K);
        minn[rt]=/*maxx[rt]=*/nex[rt]-/*minn[rt]*/val[rt];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
    pushup(rt);
}
ll query(int rt,int l,int r,int x)
{
    if(l==r) return /*nex[rt]-minn[rt]*/val[rt];
    int mid=(l+r)>>1;
    pushdown(rt);
    return (x<=mid)?query(rt<<1,l,mid,x):query((rt<<1)|1,mid+1,r,x);
}
void updatec(int rt,int l,int r,int x,int y,ll ne,ll d)
{
    if(x<=l && r<=y) { push(rt,ne,d); return; }
    int mid=(l+r)>>1;
    pushdown(rt);
    if(x<=mid) updatec(rt<<1,l,mid,x,y,ne,d);
    if(mid<y) updatec((rt<<1)|1,mid+1,r,x,y,ne,d);
    pushup(rt);
}
bool updates(int rt,int l,int r,int x,int y,ll z)
{
    // printf("updates [%d,%d] [%d,%d] %lld\n",l,r,x,y,z);
    if(x<=l && r<=y)
    {
        if(minn[rt]>=z) { push(rt,z); return minn[rt]>0; }
        // if(minn[rt]==maxx[rt]) 
        if(val[rt]>=0)
        {
            ll t;
            bool res;
            for(t=val[rt]+minn[rt];t<val[rt]+z;t*=K);
            res=(t!=val[rt]+z);
            push(rt,t,t-(val[rt]+z));
            return res;
        }
    }
    bool res1=true,res2=true;
    int mid=(l+r)>>1;
    pushdown(rt);
    if(x<=mid) res1=updates(rt<<1,l,mid,x,y,z);
    if(mid<y) res2=updates((rt<<1)|1,mid+1,r,x,y,z);
    pushup(rt);
    return res1 && res2;
}
int main()
{
    int q,op,l,r;
    ll x,y;
    scanf("%d%d",&n,&q);
    build(1,1,n);
    while(q--)
        if(scanf("%d",&op),op==1) scanf("%d",&l),printf("%lld\n",query(1,1,n,l));
        else if(op==2)
        {
            scanf("%d%d%lld",&l,&r,&x);
            for(y=1;y<=x;y*=K);
            updatec(1,1,n,l,r,y,y-x);
        }
        else
        {
            scanf("%d%d%lld",&l,&r,&x);
            for(;!updates(1,1,n,l,r,x););
        }
    return 0;
}