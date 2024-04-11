#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int N = 200005;

using myset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
int a[N], b[N];
int fa[N], fb[N];
myset f[N];

void add(int x,int y) {
	for (; x <= n; x += x & -x) {
		f[x].insert(y);
	}
}

void del(int x,int y) {
	for (; x <= n; x += x & -x) {
		f[x].erase(y);
	}
}

int get(int x,int ly, int ry) {
	int ans = 0;
	for (; x > 0; x -= x & -x) {
		ans += f[x].order_of_key(ry + 1) - f[x].order_of_key(ly);
	}
	return ans;
}

int main() {
	int q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		fa[a[i]] = i;
	} 
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
		fb[b[i]] = i; 
	}
	for (int i = 1; i <= n; ++i) {
		add(fa[i], fb[i]);
	}
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int la, ra, lb, rb;
			scanf("%d %d %d %d", &la, &ra, &lb, &rb);
			printf("%d\n", get(ra, lb, rb) - get(la - 1, lb, rb));
		} else {
			int x, y;
			scanf("%d %d", &x, &y);
			del(fa[b[x]], fb[b[x]]);
			del(fa[b[y]], fb[b[y]]);
			swap(b[x], b[y]);
			swap(fb[b[x]], fb[b[y]]);
			add(fa[b[x]], fb[b[x]]);
			add(fa[b[y]], fb[b[y]]);
		}
	}
}