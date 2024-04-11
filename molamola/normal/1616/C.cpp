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

int n, a[100];

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", a + i);
	if(n == 1) {
		puts("0");
		return;
	}
	int ans = n - 2;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			int cnt = 0;
			for(int k=1;k<=n;k++) {
				if((a[k] - a[i]) * (j - i) != (a[j] - a[i]) * (k - i)) ++cnt;
			}
			ans = min(ans, cnt);
		}
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}