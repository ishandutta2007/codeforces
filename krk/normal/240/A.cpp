#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int m, k;
int n;
bool fav[Maxn];
int mn[Maxn], mx[Maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &m, &k);
	for (int i = 0; i < k; i++) {
		int a; scanf("%d", &a);
		fav[a] = true;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int d; scanf("%d", &d);
		int f = 0, u = 0, nf = 0;
		while (d--) {
			int a; scanf("%d", &a);
			if (a == 0) u++;
			else if (fav[a]) f++;
			else nf++;
		}
		mn[i] = max(f, f + u - (m - k - nf)); mx[i] = min(f + u, k);
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j == i || j < n && mx[i] >= mn[j]) j++;
		if (j < n) { printf("1\n"); continue; }
		j = 0;
		while (j == i || j < n && mn[i] >= mx[j]) j++;
		if (j == n) printf("0\n");
		else printf("2\n");
	}
	return 0;
}