#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
#define pb emplace_back
typedef vector<int> vi;

#define MAXN 200005

int t;
int n;
int b[MAXN], nb[MAXN];
bool used[MAXN * 2];

int getMax(int* a, int* b) {
	int r = 0;
	REP (l, 0, n) {
		while (r < n && a[l] > b[r]) r++;
		if (r == n) return l;
		r++;
	}
	return n;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &b[i]);
			used[b[i]] = true;
		}
		int cnt = 0;
		REP (i, 1, 2 * n + 1) {
			if (!used[i]) nb[cnt++] = i;
		}
		int mx = getMax(b, nb), mn = n - getMax(nb, b);
		printf("%d\n", mx - mn + 1);
		REP(i, 1, 2 * n + 1) used[i] = false;
	}
	return 0;
}