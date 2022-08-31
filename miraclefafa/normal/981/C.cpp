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
int n,u,v,deg[N];
VI g,lv;

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		deg[u]++; deg[v]++;
	}
	rep(i,1,n+1) if (deg[i]>=3) g.pb(i);
	if (SZ(g)>=2) {
		puts("No");
		return 0;
	}
	puts("Yes");
	if (SZ(g)==1) {
		int rt=g[0];
		int cnt=0;
		rep(i,1,n+1) if (deg[i]==1) cnt++;
		printf("%d\n",cnt);
		rep(i,1,n+1) if (deg[i]==1) printf("%d %d\n",rt,i);
	} else {
		lv.clear();
		rep(i,1,n+1) if (deg[i]==1) lv.pb(i);
		assert(SZ(lv)==2);
		printf("%d\n",1);
		printf("%d %d\n",lv[0],lv[1]);
	}
}