#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
#pragma pack(1)

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 105,M = 6005,MOD = 998244353,iv2 = MOD+1>>1;
int na,nb;
struct Line {ll s; short d;};
vector<Line> t[2][65],a[2][65],ans;
void decomp(int dep,ll l,ll x,ll y,int job) {
	ll r = l + (1ll << dep),mid = l + (1ll << dep-1);
	a[job][dep].push_back((Line){l,dep});
	if(x <= l && r-1 <= y) return t[job][dep].push_back((Line){l,dep});
	if(x < mid) decomp(dep-1,l,x,y,job);
	if(y >= mid) decomp(dep-1,mid,x,y,job);
}
ll sum(ll l,ll r) {
	return (l + r-1) % MOD * ((r - l) % MOD) % MOD * iv2 % MOD;
}
int main() {
	scanf("%d",&na);
	fr(i,1,na) {
		ll l,r; scanf("%lld%lld",&l,&r);
		decomp(60,0,l,r,0);
	}
	scanf("%d",&nb);
	fr(i,1,nb) {
		ll l,r; scanf("%lld%lld",&l,&r);
		decomp(60,0,l,r,1);
	}
	fr(k,0,60) fr(o,0,1) for(auto x : t[o][k]) for(auto y : a[o^1][k]) {
		int d = max(x.d,y.d);
		ll s = (x.s ^ y.s) & ~((1ll << d) - 1ll);
		ans.push_back((Line){s,1});
		ans.push_back((Line){s + (1ll << d),-1});
	}

	sort(ans.begin(),ans.end(),[](const Line &a,const Line &b) {
		return a.s < b.s;
	});
	ll out = 0,now = 0,lst = 0;
	fo(i,0,ans.size()) {
		if(lst != ans[i].s && now)
			(out += sum(lst,ans[i].s)) %= MOD;
		lst = ans[i].s;
		now += ans[i].d;
	}
	printf("%lld\n",out);
	return 0;
}