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
const int MAXN = 160;

vector<pii> dp[MAXN][MAXN];

void solve() {
	int n,k,s;
	scanf("%d%d%d",&n,&k,&s);
	vi Q(n);
	fru(i,n) scanf("%d",&Q[i]);
	dp[0][0].pb(pii(0,0));
	fru(i,n) fru(j,i+1) {
		sort(ALL(dp[i][j]));
		int prev = -1;
		for(pii p : dp[i][j]) {
			if(p.x == prev) continue;
			prev = p.x;
			dp[i+1][j+1].pb(pii(p.x+i-j,p.y+Q[i]));
			dp[i+1][j].pb(pii(p.x,p.y));
		}
		{ vector<pii> tmp; swap(dp[i][j],tmp); }
	}
	int best = inft;
	for(pii p : dp[n][k]) if(p.x <= s) best = min(best, p.y);
	printf("%d\n",best);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}