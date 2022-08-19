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

int _;
ll p,q,b,d;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lld%lld%lld",&p,&q,&b);
		d=gcd(p,q); p/=d; q/=d;
		d=b;
		while (1) {
			d=gcd(q,d);
			if (d==1) break;
			q/=d;
		}
		puts(q==1?"Finite":"Infinite");
	}
}