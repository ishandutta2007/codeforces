#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int MOD1 = 1e9 + 7,MOD2 = 998244353;
ll n,c1,c2,ans,pw[20],sum[10];
vector<ll> buc[10];
void query(ll p,ll s) {
	fr(i,0,6) {
		ll x = ((s - p * pw[i]) % MOD2 + MOD2) % MOD2;
		(ans += x * buc[i].size() + sum[i]) %= MOD1;
		(ans -= 1ll * (buc[i].end() - lower_bound(buc[i].begin(),buc[i].end(),MOD2-x)) * MOD2) %= MOD1;
	}
}
void dfs(ll x,int d) {
	ll tmp = ((c1++ - x) % MOD2 + MOD2) % MOD2;
	(sum[d] += tmp) %= MOD1;
	buc[d].push_back(tmp);
	if(d == 6) return;
	fr(i,0,9) dfs(x * 10 + i,d+1);
}
void dfs2(ll x) {
	if(x > n) return;
	if((x + 1) * ll(1e6) <= n+1 && x * ll(1e7) > n)
		query(x,c2),c2 += c1;
	else {
		(ans += ((c2++ - x) % MOD2 + MOD2) % MOD2) %= MOD1;
		fr(i,x ? 0 : 1,9) dfs2(x * 10 + i);
	}
}
int main() {
	cin >> n;
	dfs(0,0);
	fr(i,1,6) sort(buc[i].begin(),buc[i].end());
	pw[0] = 1; fr(i,1,12) pw[i] = pw[i-1] * 10;
	dfs2(0);
	cout << (ans + MOD1) % MOD1 << endl;
	return 0;
}