#include <bits/stdc++.h>
using namespace std;

const int N = 200005, MX = 1E6 + 5, D = 450;

int n, t, l = 1, r = 0, a[N], occ[MX];
long long current_answer = 0, ans[N];

struct query {
	int l, r, ind;
} que[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= t; i++) {
		cin >> que[i].l >> que[i].r;
		que[i].ind = i;
	}
	sort(que + 1, que + t + 1, [](const query &u, const query &v) {
		if (u.l / D != v.l / D) {
			return u.l / D < v.l / D;
		} else {
			return u.r < v.r;
 		}
	});
	for (int i = 1; i <= t; i++) {
		query &cur = que[i];
		for (; r < cur.r; r++) {
			int v = a[r + 1];
			current_answer -= 1LL * occ[v] * occ[v] * v;
			occ[v]++;
			current_answer += 1LL * occ[v] * occ[v] * v;
		}
		for (; l > cur.l; l--) {
			int v = a[l - 1];
			current_answer -= 1LL * occ[v] * occ[v] * v;
			occ[v]++;
			current_answer += 1LL * occ[v] * occ[v] * v;
		}
		for (; r > cur.r; r--) {
			int v = a[r];
			current_answer -= 1LL * occ[v] * occ[v] * v;
			occ[v]--;
			current_answer += 1LL * occ[v] * occ[v] * v;
		}
		for (; l < cur.l; l++) {
			int v = a[l];
			current_answer -= 1LL * occ[v] * occ[v] * v;
			occ[v]--;
			current_answer += 1LL * occ[v] * occ[v] * v;
		}
		ans[cur.ind] = current_answer;
	}
	for (int i = 1; i <= t; i++) {
		cout << ans[i] << '\n';
	}
}