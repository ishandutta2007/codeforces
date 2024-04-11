#include <bits/stdc++.h>
using namespace std;
// f(x)=ModAdd(x,a,p) g(x)=f(f(...x...))=f^(n)(x)
// x-f(x)=0 or p; x-g(x)=0,p,...,np
// |x-y|<p => |f(x)-f(y)|<p => |g(x)-g(y)|<p g(x)-g(y)=x-y(mod p)
// (x-g(x))-(x+1-g(x+1))=0 or -p
// x-g(x) increasing
typedef long long ll;
const int maxn=1000005;
const int maxlog=22;
int n;
ll p,s[maxn<<2],tr[maxlog][maxn]; // [tr[dep][l+t-1],) x+s-t*p (1<=t<=r-l+1)
void build(int rt,int dep,int l,int r)
{
    if(l==r) { scanf("%lld",&s[rt]); tr[dep][l]=-s[rt]+p; return; }
    int mid=(l+r)>>1,i,j,k;
    build(rt<<1,dep+1,l,mid),build((rt<<1)|1,dep+1,mid+1,r);
    s[rt]=s[rt<<1]+s[(rt<<1)|1];
    for(k=l-1,i=l-1,j=mid;i<=mid;j--,i++)
    {
        for(;j>mid && i>=l && tr[dep+1][j]>tr[dep+1][i]+s[rt<<1]-p*(i-l+1);j--);
        for(;j<=r && (i==mid || j==mid || tr[dep+1][j]-s[rt<<1]+p*(i-l+1)<tr[dep+1][i+1]);j++)
            if(/*printf("%d %d\n",i,j),*/l+(i-l)+(j-mid)>k)
                tr[dep][k=l+(i-l)+(j-mid)]=max((i==l-1)?(ll)0x8000000000000000ll:tr[dep+1][i],(j==mid)?(ll)0x8000000000000000ll:(tr[dep+1][j]-s[rt<<1]+p*(i-l+1)));
    }
    assert(k==r);
    // printf("%d [%d, %d]: (%lld)",rt,l,r,s[rt]);
    // for(i=l;i<=r;i++) printf(" %lld",tr[dep][i]);
    // printf("\n");
}
ll query(int rt,int dep,int l,int r,int x,int y,ll z)
{
    if(x<=l && r<=y) return z+s[rt]-(upper_bound(tr[dep]+l,tr[dep]+r+1,z)-tr[dep]-l)*p;
    int mid=(l+r)>>1;
    if(x<=mid) z=query(rt<<1,dep+1,l,mid,x,y,z);
    if(mid<y) z=query((rt<<1)|1,dep+1,mid+1,r,x,y,z);
    return z;
}
int main()
{
    int q,l,r;
    scanf("%d%d%lld",&n,&q,&p);
    build(1,0,1,n);
    while(q--) scanf("%d%d",&l,&r),printf("%lld\n",query(1,0,1,n,l,r,0));
    return 0;
}