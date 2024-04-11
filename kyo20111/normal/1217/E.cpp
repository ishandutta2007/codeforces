#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <cmath>
#include <tuple>
using namespace std;
#define fio ios::sync_with_stdio(0),cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define md ((s + e) >> 1)
int N, M, K, T;
ll a, b, c;
int inp[300005];
char conv[300005][10];
pii tree[9][800005];
 
pii merge(pii a,pii b){
	pii c = a;
	if(b.first < c.first) c.second = c.first, c.first = b.first;
	else if(b.first < c.second) c.second = b.first;
	if(b.second < c.second) c.second = b.second;
	return c;
}
 
void build(int k, int n, int s, int e) {
	if (s != e) {
		build(k, n * 2, s, md);
		build(k, n * 2 + 1, md + 1, e);
		tree[k][n] = merge(tree[k][n * 2], tree[k][n * 2 + 1]);
	}
	else tree[k][n] = {conv[s][k] ? inp[s] : 1e9, 1e9};
}
 
 
void update(int k, int i, int v, int n = 1, int s = 1, int e = N) {
	if (e < i || i < s) return;
	if (s != e) {
		update(k, i, v, n * 2, s, md);
		update(k, i, v, n * 2 + 1, md + 1, e);
		tree[k][n] = merge(tree[k][n * 2], tree[k][n * 2 + 1]);
	}
	else {
		tree[k][n] = {v, 1e9};
	}
}
 
pii find(int k, int l, int r, int n = 1, int s = 1, int e = N) {
	if (e < l || r < s || r < l) return {1e9, 1e9};
	if (l <= s && e <= r) return tree[k][n];
	return merge(find(k, l, r, n * 2, s, md), find(k, l, r, n * 2 + 1, md + 1, e));
}
 
int main() {
	fio;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		inp[i] = x;
		for (int k = 0; k < 9; k++) {
			conv[i][k] = x % 10;
			x /= 10;
		}
	}
	for (int k = 0; k < 9; k++) {
		build(k, 1, 1, N);
	}
	while (M--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			int ob = b;
			for (ll k = 0; k < 9; k++, b /= 10) {
				int x = b % 10;
				update(k, a, x ? ob : 1e9);
			}
		}
		else {
			int ret = 2e9;
			for (int i = 0; i < 9; i++) {
				pii tmp = find(i, a, b);
				if (tmp.first == 1e9 || tmp.second == 1e9) continue;
				ret = min(ret, tmp.first + tmp.second);
			}
			printf("%d\n", ret != 2e9 ? ret : -1);
		}
	}
}