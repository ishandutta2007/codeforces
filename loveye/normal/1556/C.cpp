#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1005;
int n,a[N],s[N],l[N],r[N],f[N][N];
signed main() {
	cin >> n;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) if(i & 1) {
		s[i] = s[i-1] + a[i];
		l[i] = s[i-1] + 1;
		r[i] = s[i];
	} else {
		s[i] = s[i-1] - a[i];
		l[i] = s[i-1] - 1;
		r[i] = s[i];
	}
	l[1] = 0;
	memset(f,0x3f,sizeof f);
	fr(i,1,n) f[i][i] = min(l[i],r[i]);
	fr(i,2,n) fr(j,1,n-i+1) f[j][j+i-1] = min(f[j][j+i-2],f[j+1][j+i-1]);
	ll ans = 0;
	fr(i,1,n) fr(j,i+1,n) {
		if(l[i] <= r[i] && l[j] >= r[j]) {
			int L = max(l[i],r[j]);
			int R = min(r[i],l[j]);
			R = min(R,f[i+1][j-1]);
			if(L > R) continue;
			ans += R-L+1;
		} else if(l[i] <= r[i] && l[j] <= r[j]) {
			if(l[i] <= l[j] && l[j] <= r[i] && f[i+1][j-1] >= l[j])
				++ans;
		} else if(l[i] >= r[i] && l[j] >= r[j]) {
			if(l[j] >= r[i] && r[i] >= r[j] && f[i+1][j-1] >= r[i])
				++ans;
		} else {
			if(r[i] == l[j] && f[i+1][j-1] >= r[i])
				++ans;
		}
	}
	cout << ans << endl;
	return 0;
}