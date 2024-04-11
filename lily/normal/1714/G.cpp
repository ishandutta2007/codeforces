#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 5;
int n;
int a[N], b[N], ans[N];
vector <int> E[N];
LL A[N], B[N];
int dep;
void dfs (int x) {
	++dep;
	A[dep] = A[dep - 1] + a[x];
	B[dep] = B[dep - 1] + b[x];
	ans[x] = upper_bound(B, B + dep + 1, A[dep]) - B - 2;
	for (auto v : E[x]) dfs (v);
	dep --;
}

void work() {
	read(n);
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 2; i <= n; i++) {
		int p;
		read(p); read(a[i]); read(b[i]);
		E[p].push_back(i);
	}
	dfs (1);
	for (int i = 2; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	
}

int main() {
	int T;
	read (T);
	while (T--) work();
}