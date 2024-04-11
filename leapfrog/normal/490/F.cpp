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
int n,tn[100005],ut,a[100005],et,head[100005];struct edge{int to,nxt;}e[200005];
struct segm{int ls,rs,mx[2];}t[10000005];int tt,rt[100005],tp,st[100005],res;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline segm& New(int &x) {return t[x=tp?st[tp--]:++tt];}
inline void Del(int &x) {t[st[++tp]=x]=(segm){0,0,0,0},x=0;}
inline void modif(int &x,int l,int r,int dw,int dc,int fg)
{
	x?t[x]:New(x);if(l==r) return t[x].mx[fg]=max(t[x].mx[fg],dc),void();
	if(dw<=((l+r)>>1)) modif(t[x].ls,l,(l+r)>>1,dw,dc,fg),t[x].mx[fg]=max(t[t[x].ls].mx[fg],t[t[x].rs].mx[fg]);
	else modif(t[x].rs,((l+r)>>1)+1,r,dw,dc,fg),t[x].mx[fg]=max(t[t[x].ls].mx[fg],t[t[x].rs].mx[fg]);
}
inline int merge(int &x,int &y)
{
	if(!x||!y||!(x^y)) return x|y;
	t[x].mx[0]=max(t[x].mx[0],t[y].mx[0]),t[x].mx[1]=max(t[x].mx[1],t[y].mx[1]);
	res=max(res,max(t[t[x].ls].mx[0]+t[t[y].rs].mx[1],t[t[y].ls].mx[0]+t[t[x].rs].mx[1]));
	return t[x].ls=merge(t[x].ls,t[y].ls),t[x].rs=merge(t[x].rs,t[y].rs),Del(y),x;
}
inline int query(int x,int l,int r,int dl,int dr,int fg)
{
	if(l>dr||dl>r||!x) return 0;else if(dl<=l&&r<=dr) return t[x].mx[fg];
	return max(query(t[x].ls,l,(l+r)>>1,dl,dr,fg),query(t[x].rs,((l+r)>>1)+1,r,dl,dr,fg));
}
inline void paint(int x,int l,int r)
{
	if(!x) return;else if(l==r) printf("<%d,%d,%d> ",l,t[x].mx[0],t[x].mx[1]);
	else paint(t[x].ls,l,(l+r)>>1),paint(t[x].rs,((l+r)>>1)+1,r);
}
inline void dfs(int x,int fa)
{
	int qw[2];qw[0]=qw[1]=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs(e[i].to,x);int gg[2];
		gg[0]=query(rt[e[i].to],1,ut,1,a[x]-1,0),gg[1]=query(rt[e[i].to],1,ut,a[x]+1,ut,1);
		rt[x]=merge(rt[x],rt[e[i].to]),res=max(res,max(gg[0]+qw[1],gg[1]+qw[0])+1);
		qw[0]=max(qw[0],gg[0]),qw[1]=max(qw[1],gg[1]);
	}
	modif(rt[x],1,ut,a[x],qw[0]+1,0),modif(rt[x],1,ut,a[x],qw[1]+1,1);
	//paint(rt[x],1,ut),putchar('\n');
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),tn[i]=a[i];
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	sort(tn+1,tn+n+1),ut=unique(tn+1,tn+n+1)-tn-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+ut+1,a[i])-tn;
	return dfs(1,0),printf("%d\n",res),0;
}