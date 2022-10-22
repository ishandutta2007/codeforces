#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m;
int a[Maxn];
int b[Maxn];
int c[Maxn];
vector <int> nd[Maxn];
int res[Maxn];

bool Check()
{
	if (!nd[c[m]].empty()) {
		res[m] = nd[c[m]].back();
		a[res[m]] = c[m];
		nd[c[m]].pop_back();
		return true;
	}
	for (int i = 1; i <= n; i++)
		if (c[m] == b[i]) {
			res[m] = i;
			return true;
		}
	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			nd[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
			if (a[i] != b[i]) nd[b[i]].push_back(i);
		}
		for (int i = 1; i <= m; i++)
			scanf("%d", &c[i]);
		if (!Check()) { printf("NO\n"); continue; }
		for (int i = m - 1; i >= 1; i--)
			if (!nd[c[i]].empty()) {
				res[i] = nd[c[i]].back();
				a[res[i]] = c[i];
				nd[c[i]].pop_back();
			} else { res[i] = res[m]; }
		bool sam = true;
		for (int i = 1; i <= n && sam; i++)
			sam = a[i] == b[i];
		if (!sam) { printf("NO\n"); continue; }
		printf("YES\n");
		for (int i = 1; i <= m; i++)
			printf("%d%c", res[i], i + 1 <= m? ' ': '\n');
	}
    return 0;
}