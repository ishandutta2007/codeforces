#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=(1<<18)+20;
int a[N],n,q;
struct info {
	ll mss, mpre, msuf, s;
	info () {}
	info (int a):mss(max(a,0)), mpre(max(a,0)),
		msuf(max(a,0)), s(a) {}
};

info operator + (const info &l, const info &r) {
	info a;
	a.mss = max({l.mss, r.mss, l.msuf + r.mpre});
	a.mpre = max(l.mpre, l.s + r.mpre);
	a.msuf = max(r.msuf, r.s + l.msuf);
	a.s = l.s + r.s;
	return a;
}

vector<info> build(int l,int r) {
	if (l==r) {
		return {info(a[l])};
	} else {
		int md=(l+r)>>1;
		auto vl=build(l,md);
		auto vr=build(md+1,r);
		int sz=(r-l+1);
		vector<info> ret(sz);
		rep(i,0,sz/2) ret[i]=vl[i]+vr[i],ret[i+sz/2]=vr[i]+vl[i];
		return ret;
	}
}

int main() {
	scanf("%d",&n);
	rep(i,0,(1<<n)) scanf("%d",a+i);
	auto ans=build(0,(1<<n)-1);
	scanf("%d",&q);
	int off=0;
	rep(i,0,q) {
		int v;
		scanf("%d",&v);
		off^=(1<<v);
		printf("%lld\n",ans[off].mss);
	}
}