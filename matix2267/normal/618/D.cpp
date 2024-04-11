#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

vector<vi> V;

pii dfs(int u, int par) {
	int rx = 0, ile = 0;
	for(int v : V[u]) if(v != par) {
		pii z = dfs(v,u);
		if(z.x < z.y) {
			assert(z.x+1 == z.y);
			rx += z.x+1;
		} else {
			assert(z.x == z.y);
			rx += z.y;
			ile++;
		}
	}
	if(ile<=1) return pii(rx,rx);
	return pii(rx+ile-2,rx+ile-1);
}

ll solve() {
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	V.resize(n);
	fru(i,n-1) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		V[a].pb(b);
		V[b].pb(a);
	}
	if(n==1) return 0;
	if(x > y) {
		int bad = 0;
		fru(i,n) if(V[i].size()==n-1) bad++;
		if(bad) return 1LL*y*(n-2) + x;
		else return 1LL*y*(n-1);
	} else {
		int sklad = dfs(0,-1).x;
		return 1LL*y*sklad + 1LL*x*(n-sklad-1);
	}
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) printf("%lld\n",solve());
	return 0;
}