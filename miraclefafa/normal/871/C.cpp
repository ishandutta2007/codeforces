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

int n,sn,se;
ll x,y,ret=1;
set<int> hs;
map<int,VI> e;
void dfs(int u) {
	hs.erase(u);
	VI ee=e[u];
	sn++;
	for (auto v:ee) {
		se++;
		if (hs.count(v)) dfs(v);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%lld%lld",&x,&y);
		x*=2; y=y*2+1;
		hs.insert(x);
		hs.insert(y);
		e[x].pb(y); e[y].pb(x);
	}
	while (!hs.empty()) {
		int u=*hs.begin();
		sn=0; se=0;
		dfs(u);
		se/=2;
		if (se==sn-1) {
			ret=ret*(powmod(2,sn)-1)%mod;
		} else {
			ret=ret*powmod(2,sn)%mod;
		}
	}
	printf("%lld\n",ret);
}