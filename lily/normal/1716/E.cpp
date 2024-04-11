#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2.63e5 + 5;
const LL INF = 1e18;

struct segment {
	LL ans, left, right, sum;
	segment() {ans = left = right = sum = -INF;}
	segment(LL x) {ans = left = right = max(0ll, x); sum = x;}
	segment(LL a, LL b, LL c, LL d) : ans(a), left(b), right(c), sum(d) {}
	segment operator + (const segment &o) const {
		segment ret;
		ret.ans = max(ans, o.ans);
		ret.ans = max(ret.ans, right + o.left);
		ret.left = max(left, sum + o.left);
		ret.right = max(o.right, right + o.sum);
		ret.sum = sum + o.sum;
		return ret;
	}
};
int n, K;
segment a[20][N];
int main() {
	read(K);
	n = 1 << K;
	for (int i = 0; i < n; i++) {
		int x; read(x);
		a[0][i] = segment(x);
	}
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < n; i++) {
			a[k + 1][i] = a[k][i] + a[k][i ^ (1 << k)];
		}
	}
	int Q, w = 0; read(Q);
	while (Q--) {
		int k; read(k);
		w ^= 1 << k;
		printf("%lld\n", a[K][w].ans);
	}
}