#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 510;

int A[MAXN];
int B[MAXN][MAXN];

void solve() {
	int n,m,b,MOD;
	scanf("%d%d%d%d",&n,&m,&b,&MOD);
	fru(i,n) scanf("%d",&A[i]);
	B[0][0]=1%MOD;
	fru(i,n) {
		for(int j=A[i];j<=b;j++) fru(k,m)
			B[j][k+1] = (1LL*B[j][k+1] + B[j-A[i]][k]) % MOD;
//		printf("after %d\n",i+1);
//		fru(j,b+1) { fru(k,m+1) printf("%d ", B[j][k]); puts(""); }
	}
	int ans = 0;
	fru(j,b+1) ans = (1LL*ans + B[j][m]) % MOD;
	printf("%d\n", ans);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}