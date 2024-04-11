#include<bits/stdc++.h>
using namespace std;

int read();
#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5;
int n,dlg[N];
ll a[N],f[20][N];
ll gcd(ll x,ll y) {
	return !y ? x : gcd(y,x % y);
}
ll getgcd(int l,int r) {
	int k = dlg[r-l+1];
	return gcd(f[k][l],f[k][r-(1<<k)+1]);
}
int main() {
	int t;
	scanf("%d",&t);
	dlg[0] = -1;
	while(t--) {
		scanf("%d",&n);
		fr(i,1,n) scanf("%lld",&f[0][i]);
		fo(i,1,n) f[0][i] = f[0][i] - f[0][i+1];
		fr(i,1,n) dlg[i] = dlg[i>>1] + 1;
		fr(k,1,18) fr(i,1,n-(1<<k))
			f[k][i] = gcd(f[k-1][i],f[k-1][i+(1<<k-1)]);
		int ans = 0;
		fo(i,1,n) {
			int l = 1,r = i;
			if(abs(f[0][i]) == 1) continue;
			while(l < r) {
				int mid = l + r >> 1;
				if(abs(getgcd(mid,i)) != 1) r = mid;
				else l = mid+1;
			}
			ans = max(ans,i-l+1);
		}
		printf("%d\n",ans + 1);
	}
	return 0;
}