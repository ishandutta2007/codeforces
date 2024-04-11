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

ll fac[1010000],ans=1;
int c[1010],n;
ll binom(ll x,ll y) {
	return fac[x]*powmod(fac[y]*fac[x-y],mod-2)%mod;
}
int main() {
	fac[0]=1;
	rep(i,1,1000001) fac[i]=fac[i-1]*i%mod;
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",c+i);
	}
	int sm=c[0];
	rep(i,1,n) {
		ans=ans*binom(sm+c[i]-1,sm)%mod;
		sm+=c[i];
	}
	printf("%I64d\n",ans);
}