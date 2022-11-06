#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll mn=2e5+4;
vector<ll> g[mn];
ll numv[mn][5];
ll sumv[mn][5];
ll k;
ll final=0;
void dfs(ll x, ll p) {
	numv[x][0]=1;
	for (auto &y:g[x]) {
		if (y==p) continue;
		dfs(y,x);
		for (ll i=0;i<k;i++) {
			for (ll j=0;j<k;j++) {
				ll perv=(i+j+1+k-1)/k;
				ll toadd1=perv*numv[x][i]*numv[y][j];
				ll toadd2=numv[x][i]*sumv[y][j]+sumv[x][i]*numv[y][j];
				final+=toadd1+toadd2;
				//if(toadd1+toadd2) {
				//	printf("x:%lld y:%lld i:%lld j:%lld toadd1:%lld toadd2:%lld\n",x,y,i,j,toadd1,toadd2);
				//}
			}
		}
		for (ll j=0;j<k;j++) {
			ll i=(j+1)%k;
			ll more=(j+1)/k;
			numv[x][i]+=numv[y][j];
			sumv[x][i]+=sumv[y][j]+more*numv[y][j];
		}
	}
	//printf("x:%lld p:%lld\n",x,p);
	//for (ll i=0;i<k;i++) {
	//	printf("i:%lld numv:%lld sumv:%lld\n",i,numv[x][i],sumv[x][i]);
	//}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(numv,0,sizeof numv);
	memset(sumv,0,sizeof sumv);
	ll n; scanf("%lld %lld",&n,&k);
	for (ll i=0;i<n-1;i++) {
		ll x,y;scanf("%lld%lld",&x,&y);
		g[x].PB(y); g[y].PB(x);
	}
	dfs(1,-1);
	printf("%lld\n",final);
}