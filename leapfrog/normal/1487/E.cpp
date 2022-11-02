#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
int T[600005],na,nb,nc,nd,m,a[150005],b[150005],c[150005],d[150005];
vector<int>eb[150005],ec[150005],ed[150005];int st[150005],tp;
inline void build(int x,int l,int r,int *a)
{
    if(l==r) return T[x]=a[l],void();
    build(x<<1,l,(l+r)>>1,a),build(x<<1|1,((l+r)>>1)+1,r,a),T[x]=min(T[x<<1],T[x<<1|1]);
}
inline void modif(int x,int l,int r,int dw,int dc)
{
    if(l==r) return T[x]=dc,void();
    if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
    else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
}
signed main()
{
    read(na),read(nb),read(nc),read(nd);
    for(int i=1;i<=na;i++) read(a[i]);
    for(int i=1;i<=nb;i++) read(b[i]);
    for(int i=1;i<=nc;i++) read(c[i]);
    for(int i=1;i<=nd;i++) read(d[i]);
    read(m);for(int x,y;m--;) read(x),read(y),eb[y].push_back(x);
    read(m);for(int x,y;m--;) read(x),read(y),ec[y].push_back(x);
    read(m);for(int x,y;m--;) read(x),read(y),ed[y].push_back(x);
    build(1,1,na,a);for(int i=1;i<=nb;i++)
    {
        tp=0;for(auto x:eb[i]) st[++tp]=a[x],modif(1,1,na,x,1e9+5);
        tp=0,b[i]+=T[1];for(auto x:eb[i]) modif(1,1,na,x,st[++tp]);
    }
    build(1,1,nb,b);for(int i=1;i<=nc;i++)
    {
        tp=0;for(auto x:ec[i]) st[++tp]=b[x],modif(1,1,nb,x,1e9+5);
        tp=0,c[i]+=T[1];for(auto x:ec[i]) modif(1,1,nb,x,st[++tp]);
    }
    build(1,1,nc,c);for(int i=1;i<=nd;i++)
    {
        tp=0;for(auto x:ed[i]) st[++tp]=c[x],modif(1,1,nc,x,1e9+5);
        tp=0,d[i]+=T[1];for(auto x:ed[i]) modif(1,1,nc,x,st[++tp]);
    }
    int mn=1e9+5;for(int i=1;i<=nd;i++) mn=min(mn,d[i]);
    return printf("%lld\n",mn>=1e9+5?-1:mn),0;
}