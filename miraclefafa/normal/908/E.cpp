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

int n,m,rk;
ll g[1010],comb[1010][1010],bel[1010];
char s[1010];
map<ll,int> hs;
int main() {
	scanf("%d%d",&m,&n);
	rep(i,0,n) {
		scanf("%s",s);
		rep(j,0,m) g[j]=g[j]*2+(s[j]-'0');
	}
	rep(j,0,m) hs[g[j]]++;
	ll ret=1; bel[0]=1;
	comb[0][0]=1;
	rep(i,0,m+1) {
		comb[i][0]=1;
		rep(j,1,i+1) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
		rep(j,0,i+1) bel[i+1]=(bel[i+1]+comb[i][j]*bel[j])%mod;
	}
	for (auto p:hs) ret=ret*bel[p.se]%mod;
	printf("%lld\n",ret);
}