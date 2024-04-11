#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 5055
const int MOD = 1000000007;

int n, m;
int s[N];
struct Node {
	int f, h;
	bool operator < (const Node &a) const {
		return f < a.f || (f == a.f && (h < a.h));
	}
} a[N];

vector <int> A[N], B[N];
int cnt[N][N], cnt2[N][N], lp[N], rp[N];

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(s[i]);
		A[s[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		a[i] = (Node) {u, v};
	}

	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; ) {
		int j = i;
		while (j <= m && a[j].f == a[i].f) j++;
		while (i < j) {
			B[a[i].f].push_back(a[i].h);
			i++;
		}
	}
	for (int i = 1; i <= n; i++) if (B[i].size()) {
		int cc = (int)A[i].size();
		sort(B[i].begin(), B[i].end());
		while (B[i].size() && B[i].back() > cc) B[i].pop_back();
		for (int u = 0; u < (int)B[i].size(); u++){
			for (int v = 0; v < (int)B[i].size(); v++) {
				int L = A[i][B[i][u] - 1], R = A[i][cc - B[i][v]]; 
				if (L < R) {
					cnt[i][L]++, cnt[i][R]--;
					cnt2[i][L + 1]++, cnt2[i][R]--;;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[i][j] += cnt[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt2[i][j] += cnt2[i][j - 1];
		}
	}
	int ans = 0; long long cc = 1;
	for (int i = 1; i <= n; i++) lp[i] = 0, rp[i] = B[i].size() - 1;
	for (int split = 0; split <= n; split++) {
		int tot = 0;
		long long ct = 1;
		for (int i = 1; i <= n; i++) if (B[i].size()){
			while (lp[i] < B[i].size() && A[i][B[i][lp[i]] - 1] <= split) lp[i]++;
			while (rp[i] >= 0 && A[i][A[i].size() - B[i][rp[i]]] <= split) rp[i]--;
			int lans = lp[i], rans = rp[i] + 1;
		//	cerr << lans << " " << rans << " -- " << rp[i] << endl;
			if (cnt[i][split] - min(lans, rans)) {
				tot += 2;
			//	cerr << i << " " << split << " " << cnt[i][split] << " " << lans << " " << rans << endl;
				(ct *= cnt[i][split] - min(lans, rans)) %= MOD;
			}
			else if (lans + rans) {
				tot += 1;
				(ct *= lans + rans) %= MOD;
			}
		}
		if (tot > ans) ans = tot, cc = ct;
		else if (tot == ans) {
			(cc += ct) %= MOD;
		}
	}
//	cerr << " :: " << ans << " " << cc << endl;
	for (int i = 1; i <= n; i++) lp[i] = 0, rp[i] = B[i].size() - 1;
	for (int split = 1; split <= n; split++) {
		int tot = 0;
		long long ct = 1;
		for (int i = 1; i <= n; i++) if (B[i].size()){
			while (lp[i] < B[i].size() && A[i][B[i][lp[i]] - 1] <= split - 1) lp[i]++;
				while (rp[i] >= 0 && A[i][A[i].size() - B[i][rp[i]]] <= split) rp[i]--;
			int lans = lp[i], rans = rp[i] + 1;
			if (cnt2[i][split] - min(lans, rans)) {
				tot += 2;
				(ct *= cnt2[i][split] - min(lans, rans)) %= MOD;
			}
			else if (lans + rans) {
				tot += 1;
				(ct *= lans + rans) %= MOD;
			}
		}
		if (tot == ans) {
			(cc -= ct) %= MOD;
		}
	}
	cc = (cc + MOD) % MOD;
	cout << ans << " " << (ans == 0 ? 1ll : cc) << endl;
}