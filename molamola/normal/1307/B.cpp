#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n;
ll x, a[100010];

void solve() {
	scanf("%d%lld", &n, &x);
	for(int i=1;i<=n;i++) scanf("%lld", a + i);
	sort(a+1, a+1+n);
	int t = (int)(lower_bound(a+1, a+1+n, x) - a);
	if(t <= n && a[t] == x) {
		puts("1");
		return;
	}
	if(t <= n) {
		puts("2");
		return;
	}
	printf("%lld\n", (x + a[n] - 1) / a[n]);
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}