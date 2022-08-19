#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n;
ll query(int a,int b) {
	if (a>=b) return 0;
	printf("? %d %d\n",a,b);
	fflush(stdout);
	ll x;
	scanf("%lld",&x);
	return x;
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		int l=1,r=n+1;
		ll tot=query(1,n);
		while (l+1<r) {
			int md=(l+r)>>1;
			if (query(md,n)==tot) l=md; else r=md;
		}
		ll tot2=query(l+1,n);
		ll s1=tot-tot2;
		//printf("%lld %lld\n",(ll)l,l+s1);
		PII seg1(l,l+s1);
		l=l+s1+1;
		ll tot3=query(l,n);
		ll tot4=query(l+1,n);
		printf("! %d %d %lld\n",seg1.fi,seg1.se+1,l+tot3-tot4);
		fflush(stdout);
	}
}