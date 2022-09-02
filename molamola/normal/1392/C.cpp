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
ll A[200020];
void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld", A + i);
	ll mx = A[1], ans = 0;
	A[n+1] = 1e11;
	for(int i=2;i<=n+1;i++) {
		if(A[i-1] < A[i]) {
			ans += min(A[i], mx) - A[i-1];
		}
		if(mx < A[i]) mx = A[i];
	}
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}