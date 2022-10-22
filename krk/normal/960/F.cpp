#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int a[Maxn], b[Maxn], w[Maxn];
set <ii> S[Maxn];
int res;

int Get(int ind, int w)
{
	set <ii>::iterator it = S[ind].lower_bound(ii(w, 0));
	it--;
	return it->second;
}

void Insert(int ind, int w, int v)
{
	set <ii>::iterator it = S[ind].lower_bound(ii(w + 1, 0));
	it--;
	if (it->second >= v) return;
	it = S[ind].lower_bound(ii(w, 0));
	while (it != S[ind].end() && v >= it->second) S[ind].erase(it++);
	S[ind].insert(ii(w, v));
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		S[i].insert(ii(-1, 0));
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &w[i]);
		int g = Get(a[i], w[i]) + 1;
		res = max(res, g);
		Insert(b[i], w[i], g);
	}
	printf("%d\n", res);
	return 0;
}