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

const int N = 2e5 + 5;
int t,n,k,a[N];
bool cmp(int i,int j) {
	return i > j;
}
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> k;
		fr(i,1,n) cin >> a[i];
		sort(a+1,a+n+1,cmp);
		LL ans = 0;
		fr(i,1,k+1) ans += a[i];
		cout << ans << endl;
	}
	return 0;
}