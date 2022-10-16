#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 200005;

int n;

LL m;

struct E{
	int w, id;
	bool operator < (const E &b) const {
		return w < b.w;
	}
} e[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &e[i].w), e[i].id = i;
		LL v = (m + 1) / 2;
		sort(e + 1, e + 1 + n);
		bool ok = false;
		int p = -1;
		for (int i = 1; i <= n; i++) {
			if (e[i].w >= v && e[i].w <= m) {
				ok = true;
				p = e[i].id;
				break;
			}
		}
		if (ok) printf("%d\n%d\n", 1, p);
		else {
			LL sum = 0;
			p = -1;
			for (int i = 1; i <= n; i++) {
				if (e[i].w < v) {
					sum += e[i].w;
					if (sum >= v) {
						p = i;
						break;
					}
				}
			}
			if (p == -1) puts("-1");
			else {
				printf("%d\n", p);
				for (int i = 1; i <= p; i++) printf("%d ", e[i].id);
				puts("");
			}
		}
	}	
	return 0;
}