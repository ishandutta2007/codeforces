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
int n,a[N],p,w,sta[N],fg[N];
vector<PII> s[N];
ll dis[N];
void dfs(int u,ll d,int f) {
	sta[f]=u; dis[f]=d;
	int l=lower_bound(dis,dis+f+1,d-a[u])-dis-1;
	fg[sta[l]]--; fg[u]++;
	for (auto v:s[u]) {
		dfs(v.fi,d+v.se,f+1);
		fg[u]+=fg[v.fi];
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,2,n+1) {
		scanf("%d%d",&p,&w);
		s[p].pb(mp(i,w));
	}
	dis[0]=-1ll<<60;
	dfs(1,0,1);
	rep(i,1,n+1) printf("%d ",fg[i]-1);
	puts("");
}