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

const int N=101000;
int n,p[N],cnt[N],ret;
VI s[N];
void dfs(int u,int dep) {
	cnt[dep]^=1;
	for (auto v:s[u]) dfs(v,dep+1);
}
int main() {
	scanf("%d",&n);
	rep(i,2,n+1) {
		scanf("%d",p+i);
		s[p[i]].pb(i);
	}
	dfs(1,0);
	rep(i,0,n) ret+=cnt[i];
	printf("%d\n",ret);
}