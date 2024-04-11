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
const int MAXN = 30001, MAXM = 300;

int V[MAXN];
int dp[MAXN][2*MAXM];

void solve() {
	int n,d;
	scanf("%d%d",&n,&d);
	fru(i,n) {
		int a;
		scanf("%d",&a);
		V[a]++;
	}
	int base = max(1,d-MAXM);
	int upp = base + 2*MAXM;
	for(int u=MAXN-1; u>=0; u--) {
		for(int l=base; l < upp; l++) {
			int ans = 0;
			for(int l1 = l-1; l1 <= l+1; l1++) {
				if(l1 < base || l1 >= upp) continue;
				if(u+l1 >= MAXN) continue;
				ans = max(ans,dp[u+l1][l1-base]);
			}
			ans += V[u];
			dp[u][l-base] = ans;
//			if(u < 28 && l >= 7 && l <= 13) DEB("dp %d %d = %d\n",u,l,ans);
		}
	}
	printf("%d\n",dp[d][d-base]);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}