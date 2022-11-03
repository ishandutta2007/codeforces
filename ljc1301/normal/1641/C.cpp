#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,/*maxx[maxn<<2],*/minn[maxn<<2];
bool tag[maxn<<2];
void build(int rt,int l,int r)
{
    tag[rt]=0,/*maxx[rt]=-1*/minn[rt]=n+1;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
}
// inline void updatemax(int x,int y)
// {
//     int rt=1,l=1,r=n,mid;
//     for(;l<r;)
//     {
//         maxx[rt]=max(maxx[rt],y);
//         mid=(l+r)>>1;
//         if(x<=mid) r=mid,rt<<=1;
//         else l=mid+1,rt=(rt<<1)|1;
//     }
// }
inline void updatemin(int x,int y)
{
    int rt=1,l=1,r=n,mid;
    for(;;)
    {
        minn[rt]=min(minn[rt],y);
        if(l==r) return;
        mid=(l+r)>>1;
        if(x<=mid) r=mid,rt<<=1;
        else l=mid+1,rt=(rt<<1)|1;
    }
}
void update(int rt,int l,int r,int x,int y)
{
    if(x<=l && r<=y) { tag[rt]=1; return; }
    int mid=(l+r)>>1;
    if(x<=mid) update(rt<<1,l,mid,x,y);
    if(mid<y) update((rt<<1)|1,mid+1,r,x,y);
    tag[rt]|=tag[rt<<1] && tag[(rt<<1)|1];
}
inline bool query(int x)
{
    int rt=1,l=1,r=n,mid;
    for(;;)
    {
        if(tag[rt]) return true;
        if(l==r) return false;
        mid=(l+r)>>1;
        if(x<=mid) r=mid,rt<<=1;
        else l=mid+1,rt=(rt<<1)|1;
    }
}
int querymin(int rt,int l,int r,int x,int y)
{
    if(x<=l && r<=y) return minn[rt];
    int mid=(l+r)>>1,res=n+1;
    if(x<=mid) res=min(res,querymin(rt<<1,l,mid,x,y));
    if(mid<y) res=min(res,querymin((rt<<1)|1,mid+1,r,x,y));
    return res;
}
int findmax(int rt,int l,int r,int x,int y)
{
    if(x>y) return -1;
    if(tag[rt]) return -1;
    if(l==r) return l;
    int mid=(l+r)>>1,res=-1;
    if(mid<y) res=findmax((rt<<1)|1,mid+1,r,x,y);
    if(res!=-1) return res;
    if(x<=mid) res=findmax(rt<<1,l,mid,x,y);
    return res;
}
int findmin(int rt,int l,int r,int x,int y)
{
    if(x>y) return n+1;
    if(tag[rt]) return n+1;
    if(l==r) return l;
    int mid=(l+r)>>1,res=n+1;
    if(x<=mid) res=findmin(rt<<1,l,mid,x,y);
    if(res!=n+1) return res;
    if(mid<y) res=findmin((rt<<1)|1,mid+1,r,x,y);
    return res;
}
int main()
{
    int q,l,r,x;
    scanf("%d%d",&n,&q);
    build(1,1,n);
    while(q--)
        if(scanf("%d",&x),!x)
        {
            scanf("%d%d%d",&l,&r,&x);
            if(x) updatemin(l,r);
            else update(1,1,n,l,r);
        }
        else if(scanf("%d",&x),query(x)) printf("NO\n");
        else
        {
            l=findmax(1,1,n,1,x-1)+1,r=findmin(1,1,n,x+1,n)-1;
            // printf("? %d %d\n",l,r);
            if(querymin(1,1,n,l,x)<=r) printf("YES\n");
            else printf("N/A\n");
        }
    return 0;
}