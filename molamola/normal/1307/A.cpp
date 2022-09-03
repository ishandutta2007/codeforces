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

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		int n, d, a[110];
		scanf("%d%d", &n, &d);
		for(int i=1;i<=n;i++) scanf("%d", a + i);
		int ans = a[1];
		for(int i=2;i<=n;i++) {
			int t = min(a[i], d / (i - 1));
			d -= t * (i-1);
			ans += t;
		}
		printf("%d\n", ans);
	}
	return 0;
}