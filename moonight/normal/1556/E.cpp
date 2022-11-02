#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=100005;
int n,Q;ll a[N],mn[N*4],mx[N*4];
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
void build(int x,int l,int r)
{
    if(l==r)
    {
        mn[x]=mx[x]=a[l];
        return;
    }
    int m=l+r>>1;
    build(ls);
    build(rs);
    mn[x]=min(mn[x<<1],mn[x<<1|1]);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
ll qmn(int x,int l,int r,int tl,int tr)
{
    if(tl<=l&&r<=tr)return mn[x];
    int m=l+r>>1;
    if(tr<=m)return qmn(ls,tl,tr);
    if(tl>m)return qmn(rs,tl,tr);
    return min(qmn(ls,tl,tr),qmn(rs,tl,tr));
}
ll qmx(int x,int l,int r,int tl,int tr)
{
    if(tl<=l&&r<=tr)return mx[x];
    int m=l+r>>1;
    if(tr<=m)return qmx(ls,tl,tr);
    if(tl>m)return qmx(rs,tl,tr);
    return max(qmx(ls,tl,tr),qmx(rs,tl,tr));
}
int main()
{
    n=rd();Q=rd();
    rep(i,1,n)a[i]=rd();
    rep(i,1,n)a[i]=rd()-a[i];
    rep(i,1,n)a[i]+=a[i-1];
    build(1,1,n);
    rep(i,1,Q)
    {
        int l=rd(),r=rd();
        ll mn=qmn(1,1,n,l,r);
        ll mx=qmx(1,1,n,l,r);
        mn-=a[l-1];mx-=a[l-1];
        if(mn<0||(a[r]!=a[l-1]))puts("-1");
        else printf("%lld\n",mx);
    }
    return 0;
}