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

int n, a[120], b[120];

void solve() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", a + i);
	rep(i, n) scanf("%d", b + i);
	sort(a, a+n);
	sort(b, b+n);
	rep(i, n) printf("%d ", a[i]); puts("");
	rep(i, n) printf("%d ", b[i]); puts("");
}

int main() {
	int t; scanf("%d", &t);
	rep(tt, t) {
		solve();
	}
	return 0;
}