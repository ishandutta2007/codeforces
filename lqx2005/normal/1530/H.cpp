#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
const int N = 1.5e4 + 10;
int n, a[N], b[N];
int dp1[2][N], dp2[2][N];

struct BIT {
	int t[N];
	void clear() {
		for(int i = 1; i <= n; i++) t[i] = 0;
		return;
	}
	
	void insert(int x, int v) {
		if(x <= 0) return;
		for(int i = x; i <= n; i += i & (-i)) {
			t[i] = max(t[i], v);
		}
		return;
	}
		
	int query(int x) {
		int res = 0;
		for(int i = x; i > 0; i -= i & (-i)) {
			res = max(res, t[i]);
		}
		return res;
	}
	
}t;

void rever(int arr[]) {
	for(int i = 1; i <= n; i++) {
		arr[i] = n + 1 - arr[i];
	}
	return;
}

void solve(int B, int a[], int dp[], int dp1[], int dp2[]) {
	for(int i = 1; i <= n; i++) dp[i] = 0;
	t.clear();
	for(int i = 1; i <= n; i++) {
		dp[i] = t.query(a[i] - 1);
		t.insert(a[i], dp1[i]);
	}
	t.clear();
	for(int i = 1; i <= n; i++) {
		if(i - B >= 1) {
			t.insert(dp2[i - B], a[i - B]);
		}
		dp[i] = max(dp[i], t.query(a[i] - 1));
	}
	return;
}

int calc(int d) {
	int cnt;
	for(cnt = 1; ; cnt++) {
		int o = cnt % 2, p = (cnt + 1) % 2;
		solve(cnt + d, a, dp1[p], dp1[o], dp2[o]);
		rever(dp1[o]), rever(dp2[o]);
		solve(cnt + d, b, dp2[p], dp2[o], dp1[o]);
		rever(dp1[o]), rever(dp2[o]), rever(dp2[p]);
//		for(int i = 1; i <= n; i++) {
//			cout << dp1[cnt + 1][i] <<" ";
//		}
//		cout << endl;
//		for(int i = 1; i <= n; i++) {
//			cout << dp2[cnt + 1][i] <<" ";
//		}
//		cout << endl;
		int flag = 0;
		for(int i = 1; i <= n; i++) {
			if(dp1[p][i] > 0 || dp2[p][i] <= n) {
				flag = 1;
				break;
			}
		}
		if(!flag) break;
	}
	return cnt;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	reverse(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		b[i] = n + 1 - a[i];
		dp1[1][i] = dp2[1][i] = a[i];
	}
	dp1[1][1] = 0, dp2[1][1] = n + 1;
	ans = max(ans, calc(1));
	for(int i = 1; i <= n; i++) {
		dp1[1][i] = 0, dp2[1][i] = n + 1;
	}
	dp1[1][1] = dp2[1][1] = a[1];
	ans = max(ans, calc(0));
	cout << ans << endl;
	return;
}

int main() {
	int T;
	for(cin >> T;T-- ; ) {
		solve();
	}
    return 0;
}