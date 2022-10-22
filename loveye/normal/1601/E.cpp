#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 3e5 + 5;
int n,m,k,dlg[N],stk[N],top,val[N],lim;
ll ans[N];
struct Query {
	int l,r,id;
} q[N];
int st[20][N];
int getmin(int l,int r) {
	int k = dlg[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
ll tag[N << 2],sum[N << 2];
#define lc (k << 1)
#define rc (lc | 1)
#define left lc,l,mid
#define right rc,mid+1,r
void puttag(int k,int l,int r,ll v) {
	tag[k] = v; sum[k] = (r-l+1) * v;
}
void pushdown(int k,int l,int r,int mid) {
	if(tag[k] != -1)
		puttag(left,tag[k]),puttag(right,tag[k]),tag[k] = -1;
}
void pushup(int k) {sum[k] = sum[lc] + sum[rc];}
void change(int k,int l,int r,int x,int y,int v) {
	if(x <= l && r <= y) return puttag(k,l,r,v);
	int mid = l + r >> 1; pushdown(k,l,r,mid);
	if(x <= mid) change(left,x,y,v);
	if(y > mid) change(right,x,y,v);
	pushup(k);
}
ll query(int k,int l,int r,int x,int y) {
	if(x <= l && r <= y) return sum[k];
	int mid = l + r >> 1; pushdown(k,l,r,mid);
	ll res = 0;
	if(x <= mid) res = query(left,x,y);
	if(y > mid) return res + query(right,x,y);
	return res;
}
void Insert(int i,int v) {
	while(top && val[top] >= v) --top;
	if(stk[top] == i) return;
	change(1,0,lim,i,stk[top] - 1,v);
	stk[++top] = i; val[top] = v;
}
int getval(int x,int y) {
	if(x % k >= y) return (x - (x % k - y)) / k;
	return (x - x % k + y - k) / k;
}
int main() {
	n = read(); m = read(); k = read();
	dlg[0] = -1;
	fr(i,1,n) st[0][i] = read(),dlg[i] = dlg[i>>1] + 1;
	fr(k,1,18) fr(i,1,n+1-(1<<k)) st[k][i] = min(st[k-1][i],st[k-1][i+(1<<k-1)]);
	fr(i,1,m) q[i].l = read(),q[i].r = read(),q[i].id = i;
	sort(q+1,q+m+1,[](const Query &a,const Query &b) {
		if(a.l % k ^ b.l % k) return a.l % k < b.l % k;
		return a.l > b.l;
	});
	lim = n / k + 1;
	memset(tag,-1,sizeof tag);
	int p;
	fr(i,1,m) {
		if(i == 1 || q[i].l % k != q[i-1].l % k) {
			p = q[i].l % k;
			while(p + k <= n) p += k;
			stk[top = 0] = lim;
			change(1,0,lim,0,lim,0);
		}
		for(;p >= q[i].l;p -= k) {
			Insert(p / k + 1,getmin(p+1,p+k));
			Insert(p / k,st[0][p]);
		}
		ans[q[i].id] = query(1,0,lim,q[i].l / k,getval(q[i].r,q[i].l % k));
	}
	fr(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}