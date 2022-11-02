//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int mn,fg;}T[1200005];
int n,m,H,a[150005],b[150005],tn[300005],ut;
inline void allc(int x,int w) {T[x].mn+=w,T[x].fg+=w;}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void pushup(int x) {T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);}
inline void modif(int x,int l,int r,int dl,int dr,int dw)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dw);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dw),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dw),pushup(x);
}
int main()
{
	read(n),read(m),read(H);int cnt=0;
	for(int i=1;i<=m;i++) read(b[i]),b[i]=H-b[i],tn[++ut]=b[i];
	for(int i=1;i<=n;i++) read(a[i]),tn[++ut]=a[i];
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=m;i++) b[i]=lower_bound(tn+1,tn+ut+1,b[i])-tn;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+ut+1,a[i])-tn;
	for(int i=1;i<=m;i++) modif(1,1,ut,a[i],ut,-1),modif(1,1,ut,b[i],ut,1);
	cnt+=T[1].mn>=0;//printf("?? %d\n",T[1].mn);
	for(int i=m+1;i<=n;i++) modif(1,1,ut,a[i-m],ut,1),modif(1,1,ut,a[i],ut,-1),cnt+=T[1].mn>=0;
	return printf("%d\n",cnt),0;
}