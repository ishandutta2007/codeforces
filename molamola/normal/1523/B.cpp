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

void solve() {
	int n, a[1010];
	scanf("%d", &n);
	rep(i, n) scanf("%d", a + i + 1);
	printf("%d\n", 3 * n);
	for(int i=1;i<=n;i+=2) {
		int j = i + 1;
		printf("%d %d %d\n", 1, i, j);
		printf("%d %d %d\n", 2, i, j);
		printf("%d %d %d\n", 1, i, j);
		printf("%d %d %d\n", 1, i, j);
		printf("%d %d %d\n", 2, i, j);
		printf("%d %d %d\n", 1, i, j);
	}
}

int main() {
	int T; scanf("%d", &T);
	rep(tt, T) {
		solve();
	}
	return 0;
}