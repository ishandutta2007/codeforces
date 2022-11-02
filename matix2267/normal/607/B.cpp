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
const int MAXN = 1003;

int dp[MAXN][MAXN];

void solve() {
	int n;
	scanf("%d",&n);
	vi V(n);
	fru(i,n) scanf("%d",&V[i]);
	fru(d,n+1) fru(i,n+1-d) {
		int j = i+d;
		if(d==0) dp[i][j]=0;
		else if(d==1) dp[i][j]=0;
		else {
			dp[i][j] = inft;
			if(V[i] == V[j-1]) dp[i][j] = dp[i+1][j-1];
			for(int k=i+1;k<j;k++) dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k][j]);
		}
//		printf("[%d][%d] = %d\n",i,j,dp[i][j]);
	}
	printf("%d\n",1+dp[0][n]);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}