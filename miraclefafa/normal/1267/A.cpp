#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n;
ll l,r,t;
vector<pair<ll,ll>> v;
multiset<ll> pro;

int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%lld%lld%lld",&l,&r,&t);
		l*=2; r*=2; t*=2; r++;
		v.pb(mp(l,t));
		v.pb(mp(r-t,-t));
	}
	ll z=0;
	ll cnt=0;
	sort(all(v));
	rep(i,0,SZ(v)) {
		// z to v[i].fi
		//printf("gg %lld %lld\n",v[i].fi,v[i].se);
		if (v[i].se>0) pro.insert(v[i].se);
		else {
			pro.erase(pro.lower_bound(-v[i].se));
		}
		if (!pro.empty()) {
			l=v[i].fi; r=v[i+1].fi;
			if (l+*pro.begin()<z) z=l+*pro.begin();
			z=max(z,l);
			if (z<=r) {
				ll w=(r-z)/(*pro.begin());
				cnt+=w;
				z+=w*(*pro.begin());
			}
			while (z<=r) {
				z+=*pro.begin();
				cnt++;
			}
		}
	}
	printf("%lld\n",cnt);
}