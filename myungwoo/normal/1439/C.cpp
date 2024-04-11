#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
typedef long long lld;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

int N, Q;
int A[MAXN];

namespace SEGTREE{
	int ts, st;
	struct NODE{
		lld sum; int max, min, lazy;
	};
	vector<NODE> tree;

	NODE combine(const NODE &l, const NODE &r){
		return {l.sum+r.sum, max(l.max, r.max), min(l.min, r.min), 0};
	}

	void build(){
		for (ts=1;ts<N;ts<<=1);
		ts <<= 1; st = (ts>>1)-1;
		tree.resize(ts);
		for (int i=1;i<=N;i++) tree[st+i] = {A[i], A[i], A[i], 0};
		for (int i=st;i;i--) tree[i] = combine(tree[i<<1], tree[i<<1|1]);
	}

	void apply(int n, int v){
		tree[n] = {((lld)1<<__builtin_clz(n)-__builtin_clz(ts)-1)*v, v, v, v};
	}

	void propagate(int n){
		if (!tree[n].lazy) return;
		apply(n<<1, tree[n].lazy);
		apply(n<<1|1, tree[n].lazy);
		tree[n].lazy = 0;
	}

	void lazy_up(int n){
		for (n>>=1;n;n>>=1) if (!tree[n].lazy) tree[n] = combine(tree[n<<1], tree[n<<1|1]);
	}

	void lazy_down(int n){
		if (!n) return;
		lazy_down(n>>1);
		if (!tree[n].lazy || n > st) return;
		propagate(n);
	}

	void query(int r, int v){
		if (tree[1].min >= v) return;
		int l = 1; r += st;
		while (l <= st){
			propagate(l);
			if (tree[l<<1].min < v) l <<= 1;
			else l = l<<1|1;
		}
		// debug("query from %d to %d / value = %d\n", l-st, r-st, v);
		int l0 = l, r0 = r;
		lazy_down(l0); lazy_down(r0);
		for (;l<=r;l>>=1,r>>=1){
			if (l&1) apply(l++, v);
			if (r&1^1) apply(r--, v);
		}
		lazy_up(l0); lazy_up(r0);
	}

	tuple<int, lld> find(int l, int v){
		if (l > N || tree[1].min > v) return {N+1, 0};
		int n = 1, s = 1, e = ts-st-1; lld sum = 0;
		while (n <= st){
			propagate(n);
			// debug("n = %d / me = %d / l = %d / r = %d\n", n, tree[n].min, tree[n<<1].min, tree[n<<1|1].min);
			int m = s+e>>1;
			if (m >= l && tree[n<<1].min <= v) n <<= 1, e = m;
			else{
				sum += tree[n<<1].sum; n = n<<1|1; s = m+1;
			}
		}
		return {n-st, sum};
	}

	tuple<int, lld> get_range(lld val){
		if (tree[1].sum <= val) return {N+1, 0};
		int n = 1; lld val0 = val;
		while (n <= st){
			propagate(n);
			if (tree[n<<1].sum <= val) val -= tree[n<<1].sum, n = n<<1|1;
			else n <<= 1;
		}
		return {n-st, val0-val};
	}
};

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	SEGTREE::build();
	while (Q--){
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if (t == 1) SEGTREE::query(x, y);
		else{
			int ans = 0;
			while (x <= N){
				auto [t, v] = SEGTREE::find(x, y);
				// debug("find(%d, %d) = (%d, %d)\n", x, y, t, v);
				if (t > N) break;
				v += y;
				auto [nxt, s] = SEGTREE::get_range(v);
				ans += nxt - t;
				y = v-s;
				x = nxt;
			}
			printf("%d\n", ans);
		}
	}
}