#include<cstdio>
#include<set>
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

const int N = 2e5 + 5,MOD = 998244353;
int n,m;
ll p[N],q[N],s[N],ans;
ll qpow(ll a,int x) {
	ll res = 1;
	for(;x;x >>= 1,a = a * a % MOD)
		if(x & 1) res = res * a % MOD;
	return res;
}
ll getsum(int l,int r) {
	return q[r] * (s[r] - s[l-1]) % MOD;
}
set<int> S;
int main() {
	scanf("%d%d",&n,&m);
	fr(i,1,n) scanf("%lld",p+i);
	q[0] = 1;
	fr(i,1,n) q[i] = q[i-1] * 100 % MOD * qpow(p[i],MOD-2) % MOD;
	fr(i,1,n) s[i] = (s[i-1] + qpow(q[i-1],MOD-2)) % MOD;
	S.insert(1),S.insert(n+1);
	ans = getsum(1,n);
	while(m--) {
		static int i,j;
		scanf("%d",&i);
		if(S.count(i)) {
			auto it = S.upper_bound(i);
			j = *it;
			ans -= getsum(i,j-1);
			--it,--it; j = *it;
			ans -= getsum(j,i-1);
			it = S.erase(++it);
			ans += getsum(j,*it-1);
		} else {
			auto it = S.upper_bound(i); j = *it;
			--it; ans -= getsum(*it,j-1);
			ans += getsum(*it,i-1);
			ans += getsum(i,j-1);
			S.insert(i);
		}
		ans %= MOD;
		printf("%lld\n",(ans + MOD) % MOD);
	}
	return 0;
}