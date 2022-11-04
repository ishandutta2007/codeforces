#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

struct edge {int to,nxt;} e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,c[N],m,bl,b[N],et[N],tick,s[N],t[N],cnt[N],sum[N],ans[N];

struct query{int id,l,r,k;}q[N];
bool cmp(const query &x,const query &y) {
	return b[x.l]==b[y.l]?x.r<y.r:b[x.l]<b[y.l];
}
void inc(int x) {cnt[c[et[x]]]++,sum[cnt[c[et[x]]]]++;}
void dec(int x) {sum[cnt[c[et[x]]]]--,cnt[c[et[x]]]--;}

void dfs(int u,int fa) {
	et[s[u]=++tick]=u;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		dfs(v,u);
	}
	t[u]=tick;
} 

signed main() {
	n=read(), m=read();
	rep(i,1,n) c[i]=read();
	rep(i,1,n-1) {
		int u=read(), v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	bl=sqrt(n);
	rep(i,1,n) b[i]=(i-1)/bl+1;
	rep(i,1,m) {
		int u=read(), k=read();
		q[i]=(query){i,s[u],t[u],k};
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	rep(i,1,m) {
		while(l>q[i].l) inc(--l);
		while(r<q[i].r) inc(++r);
		while(l<q[i].l) dec(l++);
		while(r>q[i].r) dec(r--);
		ans[q[i].id]=sum[q[i].k];
	}
	rep(i,1,m) printf("%d\n",ans[i]);
	return 0;
}