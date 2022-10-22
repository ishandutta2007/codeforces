#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, q;
int a[Maxn];
int mn[Maxn], mx[Maxn];
set <int> S;

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!mn[a[i]]) mn[a[i]] = i;
		mx[a[i]] = i;
		S.insert(i);
	}
	if (!mn[q]) {
		bool found = false;
		for (int i = 1; i <= n && !found; i++)
			if (a[i] == 0) { mn[q] = mx[q] = i; found = true; }
		if (!found) { printf("NO\n"); return 0; }
	}
	for (int i = q; i > 1; i--) if (mn[i]) {
		set <int>::iterator it = S.lower_bound(mn[i]);
		while (it != S.end() && *it <= mx[i]) {
			if (a[*it] != 0 && a[*it] != i) { printf("NO\n"); return 0; }
			a[*it] = i; S.erase(it++);
		}
	}
	for (set <int>::iterator it = S.begin(); it != S.end(); it++)
		a[*it] = 1;
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
	return 0;
}