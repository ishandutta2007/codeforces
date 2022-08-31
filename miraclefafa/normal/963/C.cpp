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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
map<ll,int> hs1,hs2;
map<int,ll> e[N];
int n,l,r,cnt;
ll w,h,c;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%lld%lld%lld",&w,&h,&c);
		if (!hs1.count(w)) hs1[w]=++l;
		if (!hs2.count(h)) hs2[h]=++r;
		e[hs1[w]][hs2[h]]=c;
	}
	rep(i,1,l+1) if (SZ(e[i])!=r) {
		puts("0"); return 0;
	}
	rep(i,1,l+1) rep(j,1,r+1) {
		ll p00=e[1][1],p01=e[1][j],p10=e[i][1],p11=e[i][j];
		ll d1=gcd(p00,p10),d2=gcd(p01,p11);
		p00/=d1; p10/=d1; p01/=d2; p11/=d2;
		if (p00!=p01||p10!=p11) {
			puts("0"); return 0;
		}
	}
	ll d1=e[1][1],d2=e[1][1],w=e[1][1];
	rep(i,1,r+1) d1=gcd(d1,e[1][i]);
	rep(i,1,l+1) d2=gcd(d2,e[i][1]);
	for (ll p=1;p*p<=w;p++) if (w%p==0) {
		ll q=w/p;
		if (d1%p==0&&d2%q==0) cnt++;
		if (p!=q&&d1%q==0&&d2%p==0) cnt++;
	}
	printf("%d\n",cnt);
}