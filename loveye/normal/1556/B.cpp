#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e6 + 5;
int n,a[N],p[N];
int BIT[N];
void add(int x,int v) {
	for(;x <= n;x += x & -x) BIT[x] += v;
}
int ask(int x) {
	int res = 0;
	for(;x;x -= x &- x) res += BIT[x];
	return res;
}
ll getans() {
	ll res = 0;
	rf(i,n,1) res += ask(p[i]),add(p[i],1);
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		cin >> n;
		int cnt[2] = {0};
		fr(i,1,n) {
			cin >> a[i],a[i] &= 1;
			++cnt[a[i]];
		}
		if(abs(cnt[0]-cnt[1]) > 1) {
			cout << -1 << endl;
			continue;
		}
		fr(i,1,n) BIT[i] = 0;
		ll ans0 = 1ll * n * n,ans1 = ans0;
		if(cnt[0] == cnt[1]) {
			int p0 = 1,p1 = 2;
			fr(i,1,n) if(a[i]) p[i] = p1,p1 += 2;
			else p[i] = p0,p0 += 2;
			ans0 = getans();
			fr(i,1,n) BIT[i] = 0;
			p0 = 2; p1 = 1;
			fr(i,1,n) if(a[i]) p[i] = p1,p1 += 2;
			else p[i] = p0,p0 += 2;
			ans1 = getans();
		} else if(cnt[0] > cnt[1]) {
			int p0 = 1,p1 = 2;
			fr(i,1,n) if(a[i]) p[i] = p1,p1 += 2;
			else p[i] = p0,p0 += 2;
			ans0 = getans();
		} else {
			int p0 = 2,p1 = 1;
			fr(i,1,n) if(a[i]) p[i] = p1,p1 += 2;
			else p[i] = p0,p0 += 2;
			ans0 = getans();
		}
		cout << min(ans0,ans1) << endl;
	}
	return 0;
}