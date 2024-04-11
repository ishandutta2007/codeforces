#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=1e5+5,MOD=1e9+7;
int n,a[N];
map<int,int> lst,cnt;
int pre[N],nxt[N];
int s1[N],t1,s2[N],t2;

#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
ll sa[N<<2],sb[N<<2],sab[N<<2],s0[N<<2],ta[N<<2],tb[N<<2];
void build(int k,int l,int r) {
	s0[k]=r-l+1; sb[k]=sab[k]=0;
	if(l==r) return sa[k]=l-1,void();
	int mid=l+r>>1;
	build(left); build(right);
	sa[k]=(sa[lc]+sa[rc])%MOD;
}
void putta(int k,ll v) {
	(ta[k]+=v)%=MOD;
	(sa[k]+=s0[k]*v)%=MOD;
	(sab[k]+=sb[k]*v)%=MOD;
}
void puttb(int k,ll v) {
	(tb[k]+=v)%=MOD;
	(sb[k]+=s0[k]*v)%=MOD;
	(sab[k]+=sa[k]*v)%=MOD;
}
void pushdown(int k) {
	if(ta[k]) putta(lc,ta[k]),putta(rc,ta[k]),ta[k]=0;
	if(tb[k]) puttb(lc,tb[k]),puttb(rc,tb[k]),tb[k]=0;
}
ll ans;
void change_a(int k,int l,int r,int x,int y,ll val) {
	if(x<=l&&r<=y) return putta(k,val);
	int mid=l+r>>1; pushdown(k);
	if(x<=mid) change_a(left,x,y,val);
	if(y>mid) change_a(right,x,y,val);
	sa[k]=(sa[lc]+sa[rc])%MOD;
	sab[k]=(sab[lc]+sab[rc])%MOD;
}
void change_b(int k,int l,int r,int x,int y,ll val) {
	if(x<=l&&r<=y) return puttb(k,val);
	int mid=l+r>>1; pushdown(k);
	if(x<=mid) change_b(left,x,y,val);
	if(y>mid) change_b(right,x,y,val);
	sb[k]=(sb[lc]+sb[rc])%MOD;
	sab[k]=(sab[lc]+sab[rc])%MOD;
}
void query(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y) {
		(ans+=sab[k]-(y+1)*sa[k])%=MOD;
		return;
	}
	int mid=l+r>>1; pushdown(k);
	if(x<=mid) query(left,x,y);
	if(y>mid) query(right,x,y);
}
int main() {
	n=read(); fr(i,1,n) a[i]=read();
	fr(i,1,n) pre[i]=lst[a[i]],lst[a[i]]=i;
	for(auto &p:lst) p.second=n+1;
	rf(i,n,1) nxt[i]=lst[a[i]],lst[a[i]]=i;
	build(1,1,n);
	for(int r=1,L=1;r<=n;++r) {
		while(t1&&pre[r]>=pre[s1[t1]])
			change_a(1,1,n,s1[t1-1]+1,s1[t1],pre[s1[t1]]),--t1;
		s1[++t1]=r;
		change_a(1,1,n,s1[t1-1]+1,s1[t1],-pre[s1[t1]]);
		while(t2&&nxt[r]<=nxt[s2[t2]])
			change_b(1,1,n,s2[t2-1]+1,s2[t2],-nxt[s2[t2]]),--t2;
		s2[++t2]=r;
		change_b(1,1,n,s2[t2-1]+1,s2[t2],nxt[s2[t2]]);

		++cnt[a[r]]; while(cnt[a[r]]>1) --cnt[a[L++]];
		//cout<<r<<' '<<ans<<' '<<L<<endl;
		query(1,1,n,L,r);
	}
	printf("%lld\n",(ans+MOD)%MOD);
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}