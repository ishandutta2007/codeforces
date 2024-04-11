#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e5 + 5;
#define int long long
int n,q,dlg[N];
int a[N],b[N],c[N],d[N];
int st[20][N],st2[20][N];
int getmax(int l,int r) {
	int k = dlg[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
int getmin(int l,int r) {
	int k = dlg[r-l+1];
	return min(st2[k][l],st2[k][r-(1<<k)+1]);
}
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> q;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) cin >> b[i];
	dlg[0] = -1;
	fr(i,1,n) {
		dlg[i] = dlg[i>>1] + 1;
		c[i] = b[i] - a[i];
		d[i] = d[i-1] + c[i];
		st[0][i] = st2[0][i] = d[i];
	}
	fr(k,1,18) fr(i,1,n-(1<<k)+1) {
		st[k][i] = max(st[k-1][i],st[k-1][i+(1<<k-1)]);
		st2[k][i] = min(st2[k-1][i],st2[k-1][i+(1<<k-1)]);
	}
	while(q--) {
		static int l,r;
		cin >> l >> r;
		if(d[r] != d[l-1] || getmin(l,r) < d[l-1]) {
			cout << -1 << endl; continue;
		}
		cout << getmax(l,r) - d[l-1] << endl;
	}
	return 0;
}