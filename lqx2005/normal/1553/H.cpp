#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define full(m) ((1 << (m)) - 1)
using namespace std;
typedef long long i64;
const int K = 19, N = 1 << K, oo = 0x3f3f3f3f;
int cnt[N], a[N], ans[K][N];
vector<int> c[N], d[N];
int k, n;

void chkmin(int &x, int y) {
	if(x > y) x = y;
}

void solve(vector<int> p, int s, int t) {
	if(sz(p) < 2) return;
	if(s < t) {
		for(int i = 0; i < 1 << t; i++) {
			chkmin(ans[s][i], abs((p[0] ^ i) - (p[1] ^ i)));
		}
		return;
	}
	for(int i = 0; i < 1 << (s + 1); i++) {
		d[i].clear();
	}
	for(int i = 0; i < 1 << t; i++) {
		for(int &v : p) {
			int aim = i ^ (1 << s);
			d[aim ^ v].push_back(aim);
			aim = i ^ (full(s - t) << t);
			d[aim ^ v].push_back(aim);
		}
	}
	for(int i = 0; i < 1 << (s + 1); i++) {
		sort(d[i].begin(), d[i].end());
		int mn = oo;
		for(int j = 1; j < sz(d[i]); j++) {
			chkmin(mn, d[i][j] - d[i][j - 1]);
		}
		chkmin(ans[s][i], mn);
	}
	return;
}

int main() {
	memset(ans, 0x3f, sizeof(ans));
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t = 0;
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < 1 << k; j++) {
			cnt[j] = 0;
		}
		for(int j = 0; j < n; j++) {
			cnt[a[j] >> i]++;
		}
		int mx = 0;
		for(int j = 0; j < 1 << k; j++) {
			mx = max(mx, cnt[j]);
		}
		if(mx >= 2) {
			t = i;
			break;
		}
	}
	for(int i = t - 1; i < k; i++) {
		for(int j = 0; j < 1 << (k - i - 1); j++) c[j].clear();
		for(int j = 0; j < n; j++) {
			c[a[j] >> (i + 1)].push_back(a[j] & full(i + 1));
		}
		for(int j = 0; j < 1 << (k - i - 1); j++) {
			solve(c[j], i, t);
		}
	}
	for(int i = 0; i < 1 << k; i++) {
		int res = oo;
		for(int j = t - 1; j < k; j++) {
			chkmin(res, ans[j][i & full(j + 1)]);
		}
		cout << res << " ";
	}
	cout << endl;
	return 0;
}