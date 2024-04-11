#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

ll a1,a2,a3,a4;
ll ff(ll x) {
	ll c=1;
	while (1) {
		ll y=c*(c-1)/2;
		if (y==x) return c;
		if (y>x) return -1;
		++c;
	}
	assert(0);
	return 0;
}
int main() {
	scanf("%lld%lld%lld%lld",&a1,&a2,&a3,&a4);
	if (a1==0&&a2==0&&a3==0&&a4==0) {
		puts("1");
		return 0;		
	}
	ll p=ff(a1),q=ff(a4);
	if (a1==0&&a4==0) {
		p=1; q=1;
	} else if (a1==0) {
		if (a2+a3==0) p=0; else p=1;
	} else if (a4==0) {
		if (a2+a3==0) q=0; else q=1;
	}
	if (p==-1||q==-1||ff(a1+a2+a3+a4)!=p+q) {
		puts("Impossible");
		return 0;
	}
	if (a2>p*q||a3>p*q) {
		puts("Impossible");
		return 0;
	}
	while (a2>=q&&p>0) {
		putchar('0');
		a2-=q; p--;
	}
	if (a2==0) {
		rep(i,0,q) putchar('1');
		rep(i,0,p) putchar('0');
		puts("");
		return 0;
	}
	rep(i,0,q-a2) {
		putchar('1');
	}
	q=a2;
	putchar('0');
	p--;
	rep(i,0,q) putchar('1');
	rep(i,0,p) putchar('0');
	puts("");
}