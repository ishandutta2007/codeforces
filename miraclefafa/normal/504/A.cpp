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

const int N=101000;
int n,d[N],s[N],q[N],t;
vector<PII> e;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",d+i,s+i);
	rep(i,0,n) if (d[i]==1) q[t++]=i;
	rep(i,0,t) {
		int u=q[i];
		if (d[u]==0) continue;
		e.pb(mp(u,s[u]));
		d[s[u]]--; s[s[u]]^=u;
		if (d[s[u]]==1) q[t++]=s[u];
	}
	printf("%d\n",SZ(e));
	rep(i,0,SZ(e)) printf("%d %d\n",e[i].fi,e[i].se);
}