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
#define mod 1000000007
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,m;
ll seed,vmax;
ll rd()
{
	ll ret=seed;
	seed=((ll)seed*7+13)%mod;
	return ret;
}
ll a[N];
ll quickmod(ll a,ll b,ll md)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=ret*a%md;
        a=a*a%md;
        b>>=1;
    }
    return ret;
}
namespace seg
{
    ll mx[N<<2],mn[N<<2],tag[N<<2];
    void pushup(int x)
    {
        mx[x]=max(mx[x<<1],mx[x<<1|1]);
        mn[x]=min(mn[x<<1],mn[x<<1|1]);
    }

    void cv(int x,ll y)
    {mx[x]=mn[x]=tag[x]=y;}

    void build(int x,int l,int r)
    {
        if(l==r)
        {
            mn[x]=mx[x]=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        pushup(x);
    }

    void pushdown(int x)
    {
        if(tag[x])
        {
            mn[x<<1]=mx[x<<1]=tag[x<<1]=tag[x];
            mn[x<<1|1]=mx[x<<1|1]=tag[x<<1|1]=tag[x];
            tag[x]=0;
        }
    }

    void add(int x,int l,int r,int L,int R,ll v)
    {
        if(l>=L&&r<=R&&mn[x]==mx[x])
        {
            cv(x,mx[x]+v);
            return ;
        }
        int mid=(l+r)>>1;
        pushdown(x);
        if(L<=mid) add(x<<1,l,mid,L,R,v);
        if(R>mid)  add(x<<1|1,mid+1,r,L,R,v);
        pushup(x);
    }

    void cov(int x,int l,int r,int L,int R,ll v)
    {
        if(l>=L&&r<=R)
        {
            cv(x,v);
            return ;
        }
        int mid=(l+r)>>1;
        pushdown(x);
        if(L<=mid) cov(x<<1,l,mid,L,R,v);
        if(R>mid)  cov(x<<1|1,mid+1,r,L,R,v);
        pushup(x);
    }
    struct zgz
    {
        ll x,y;
    }t[N];
    bool cmp(const zgz &a,const zgz &b)
    {return a.x<b.x;}

    int top;

    void get(int x,int l,int r,int L,int R)
    {
        if(l>=L&&r<=R&&mn[x]==mx[x])
        {
            t[++top].x=mn[x];
            t[top].y=r-l+1;
            return ;
        }
        int mid=(l+r)>>1;
        pushdown(x);
        if(L<=mid) get(x<<1,l,mid,L,R);
        if(R>mid)  get(x<<1|1,mid+1,r,L,R);
    }


    ll ask1(int x,ll y,ll k)
    {
        top=0;
        get(1,1,n,x,y);
        sort(t+1,t+top+1,cmp);
        for(int i=1;i<=top;i++)
        {
            if(k<=t[i].y)
            return t[i].x;
            k-=t[i].y;
        }
    }

    ll ask2(ll l,ll r,ll x,ll y)
    {
        top=0;
        get(1,1,n,l,r);
        sort(t+1,t+top+1,cmp);
        ll tx=0,ty=0,ret=0;
        for(int i=1;i<=top;i++)
        {
            if(t[i].x!=tx)
            {
                ret+=ty*quickmod(tx%y,x,y)%y;
                ret%=y;
                tx=t[i].x;
                ty=0;
            }
            ty+=t[i].y;
        }
        ret+=ty*quickmod(tx%y,x,y)%y;
        ret%=y;
        return ret;
    }
}
int main()
{
    n=read(),m=read(),seed=read(),vmax=read();
    for(int i=1;i<=n;i++)
    a[i]=(rd()%vmax)+1;

    seg::build(1,1,n);

    while(m--)
    {
        int opt=rd()%4+1;

        int l=rd()%n+1,r=rd()%n+1;
        if(l>r)swap(l,r);

        if(opt==1)
        {
            ll x=(rd()%vmax)+1;
            seg::add(1,1,n,l,r,x);
        }
        else if(opt==2)
        {
            ll x=(rd()%vmax)+1;
            seg::cov(1,1,n,l,r,x);
        }
        else if(opt==3)
        {
            ll x=(rd()%(r-l+1))+1;
            printf("%lld\n",seg::ask1(l,r,x));
        }
        else
        {
            ll x=(rd()%vmax)+1,y=(rd()%vmax)+1;
            printf("%lld\n",seg::ask2(l,r,x,y));
        }
    }
}