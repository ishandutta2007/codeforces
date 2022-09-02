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

int n;
ll k, A[200020];
void solve() {
	scanf("%d%lld", &n, &k);
	for(int i=1;i<=n;i++) scanf("%lld", A + i);
	auto f = [&]() {
		ll d = *max_element(A+1, A+1+n);
		for(int i=1;i<=n;i++) A[i] = d - A[i];
	};
	if(k >= 5) k -= (k - 5) / 2 * 2;
	rep(d, k) f();
	for(int i=1;i<=n;i++) printf("%lld ", A[i]); puts("");
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}