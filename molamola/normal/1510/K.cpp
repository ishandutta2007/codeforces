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

int n, p[2020], id[2020];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=2*n;i++) scanf("%d", p + i);
	auto op = [&](int x) {
		if(x == 0) {
			for(int i=1;i<2*n;i+=2) swap(p[i], p[i + 1]);
		}
		else {
			for(int i=1;i<=n;i++) swap(p[i], p[i + n]);
		}
	};
	int q[2020];
	for(int i=1;i<=2*n;i++) q[i] = p[i];
	int ans = 1e9;
	if(is_sorted(p+1, p+1+2*n)) ans = 0;
	rep(t, 2020) {
		op(t & 1);
		if(is_sorted(p + 1, p + 1 + 2*n)) {
			ans = min(ans, t + 1);
			break;
		}
	}
	for(int i=1;i<=2*n;i++) p[i] = q[i];
	rep(t, 2020) {
		op(!(t & 1));
		if(is_sorted(p + 1, p + 1 + 2*n)) {
			ans = min(ans, t + 1);
			break;
		}
	}
	if(ans == (int)1e9) puts("-1");
	else printf("%d\n", ans);
	return 0;
}