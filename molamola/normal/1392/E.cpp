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

ll X[50][50];

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++, puts("")) for(int j=1;j<=n;j++) {
		X[i][j] = (j % 2 == 1 ? (1ll << (i + j - 2)) : 0);
		printf("%lld ", X[i][j]);
	}
	fflush(stdout);
	int q; scanf("%d", &q);
	rep(qq, q) {
		ll K; scanf("%lld", &K);
		int px = 1, py = 1;
		printf("%d %d\n", px, py);
		for(int a=1;a<2*n-1;a++) {
			int t = (K >> a) & 1;
			if(t) {
				if(px+1 <= n && X[px+1][py]) ++px;
				else ++py;
			}
			else {
				if(px+1 <= n && X[px+1][py] == 0) ++px;
				else ++py;
			}
			printf("%d %d\n", px, py);
		}
		fflush(stdout);
	}
	return 0;
}