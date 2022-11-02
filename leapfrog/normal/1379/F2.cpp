//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}//}}}
int n,m,Q;set<int>A[200005],B[200005];map<pair<int,int>,char>mp;
struct seg{int mn,mx;char fg;}T[800005];
inline seg operator+(seg a,seg b)
{
    seg r;r.mn=min(a.mn,b.mn),r.mx=max(a.mx,b.mx);
    return r.fg=a.fg|b.fg|(b.mx>=a.mn),r;
}
inline void build(int x,int l,int r)
{
    if(l==r) return T[x].mn=m+1,T[x].mx=0,void();
    build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]+T[x<<1|1];
}
inline void updat(int x,int l,int r,int dw)
{
    if(l==r)
    {
        T[x].mn=A[l].empty()?m+1:*A[l].begin();
        T[x].mx=B[l].empty()?0:*B[l].rbegin();
        return T[x].fg=T[x].mx>=T[x].mn,void();
    }
    if(dw<=((l+r)>>1)) updat(x<<1,l,(l+r)>>1,dw),T[x]=T[x<<1]+T[x<<1|1];
    else updat(x<<1|1,((l+r)>>1)+1,r,dw),T[x]=T[x<<1]+T[x<<1|1];
}
inline void solve()
{
    int x,y;read(x),read(y),x++,y++;
    if(mp[make_pair(x,y)]) (y&1?B:A)[x>>1].erase(y>>1);else (y&1?B:A)[x>>1].insert(y>>1);
    mp[make_pair(x,y)]^=1,updat(1,1,n,x>>1),puts(T[1].fg?"NO":"YES");
}
int main() {for(read(n),read(m),read(Q),build(1,1,n);Q--;) solve();return 0;}