#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e6 + 5;
int n,m,t,id[N];
int a[N],b[N];
int seg[N << 2],pos[N << 2],tag[N << 2];
#define lc (k << 1)
#define rc (lc | 1)
#define left lc,l,mid
#define right rc,mid+1,r
void pushup(int k) {
	if(seg[lc] < seg[rc]) {
		seg[k] = seg[lc];
		pos[k] = pos[lc];
	} else {
		seg[k] = seg[rc];
		pos[k] = pos[rc];
	}
}
void build(int k,int l,int r) {
	tag[k] = 0;
	if(l == r) {
		seg[k] = l-1; pos[k] = l;
		return;
	}
	int mid = l + r >> 1;
	build(left); build(right); pushup(k);
}
void puttag(int k,int v) {
	tag[k] += v; seg[k] += v;
}
void pushdown(int k) {
	if(tag[k]) {
		puttag(lc,tag[k]),puttag(rc,tag[k]),tag[k] = 0;
	}
}
void change(int k,int l,int r,int x,int y,int v) {
	if(x <= l && r <= y) return puttag(k,v);
	int mid = l + r >> 1;
	pushdown(k);
	if(x <= mid) change(left,x,y,v);
	if(y > mid) change(right,x,y,v);
	pushup(k);
}
vector<int> lsh;
int BIT[N]; void add(int x,int v) {for(;x <= n;x += x & -x) BIT[x] += v;}
int ask(int x) {int res = 0; for(;x;x &= x-1) res += BIT[x]; return res;}
int calc() {
	lsh.clear();
	fr(i,1,n) lsh.push_back(a[i]);
	sort(lsh.begin(),lsh.end());
	fr(i,1,n) a[i] = lower_bound(lsh.begin(),lsh.end(),a[i]) - lsh.begin() + 1;
	ll res = 0;
	rf(i,n,1) add(a[i],1),res += ask(a[i]-1);
	fr(i,1,n) BIT[i] = 0;
	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		fr(i,1,n) cin >> a[i],id[i] = i;
		fr(i,1,m) cin >> b[i];
		sort(id+1,id+n+1,[](const int &i,const int &j) {
			return a[i] < a[j];
		});
		sort(b+1,b+m+1);
		build(1,1,n+1);
		int p = 1,q = 1;
		ll ans = 0;
		fr(i,1,m) {
			while(p <= n && a[id[p]] < b[i]) {
				change(1,1,n+1,1,id[p],1);
				++p;
			}
			while(q <= n && a[id[q]] <= b[i]) {
				change(1,1,n+1,id[q]+1,n+1,-1);
				++q;
			}
			ans += seg[1];
		}
		cout << ans + calc() << endl;
	}//clear
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