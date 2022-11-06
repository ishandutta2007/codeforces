#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef unsigned long long ull;
const ll mn=504;
const ll logm=62;
const ll mk=64;
const ll my=(mn/mk)+4;
ull a[2][mn][my];
ull b[2][mn][my];
long long c[2][mn];
long long d[2][mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%d%d",&n,&m);
	memset(a,0,sizeof a);
	memset(c,0,sizeof c);
	long long ans=0;
	for (ll i=0;i<m;i++) {
		ll v,u,t;
		scanf("%d%d%d",&v,&u,&t);
		a[t][v][u/mk]|=1ULL<<(u%mk);
		chkmax(c[t][v],1LL);
	}
	chkmax(ans,c[0][1]);
	for (ll k=0;k<logm;k++) {
		memset(b,0,sizeof b);
		memcpy(d,c,sizeof d);
		//memset(d,0,sizeof d);
		for (ll flip=0;flip<2;flip++) {
			for (ll x=1;x<=n;x++) for (ll z=1;z<=n;z++) {
				if (a[flip][x][z/64]&(1ULL<<(z%64))) {
					for (ll y=0;y<my;y++) {
						b[flip][x][y]|=a[flip^1][z][y];
					}
					chkmax(d[flip][x], (1LL<<k)+c[flip^1][z]);
				}
			}
		}
		for (ll y=1;y<=n;y++) {
			chkmax(ans,d[0][1]);
		}
		swap(a,b);
		swap(c,d);
	}
	long long lim=1000000000000000000LL;
	if (ans>lim) ans=-1;
	printf("%lld\n",ans);
}