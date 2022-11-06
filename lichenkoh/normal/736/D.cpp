#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
typedef unsigned long long ull;
const ll mn=2000;
const ll ymax=(mn+63)/64;
ll firstone[mn]; // First 1 bit in this row
ull g[mn][ymax]; // Matrix. Row number is first coordinate.
ull id[mn][ymax]; // Linear combination in terms of original rows
void gauss(ll n, ll m) {
	for (ll x=0;x<n;x++) firstone[x]=-1;
	ll nlim=(n+63)/64;
	ll ylim=(m+63)/64;
	ll initx=0;
	for (ll b=0;b<m;b++) {
		ull bm=1ULL<<(b%64);
		ll toswap=-1;
		for (ll x=initx;x<n;x++) {
			// Find vector to act as pivot
			if (g[x][b/64]&bm) {
				toswap=x;
				break;
			}
		}
		if (toswap==-1) {
			// Linear combination of rows does not span full 2^m-space.
			continue;
		}
		// Put pivot at initx position
		for (ll y=0;y<ylim;y++) {
			swap(g[toswap][y],g[initx][y]);
		}
		for (ll y=0;y<nlim;y++) {
			swap(id[toswap][y],id[initx][y]);
		}
		// Eliminate the b-th column of 1s for all rows after initx
		for (ll x=initx+1;x<n;x++) {
			if (g[x][b/64]&bm) {
				for (ll y=0;y<ylim;y++) {
					g[x][y]^=g[initx][y];
				}
				for (ll y=0;y<nlim;y++) {
					id[x][y]^=id[initx][y];
				}
			}
		}
		// initx is the row which has the b-th column as its first 1 bit.
		firstone[initx]=b;
		initx++;
	}
}
ull sol[ymax];
ull want[ymax];
bool solve(ll n, ll m) {
/*
Takes in wanted column vector as want as 64-bit compressed m-string.
Outputs sol as 64-bit compressed n-string.
Returns true if can find solution.
*/
	memset(sol,0,sizeof sol);
	ll nlim=(n+63)/64;
	ll ylim=(m+63)/64;
	ll initx=0;
	for (ll b=0;b<m;b++) {
		if (0ULL==(want[b/64]&(1ULL<<(b%64)))) continue;
		ll found=-1;
		for (ll x=initx;x<n;x++) {
			if (firstone[x]==b) {
				found=x; break;
			}
		}
		if (found==-1) {
			return false;
		}
		for (ll y=0;y<ylim;y++) {
			want[y]^=g[found][y];
		}
		for (ll y=0;y<nlim;y++) {
			sol[y]^=id[found][y];
		}
		initx=found+1;
	}
	return true;
}
bool vans[500000];
vector<pll> query[mn];
ull og[mn][ymax];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; ll q; scanf("%d%d",&n,&q);
	m=n;
	memset(g,0,sizeof g);
	memset(og,0,sizeof og);
	for (ll i=0;i<q;i++) {
		ll a,b; scanf("%d%d",&a,&b);
		--a; --b;
		g[a][b/64]|=(1ULL<<(b%64));
		og[a][b/64]|=(1ULL<<(b%64));
		query[b].PB(MP(a,i));
	}
	memset(id,0,sizeof id);
	for (ll x=0;x<n;x++) {
		id[x][x/64]|=(1ULL<<(x%64));
	}
	gauss(n,m);
	for (ll k=0;k<n;k++) {
		memset(want,0,sizeof want);
		want[k/64]|=(1ULL<<(k%64));
		bool got=solve(n,m);
		assert(got);
		for (auto &w:query[k]) {
			ll a=w.first, idx=w.second;
			if (sol[a/64]&(1ULL<<(a%64))) vans[idx]=false;
			else vans[idx]=true;
		}
	}
	for (ll i=0;i<q;i++) {
		if (vans[i]) printf("YES\n");
		else printf("NO\n");
	}
}