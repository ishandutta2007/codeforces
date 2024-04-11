//
#include<bits/stdc++.h>
char buf[1<<22],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,m,a[500005],bl[500005],cnt[500005],st[500005],tp,wh[500005],rs[500005];
struct node{int l,r,id;bool operator<(node b) const {return bl[l]^bl[b.l]?l<b.l:(bl[l]&1?r<b.r:r>b.r);}}q[500005];
inline void add(int x) {++cnt[x];if(cnt[x]==1) st[++tp]=x,wh[x]=tp;else if(cnt[x]==2) st[wh[x]]=st[tp],wh[st[tp]]=wh[x],st[tp--]=wh[x]=0;}
inline void del(int x) {--cnt[x];if(cnt[x]==1) st[++tp]=x,wh[x]=tp;else if(cnt[x]==0) st[wh[x]]=st[tp],wh[st[tp]]=wh[x],st[tp--]=wh[x]=0;}
int main()
{
	read(n);const int sz=sqrt(n);for(int i=1;i<=n;i++) read(a[i]),bl[i]=(i-1)/sz+1;
	read(m);for(int i=1;i<=m;i++) read(q[i].l),read(q[i].r),q[i].id=i;
	sort(q+1,q+m+1);int l=1,r=1;add(a[1]);
	for(int i=1;i<=m;rs[q[i].id]=st[tp],i++)
	{
		while(r<q[i].r) add(a[++r]);
		while(r>q[i].r) del(a[r--]);
		while(l<q[i].l) del(a[l++]);
		while(l>q[i].l) add(a[--l]);
	}
	for(int i=1;i<=m;i++) printf("%d\n",rs[i]);
	return 0;
}