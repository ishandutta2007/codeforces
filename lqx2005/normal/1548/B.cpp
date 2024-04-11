#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10;
int T, n, ans = 0;
i64 a[N], b[N], g[N];

void divide(int l, int r) {
	if(l > r) return;
	if(l == r) {
		if(b[l] > 1) {
			ans = max(ans, 1);
		}
		return;
	}
	int mid = (l + r) / 2;
	g[mid] = b[mid], g[mid + 1] = b[mid + 1];
	for(int i = mid; i >= l; i--) {
		g[i] = __gcd(g[i + 1], b[i]);
	}
	for(int i = mid + 2; i <= r; i++) {
		g[i] = __gcd(g[i - 1], b[i]);
	}
	int ed = l;
	for(int i = mid + 1; i <= r; i++) {
		while(ed <= mid && __gcd(g[ed], g[i]) <= 1) ed++;
		if(ed <= mid) ans = max(ans, i - ed + 1);
	}
	divide(l, mid), divide(mid + 1, r);
	return;
}

void Main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) b[i] = abs(a[i + 1] - a[i]);
	ans = 0;
	divide(1, n - 1);
	cout << ans + 1 << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--) Main();
    return 0;
}