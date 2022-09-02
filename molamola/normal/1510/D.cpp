#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

using FL = long double;
const FL INF = 1e18;
int N, D;
int A[100010];
FL dp[100010][10];
int prv[100010][10];

int main() {
	scanf("%d%d", &N, &D);
	for(int i=1;i<=N;i++) scanf("%d", A + i);
	rep(i, 10) dp[0][i] = -INF;
	dp[0][1] = 0;
	for(int i=1;i<=N;i++) {
		FL x = log(A[i]);
		rep(a, 10) dp[i][a] = dp[i-1][a], prv[i][a] = -1;
		rep(a, 10) {
			int b = a * A[i] % 10;
			if(dp[i][b] < dp[i-1][a] + x) {
				dp[i][b] = dp[i-1][a] + x;
				prv[i][b] = a;
			}
		}
	}
	if(dp[N][D] < 0) {
		puts("-1");
	}
	else if(dp[N][D] == 0) {
		int ok = 0;
		for(int i=1;i<=N;i++) if(A[i] == 1) {
			ok = 1;
			break;
		}
		if(ok) {
			puts("1\n1");
		}
		else puts("-1");
	}
	else {
		vector <int> w;
		for(int i=N, j=D;i;i--) {
			if(prv[i][j] != -1) {
				j = prv[i][j];
				w.pb(A[i]);
			}
		}
		sort(all(w));
		printf("%d\n", szz(w));
		for(int e : w) printf("%d ", e); puts("");
	}
	return 0;
}