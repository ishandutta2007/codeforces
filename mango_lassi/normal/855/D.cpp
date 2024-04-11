#include <iostream>

const long long N = 1e5;
const long long C = 20;
long long depth [N];
long long parent [N][C+1];
long long special [N];
long long part [N];

long long up(long long i, long long x, long long k) {
	if (k == -1) return i;
	if (x & (1<<k)) {
		return up(parent[i][k], x, k-1);
	}
	return up(i, x, k-1);
}

int main() {
	std::ios_base::sync_with_stdio(false);

	long long n;
	std::cin >> n;
	
	for (long long i = 0; i < n; ++i) {
		long long p, t;
		std::cin >> p >> t;
		if (p == -1) p = i+1;
		--p;
		parent[i][0] = p;
		if (p == i) {
			special[i] = 0;
			part[i] = 0;
			depth[i] = -1;
		} else if (t == 0) {
			special[i] = special[p] + 1;
			part[i] = 0;
		} else {
			special[i] = 0;
			part[i] = part[p] + 1;
		}
		depth[i] = depth[p] + 1;
	}
	for (long long k = 1; k <= C; ++k) {
		for (long long i = 0; i < n; ++i) {
			parent[i][k] = parent[parent[i][k-1]][k-1];
		}
	}
	long long q;
	std::cin >> q;
	for (long long s = 0; s < q; ++s) {
		long long t, u, v;
		std::cin >> t >> u >> v;
		--u; --v;
		if (t == 1) {
			if (v != u) {
				// v special of u
				// Is v u's special tree ancestor
				if (special[v] >= depth[v] - depth[u]) {
					v = up(v, depth[v] - depth[u], C);
					if (v == u) {
						std::cout << "YES\n";
						continue;
					}
				}
			}
			std::cout << "NO\n";
		} else {
			// v part of u
			if (v != u) {
				// Is LCA(u,v) part of u's special chain and v's part chain
				long long meet = std::max(depth[v] - part[v], depth[u] - special[u]);
				if ((meet < depth[v]) && (meet <= depth[u])) {
					v = up(v, depth[v]-meet, C);
					u = up(u, depth[u]-meet, C);
					if (u == v) {
						std::cout << "YES\n";
						continue;
					}
				}
			}
			std::cout << "NO\n";
		}
	}
}