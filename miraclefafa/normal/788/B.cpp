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

const int N=1010000;
int n,m,u,v,f[N],vis[N];
ll sf,deg[N],ans;
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int main() {
	scanf("%d%d",&n,&m);
	if (m<2) {
		puts("0");
		return 0;
	}
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		f[find(u)]=find(v);
		vis[u]=1; vis[v]=1;
		if (u==v) sf++;
		else deg[u]++,deg[v]++;
	}
	int r=0;
	rep(i,1,n+1) if (vis[i]) r=i;
	rep(i,1,n+1) if (find(i)!=find(r)&&vis[i]) {
		puts("0");
		return 0;
	}
	ans=sf*(sf-1)/2+sf*(m-sf);
	rep(i,1,n+1) ans+=deg[i]*(deg[i]-1)/2;
	printf("%lld\n",ans);
}