#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

map <ii, ii> M;
int n;
int a[Maxn], b[Maxn], c[Maxn];
int best, bi, bj;

int min(int a, int b, int c) { return min(min(a, b), c); }

void Try(int a, int b, int c, int i)
{
	if (M.find(ii(b, c)) != M.end()) {
		ii p = M[ii(b, c)];
		int cand = min(a + p.first, b, c);
		if (cand > best) { best = cand; bi = i; bj = p.second; }
	}
}

void Insert(int a, int b, int c, int i)
{
	if (M.find(ii(b, c)) != M.end()) {
		ii p = M[ii(b, c)];
		if (a > p.first) M[ii(b, c)] = ii(a, i);
	} else M[ii(b, c)] = ii(a, i);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		if (a[i] > b[i]) swap(a[i], b[i]);
		if (b[i] > c[i]) swap(b[i], c[i]);
		if (a[i] > b[i]) swap(a[i], b[i]);
		int cand = min(a[i], b[i], c[i]);

		if (cand > best) { best = cand; bi = i; bj = 0; }

		Try(a[i], b[i], c[i], i);
		Try(b[i], a[i], c[i], i);
		Try(c[i], a[i], b[i], i);

		Insert(a[i], b[i], c[i], i);
		Insert(b[i], a[i], c[i], i);
		Insert(c[i], a[i], b[i], i);
	}
	if (bj) {
		printf("2\n");
		printf("%d %d\n", bi, bj);
	} else {
		printf("1\n");
		printf("%d\n", bi);
	}
	return 0;
}