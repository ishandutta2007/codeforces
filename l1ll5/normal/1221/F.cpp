#include <cmath>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
map<int,int> mp;
int n;
struct point
{
    int x,y,c;
}a[N];
bool cmpx(point a,point b)
{return a.x==b.x?a.y>b.y:a.x>b.x;}
int stk[N],top,ref[N];
pair<ll,int> mx[N<<2];
#define fi first
#define se second
ll tag[N<<2];
#define ls x<<1
#define rs x<<1|1
#define inf -1e15
void pushup(int x)
{
    mx[x]=max(mx[ls],mx[rs]);
}
void pushdown(int x)
{
    if(tag[x])
    {
        tag[ls]+=tag[x];
        tag[rs]+=tag[x];
        mx[ls].fi+=tag[x];
        mx[rs].fi+=tag[x];
        tag[x]=0;
    }
}
void add(int x,int l,int r,int L,int R,ll v)
{
    if(l>=L&&r<=R)
    {
        tag[x]+=v;
        mx[x].fi+=v;
        return ;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(L<=mid) add(ls,l,mid,L,R,v);
    if(R>mid)  add(rs,mid+1,r,L,R,v);
    pushup(x);
}
void build(int x,int l,int r)
{
    if(l==r)
    {
        mx[x]=make_pair(-ref[l],l);
        return ;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    pushup(x);
}
pair<ll,int> ask(int x,int l,int r,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return mx[x];
    }
    pushdown(x);
    int mid=(l+r)>>1;
    pair<ll,int> ret=make_pair(inf,0);
    if(L<=mid) ret=max(ret,ask(ls,l,mid,L,R));
    if(R>mid)  ret=max(ret,ask(rs,mid+1,r,L,R));
    pushup(x);
    return ret;
}
pair<ll,int> ans;
int x1;
int main()
{
    ans=make_pair(inf,0);
    n=read();
    for(int i=1;i<=n;i++)
    {
        int x=read(),y=read(),c=read();
        if(x>y)swap(x,y);
        a[i].x=x,a[i].y=y,a[i].c=c;
        stk[++top]=y,stk[++top]=x;
    }
    sort(stk+1,stk+top+1);
    int cntt=0;
    for(int i=1;i<=top;i++)
    if(!mp[stk[i]])mp[stk[i]]=++cntt,ref[cntt]=stk[i];

    for(int i=1;i<=n;i++)
    a[i].x=mp[a[i].x],a[i].y=mp[a[i].y];

    sort(a+1,a+n+1,cmpx);

    build(1,1,cntt);
    int j=1;

    for(int i=cntt;i>=1;i--)
    {
        while(j<=n&&a[j].x>=i)
        {
            add(1,1,cntt,a[j].y,cntt,a[j].c);
            j++;
        }
        pair<ll,int> tmp=ask(1,1,cntt,i,cntt);
        tmp.fi+=ref[i];
        if(tmp>ans)
        {
            ans=tmp;
            x1=ref[i];
        }
    }
    if(ans.fi<0)
    {
        cout<<0<<endl;
        cout<<111111111<<' '<<111111111<<' '<<111111111<<' '<<111111111<<endl;
        return 0;
    }
    cout<<ans.fi<<endl;
    cout<<x1<<' '<<x1<<' '<<ref[ans.se]<<' '<<ref[ans.se];
}