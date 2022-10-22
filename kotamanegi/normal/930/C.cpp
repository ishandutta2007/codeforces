#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
long long imossing[200000] = {};
long long griding[200000] = {};
long long seg_tree[seg_size*2];
long long seg_find(int now, int n_l, int n_r, int w_l, int w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (n_l >= w_r || w_l >= n_r) return 0;
	return max(seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r), seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r));
}
long long set_seg(int now) {
	seg_tree[now] = max(seg_tree[now * 2], seg_tree[now * 2 + 1]);
	if (now != 1) set_seg(now / 2);
	return 0;
}
long long ans[2][200000];
int main(){
#define int long long
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		imossing[a]++;
		imossing[b + 1]--;
	}
	for (int i = 1; i <= m; ++i) {
		griding[i] = griding[i - 1] + imossing[i];
	}
	for (int neko = 0; neko < 2; ++neko) {
		for (int q = 0; q < 2 * seg_size; ++q) {
			seg_tree[q] = 0;
		}
		for (int q = 1; q <= m; ++q) {
			int hoge = seg_find(1, 0, seg_size, 0, griding[q]+1);
			seg_tree[(seg_size + griding[q])] = hoge + 1;
			set_seg((seg_size + griding[q]) / 2);
			ans[neko][q] = max(hoge + 1,ans[neko][q-1]);
		}
		int hoa[120000];
		for (int q = 1; q <= m; ++q) {
			hoa[q] = griding[m + 1 - q];
		}
		for (int q = 1; q <= m; ++q) {
			griding[q] = hoa[q];
		}
	}
	int final_ans = 0;
	for (int i = 0; i <= m; ++i) {
		final_ans = max(final_ans, ans[0][i] + ans[1][m - i]);
	}
	cout << final_ans << endl;
	return 0;
}