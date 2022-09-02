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

int n, m, a[200020];

void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d", a + i);
	sort(a+1, a+1+n);
	if(n > m) {
		puts("0");
		return;
	}
	int ans = 1 % m;
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) {
		ans = (ll)ans * abs(a[i] - a[j]) % m;
	}
	printf("%d\n", ans);
}

int main() {
	int t = 1; //scanf("%d", &t);
	rep(tt, t) {
		solve();
	}
	return 0;
}