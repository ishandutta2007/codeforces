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

PII p[2010];
ll dp[2010],f[201000];
int h,w,n;
ll go(ll x,ll y) {
	assert(x>=0&&y>=0);
	return f[x+y]*powmod(f[x]*f[y],mod-2)%mod;
}
int main() {
	scanf("%d%d%d",&h,&w,&n);
	f[0]=1;
	rep(i,1,200001) f[i]=f[i-1]*i%mod;
	rep(i,0,n) scanf("%d%d",&p[i].fi,&p[i].se);
	p[n]=mp(h,w); p[n+1]=mp(1,1); n+=2;
	sort(p,p+n); 
	dp[0]=1;
	rep(i,1,n) {
		dp[i]=go(p[i].fi-1,p[i].se-1);
		rep(j,1,i) if (p[j].fi<=p[i].fi&&p[j].se<=p[i].se)
			dp[i]=(dp[i]-go(p[i].fi-p[j].fi,p[i].se-p[j].se)*dp[j])%mod;
	}
	(dp[n-1]+=mod)%=mod;
	printf("%I64d\n",dp[n-1]);
}