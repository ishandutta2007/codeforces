#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn=50005;
const int maxm=50005;
int n,m;
pii p[maxm];
ll kcz,k,s[maxn];
struct matrix_
{
    ll a[2][2];
    inline matrix_() { }
    inline matrix_(ll x,ll y,ll z,ll w) { a[0][0]=x,a[0][1]=y,a[1][0]=z,a[1][1]=w; }
    inline matrix_ operator *(const matrix_ &ma) const
    {
        matrix_ res;
        res.a[0][0]=(a[0][0]*ma.a[0][0]+a[0][1]*ma.a[1][0])%kcz;
        res.a[0][1]=(a[0][0]*ma.a[0][1]+a[0][1]*ma.a[1][1])%kcz;
        res.a[1][0]=(a[1][0]*ma.a[0][0]+a[1][1]*ma.a[1][0])%kcz;
        res.a[1][1]=(a[1][0]*ma.a[0][1]+a[1][1]*ma.a[1][1])%kcz;
        return res;
    }
    inline pii operator *(const pii &vec) const
    {
        return make_pair((a[0][0]*vec.first+a[0][1]*vec.second)%kcz,
            (a[1][0]*vec.first+a[1][1]*vec.second)%kcz);
    }
}tr[maxn<<2];
inline matrix_ qpow(matrix_ a,ll k)
{
    matrix_ res(1,0,0,1);
    while(k)
    {
        if(k&1) res=res*a;
        if(k>>=1) a=a*a;
    }
    return res;
}
void build(int rt,int l,int r)
{
    if(l==r) { tr[rt]=matrix_(s[(l+n-1)%n],s[(l+n-2)%n],1,0); return; }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
    tr[rt]=tr[(rt<<1)|1]*tr[rt<<1];
}
matrix_ query(int rt,int l,int r,int x,int y)
{
    if(x<=l && r<=y) return tr[rt];
    int mid=(l+r)>>1;
    if(y<=mid) return query(rt<<1,l,mid,x,y);
    if(mid<x) return query((rt<<1)|1,mid+1,r,x,y);
    return query((rt<<1)|1,mid+1,r,x,y)*query(rt<<1,l,mid,x,y);
}
int main()
{
    int i;
    pii cur; ll pos=1; // (f_n,f_{n-1})
    scanf("%lld%lld%d",&k,&kcz,&n);
    if(k==0) { printf("0\n"); return 0; }
    if(k==1) { printf("%d\n",(int)(1%kcz)); return 0; }
    for(i=0;i<n;i++) scanf("%lld",&s[i]),s[i]%=kcz;
    if(n==1) n++,s[1]=s[0];
    build(1,0,n-1);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&p[i].first,&p[i].second);
        if(p[i].first>=k) i--,m--;
    }
    sort(p,p+m),p[m].first=k,cur=make_pair(1%kcz,0);
    for(i=0;i<=m;i++)
    {
        if(pos/n<p[i].first/n)
        {
            if(pos%n!=n-1) cur=query(1,0,n-1,pos%n+1,n-1)*cur,pos+=n-pos%n-1;
            cur=qpow(tr[1],p[i].first/n-pos/n-1)*cur,pos=p[i].first-p[i].first%n-1;
            cur=query(1,0,n-1,0,p[i].first%n)*cur,pos=p[i].first;
        }
        else if(pos<p[i].first) cur=query(1,0,n-1,pos%n+1,p[i].first%n)*cur,pos=p[i].first;
        // printf("%lld %lld\n",pos,cur.first);
        if(i==m) { printf("%lld\n",cur.first); return 0;  }
        cur=matrix_(p[i].second,(i && p[i-1].first==pos-1)?p[i-1].second:s[(pos-1)%n],1,0)*cur,pos++;
        if(pos<p[i+1].first) cur=matrix_(s[pos%n],p[i].second,1,0)*cur,pos++;
        // printf("%lld %lld\n",pos,cur.first);
    }
    return 0;
}