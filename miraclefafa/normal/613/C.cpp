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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n,a[101000];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	if (n==1) {
		printf("%d\n",a[0]);
		rep(i,0,a[0]) putchar('a');
		puts("");
		return 0;
	}
	int cnt=0;
	rep(i,0,n) cnt+=a[i]&1;
	if (cnt>=2) {
		puts("0");
		rep(i,0,n) rep(j,0,a[i]) putchar('a'+i);
		puts("");
		return 0;
	}
	int d=a[0];
	rep(i,1,n) d=__gcd(d,a[i]);
	printf("%d\n",d);
	if (cnt==1) {
		rep(k,0,d) {
			rep(i,0,n) rep(j,0,a[i]/d/2) putchar('a'+i);
			rep(i,0,n) if (a[i]/d%2==1) putchar('a'+i);
			per(i,0,n) rep(j,0,a[i]/d/2) putchar('a'+i);
		}
		puts("");
		return 0;
	}
	rep(k,0,d/2) {
		rep(i,0,n) rep(j,0,a[i]/d) putchar('a'+i);
		per(i,0,n) rep(j,0,a[i]/d) putchar('a'+i);
	}
	puts("");
}