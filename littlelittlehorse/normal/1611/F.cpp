#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct node {
	long long v;
	int p;
	bool operator < (const node &A) const {
		return v > A.v;
	}
} s[200011];
set<int> c;
int n, m, test;
long long a[200011];

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		a[n + 1] =  -(1LL << 60LL);
		s[n + 1].p = n + 1;
		s[n + 2].v = 0;
		s[n + 2].p = n + 2;
		for (int i = n + 1 ; i; i--) {
			s[i].v = a[i] + s[i + 1].v;
			s[i].p = i;
		}
		sort(s + 1, s + n + 3);
		c.clear();
		int l = 1, l1 = 0, r1 = -1;
		for (int i = 1; i <= n + 2; i++) {
			for (; l <= n + 2 && s[l].v > s[i].v + m; ++l) {
				c.insert(s[l].p);
			}
			auto itr = c.lower_bound(s[i].p);
			int x = 0, y = 0;
			if (itr == c.end())
				continue;
			else
				x = s[i].p, y = *itr - 2;
			if (y - x > r1 - l1)
				l1 = x, r1 = y;
		}
		if (l1 > r1)
			printf("-1\n");
		else
			printf("%d %d\n", l1, r1);
	}
}