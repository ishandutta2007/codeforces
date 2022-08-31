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

const int N=201000;
int n,f[N],sz[N],u,v,cyc[N];
ll ret=1;

int find(int u) { return f[u]==u?u:f[u]=find(f[u]); }
int main() {
	scanf("%d",&n);
	rep(i,1,2*n+1) f[i]=i,sz[i]=1;
	rep(i,0,n) {
		scanf("%d%d",&u,&v);
		if (u==v) {
			u=find(u);
			cyc[u]=2;
			continue;
		}
		u=find(u); v=find(v);
		if (find(u)!=find(v)) {
			f[u]=v;
			sz[v]+=sz[u];
			cyc[v]|=cyc[u];
		} else {
			cyc[u]=1;
		}
	}
	rep(i,1,2*n+1) if (find(i)==i) {
//		printf("%d %d %d\n",i,sz[i],cyc[i]);
		if (cyc[i]==1) ret=ret*2%mod;
		else if (cyc[i]==0) ret=ret*sz[i]%mod;
	}
	printf("%lld\n",ret);
}