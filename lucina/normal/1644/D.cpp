#include <stdio.h>
#include <bits/stdc++.h>
#define st first
#define nd second
#define PQ priority_queue
#define MP make_pair

using ll = long long ;
using namespace std;
using pii = pair<int,int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
const int N = 2e5 + 10;
const int MOD = 998244353;
pii query[N];
bool row[N], col[N];
int fpow(int val, int id) {
	int ret = 1;
	for(; id > 0; id >>= 1) {
		if (id & 1) ret = 1LL * ret * val % MOD;
		val = 1LL * val * val % MOD;
	}
	return ret;
}
void solve() {
	int n, m, k, q;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &query[i].st, &query[i].nd);
	}
	for (int i = 1; i <= max(n, m); i++) {
		row[i] = col[i] = false;
	}
	int rc = 0, cc = 0, id = 0;
	for (int i = q; i > 0; i--) {
		id += (!row[query[i].st] || !col[query[i].nd]);
		rc += !row[query[i].st];
		cc += !col[query[i].nd];
		row[query[i].st] = true;
		col[query[i].nd] = true;
		if (rc == n || cc == m) break;
	}
	printf("%d\n", fpow(k, id));
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}


}