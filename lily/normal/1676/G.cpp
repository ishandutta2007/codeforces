#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}

const int N = 2e5 + 5;

int n, fa[N];
vector <int>E[N];
int siz[N], w[N], ans;
char c[N];

void dfs (int x) {
	siz[x] = 1;
	w[x] = c[x] == 'W';
	for (auto v : E[x]) dfs(v), siz[x] += siz[v], w[x] += w[v];
	if (w[x] * 2 == siz[x]) ans ++;
}


void work() {
	read(n);
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 2; i <= n; i++) read(fa[i]), E[fa[i]].push_back(i);
	scanf("%s", c + 1);
	ans = 0;
	dfs(1);
	printf("%d\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}