#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using t3 = tuple<int, int, int>;

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		int n, a[120] = {};
		scanf("%d", &n);
		rep(i, n) {
			int x; scanf("%d", &x);
			a[abs(x)]++;
		}
		int ans = 0;
		rep(i, 120) ans += min(i == 0 ? 1 : 2, a[i]);
		printf("%d\n", ans);
	}
	return 0;
}