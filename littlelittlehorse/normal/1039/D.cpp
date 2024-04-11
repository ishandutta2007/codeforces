#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	node *next;
	int where;
} a[200001], *first[100001], a1[200001], *first1[100001];
int n, dist[100001], l1, c[100001], l, u[100001], ans[100001];

inline void makelist(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}

inline void makelist1(int x, int y) {
	a1[++l1].where = y;
	a1[l1].next = first1[x];
	first1[x] = &a1[l1];
}

int calc(int cur) {
	if (ans[cur] != -1)
		return ans[cur];
	int res = 0;
	for (int i = n; i; --i) {
		int m = c[i], Max1 = 0, Max2 = 0; u[m] = 0;
		for (node *x = first1[m]; x; x = x->next)
			if (u[x->where] > Max1)
				Max2 = Max1, Max1 = u[x->where];
			else
				if (u[x->where] > Max2)
					Max2 = u[x->where];
		if (Max1 + Max2 + 1 >= cur)
			++res;
		else
			u[m] = Max1 + 1;
	}
	return ans[cur] = res;
}

int main() {
	memset(ans, 255, sizeof(ans));
	scanf("%d", &n);
	memset(first, 0, sizeof(first));
	l = 0;
	memset(first1, 0, sizeof(first1));
	l1 = 0;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		makelist(x, y);
		makelist(y, x);
	}
	memset(dist, 0, sizeof(dist));
	dist[1] = 1; c[1] = 1;
	for (int k = 1, l = 1; l <= k; l++) {
		int m = c[l];
		for (node *x = first[m]; x; x = x->next)
			if (!dist[x->where])
				dist[x->where] = dist[m] + 1, c[++k] = x->where,
				makelist1(m, x->where);
	}
	int i = 1;
	for (; i <= n; ) {
		int L = 1, R = n + 1, M = (L + R) >> 1, v = calc(i);
		if (1LL * i * i <= n) 
			L = i;
		else {
			for (; L + 1 < R; M = (L + R) >> 1) 
				if (calc(M) >= v)
					L = M;
				else
					R = M;
		}
		for (int j = i; j <= L; j++)
			printf("%d\n", v);
		i = L + 1;
	}
}