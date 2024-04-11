#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 3e5 + 5;
int n,m,a[N],ans[N];
int bls,bln,bl[N],L[N],R[N];
struct Query {
	int l,r,id;
	inline bool operator < (const Query &o) {
		return bl[l] ^ bl[o.l] ? bl[l] < bl[o.l] : r < o.r;
	}
} q[N];
I prepare() {
	bls = ceil(n / sqrt(m));
	while(R[bln] < n) ++bln,L[bln] = R[bln-1] + 1,R[bln] = bln * bls;
	R[bln] = n;
	fr(i,1,bln) fr(j,L[i],R[i]) bl[j] = i;
}
int mx,cnt[N],smx,scnt[N];
int tmp[N];
I add(int i) {
	if((++cnt[a[i]]) > mx) mx = cnt[a[i]];
}
I chkans(int i,int x) {
	ans[q[i].id] = max(1,x * 2 - (q[i].r-q[i].l+1));
#ifdef ZXY
	ans[q[i].id] = x;
#endif
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	fr(i,1,n) cin >> a[i];
	prepare();
	fr(i,1,m) cin >> q[i].l >> q[i].r,q[i].id = i;
	sort(q+1,q+m+1);
	int pos = 1,l,r;
	fr(k,1,bln) {
		mx = 0,l = R[k]+1,r = l-1;
		fr(i,1,n) cnt[i] = 0;
		while(pos <= m && bl[q[pos].l] == k) {
			if(bl[q[pos].r] == k) {
				int res = 0;
				fr(i,q[pos].l,q[pos].r) tmp[a[i]] = 0;
				fr(i,q[pos].l,q[pos].r) if((++tmp[a[i]]) > res) res = tmp[a[i]];
				chkans(pos,res);
			} else {
				while(r < q[pos].r) add(++r);
				smx = mx;
				rf(i,l-1,q[pos].l) scnt[a[i]] = cnt[a[i]];
				while(l > q[pos].l) add(--l);
				chkans(pos,mx);
				l = R[k]+1;
				mx = smx;
				rf(i,l-1,q[pos].l) cnt[a[i]] = scnt[a[i]];
			}
			++pos;
		}
	}
	fr(i,1,m) cout << ans[i] << endl;
	return 0;
}