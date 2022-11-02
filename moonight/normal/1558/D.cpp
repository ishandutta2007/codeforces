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
const int N=200005,NN=400005,P=998244353;
int n,m,tt,rt,a[N],b[N],c[N],fac[NN],ifac[NN];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int C(int a,int b){return a<b||a<0||b<0?0:1ll*fac[a]*ifac[b]%P*ifac[a-b]%P;}
struct st{int l,r,w,p,s,o;}t[N];
inline int rnd()
{
    return rand();
}
inline int newnd(int w,int s){t[++tt]=(st){0,0,w,rnd(),s,s};return tt;}
inline void up(int x){t[x].s=t[t[x].l].s+t[t[x].r].s+t[x].o;}
int merge(int x,int y)
{
    if(!x||!y)return x|y;
    if(t[x].p<t[y].p){t[x].r=merge(t[x].r,y);up(x);return x;}
    t[y].l=merge(x,t[y].l);up(y);return y;
}
void split(int rt,int k,int&x,int&y)
{
    if(!rt){x=y=0;return;}
    int ls=t[t[rt].l].s+t[rt].o;
    if(ls<=k)
    {
        x=rt,split(t[x].r,k-ls,t[x].r,y);
        up(rt);return;
    }
    ls=t[t[rt].l].s;
    if(k<=ls)
    {
        y=rt,split(t[y].l,k,x,t[y].l);
        up(rt);return;
    }
    k-=ls;
    int p=newnd(t[rt].w+k,t[rt].o-k);
    t[rt].o=k;
    x=rt;y=p;t[y].r=t[x].r;t[x].r=0;
    up(rt);up(p);
}
inline int fndkth(int x,int k)
{
    while(1)
    {
        int ls=t[t[x].l].s;
        if(k<=ls){x=t[x].l;continue;}
        return t[x].w;
    }
}
/*
void dfs(int x)
{
    if(!x)return;
    dfs(t[x].l);
    d[++nn]=t[x].w;
    dfs(t[x].r);
}*/
map<int,int>mp;
void sol()
{
    n=rd();m=rd();tt=0;rt=0;
    t[0]=(st){0,0,0,0,0};mp.clear();
    rep(i,1,m)a[i]=rd(),b[i]=rd();
    int k=1,ans=0;
    rep(i,1,m)
    {
        if(a[i]-a[i-1]>1)
        {
            rt=merge(rt,newnd(a[i-1]+1,a[i]-a[i-1]-1));
        }
        int x=a[i],y=b[i],A,B;
        split(rt,y-1,A,B);
        int z=fndkth(B,1);
        if(!mp[z]){k++;mp[z]=1;}
        rt=merge(merge(A,newnd(x,1)),B);
    }
    ans=(C(n+n-k,n)+P-C(n-k,n))%P;
    printf("%d\n",ans);
}
int main()
{
    srand(time(0));
    fac[0]=1;ifac[0]=1;
    rep0(i,1,NN)fac[i]=1ll*fac[i-1]*i%P;
    rep0(i,1,NN)ifac[i]=pw(fac[i],P-2);
    int T=rd();
    while(T--)sol();
    return 0;
}