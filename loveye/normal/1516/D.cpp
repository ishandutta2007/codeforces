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

const int N = 1e5 + 5;
int n,q,a[N],pre[N],bz[N][21];
vector<int> f[N];
int st[N][21];
inline int getmax(int l,int r) {
	int k = log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main() {
	cin >> n >> q;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) {
		int sx = sqrt(a[i]) + 0.5,res = a[i];
		fr(j,2,sx) if(res % j == 0) {
			do res /= j; while(res % j == 0);
			if(f[j].size()) pre[i] = max(f[j].back(),pre[i]);
			f[j].push_back(i);
		}
		if(res != 1) {
			if(f[res].size()) pre[i] = max(f[res].back(),pre[i]);
			f[res].push_back(i);
		}
	}
	fr(i,1,n) st[i][0] = pre[i];
	fr(k,1,20) fr(i,1,n-(1<<k)+1) st[i][k] = max(st[i][k-1],st[i+(1<<k-1)][k-1]);
	fr(i,1,n) {
		int l = i,r = n;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(getmax(i,mid) < i) l = mid;
			else r = mid-1;
		}
		bz[i][0] = l+1;
	}
	fr(k,0,20) bz[n+1][k] = n+1;
	fr(k,1,20) fr(i,1,n) bz[i][k] = bz[bz[i][k-1]][k-1];
	while(q--) {
		int l,r,cur,ans = 0;
		cin >> l >> r;
		cur = l;
		rf(k,20,0) if(bz[cur][k] <= r) cur = bz[cur][k],ans += 1 << k;
		ans += 1;
		cout << ans << endl;
	}
	return 0;
}