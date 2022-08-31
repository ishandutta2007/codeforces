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
const ll mod=1000000009;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,k;
ll a,b,ret;
char s[101000];
int main() {
	scanf("%d%lld%lld%d",&n,&a,&b,&k);
	scanf("%s",s);
	b=b*powmod(a,mod-2)%mod;
	per(i,0,k) ret=(ret*b+((s[i]=='+')?1:(mod-1)))%mod;
	b=powmod(b,k)%mod;
	n=(n+1)/k;
	if (b==1) {
		ret=ret*n%mod;
	} else {
		ret=ret*(powmod(b,n)-1)%mod*powmod(b-1,mod-2)%mod;
	}
	ret=ret*powmod(a,n*k-1)%mod;
	if (ret<0) ret+=mod;
	printf("%lld\n",ret);
}