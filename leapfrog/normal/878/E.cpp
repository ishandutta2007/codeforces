//
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1000000007,I=500000004;const long long INF=1000000000000000LL;
struct qry{int l,r,id;bool operator<(qry b) const {return r<b.r;}}q[100005];
int n,Q,a[100005],fa[100005],pw[100005],iv[100005],qwq[100005],tp=0,st[100005],r[100005],s[100005];long long sm[100005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void Ins(int id)
{
	st[++tp]=id,sm[tp]=a[id];
	while(tp>1&&sm[tp]>0)
	{
		if(st[tp]-st[tp-1]>=50||(1ll<<(st[tp]-st[tp-1]))>(INF-sm[tp-1])/sm[tp]) sm[--tp]=INF;
		else sm[tp-1]=sm[tp-1]+(1ll<<(st[tp]-st[tp-1]))*sm[tp],tp--;
	}
	if(sm[tp]<INF) s[tp]=(s[tp-1]+sm[tp]%P)%P;else s[tp]=qwq[id];
}
signed main()
{
	read(n),read(Q),iv[0]=pw[0]=1;
	for(int i=1;i<=n;i++) read(a[i]),pw[i]=(pw[i-1]<<1)%P,iv[i]=1ll*iv[i-1]*I%P,qwq[i]=(qwq[i-1]+1ll*pw[i]*a[i]%P)%P;
	for(int i=1;i<=Q;i++) read(q[i].l),read(q[i].r),q[i].id=i;
	sort(q+1,q+Q+1);for(int i=1,j=1;i<=Q;i++)
	{
		while(j<=q[i].r) Ins(j),j++;
		st[tp+1]=q[i].r+1;int w=upper_bound(st+1,st+tp+2,q[i].l)-st;
		r[q[i].id]=((s[tp]-s[w-1]+P)%P*2ll%P+(qwq[st[w]-1]-qwq[q[i].l-1]+P)%P*1ll*iv[q[i].l]%P)%P;
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",(r[i]%P+P)%P);
	return 0;
}