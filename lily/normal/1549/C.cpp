#include <bits/stdc++.h>
using namespace std;

int s[int(2e5 + 5)];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		if (!s[u]++) n-- ;
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int x;
		scanf("%d", &x);
		if (x < 3) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (u > v) swap(u, v);
			if (x == 1) {
				if (!s[u]++) n--;
			}
			else if (!--s[u]) n++;
		} else printf("%d\n", n);
	}

}