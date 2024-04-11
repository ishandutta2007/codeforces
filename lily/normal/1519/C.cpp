#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 200021;


vector <LL> U[N];
LL ans[N];
int u[N], s[N];

int main() {
	int T;
	read(T);
	while (T--) {
		int n;
		read(n); 
		for (int i = 1; i <= n; i++) read(u[i]);
		for (int i = 1; i <= n; i++) read(s[i]);
		for (int i = 1; i <= n; i++) U[i].clear();
		for (int i = 1; i <= n; i++) U[u[i]].push_back(s[i]);
		for (int i = 1; i <= n; i++) ans[i] = 0;
		for (int i = 1; i <= n; i++) if (U[i].size()) {
			sort(U[i].begin(), U[i].end());
			auto &vec = U[i];
			int m = U[i].size();
			for (int i = m - 2; i >= 0; i--) {
				vec[i] += vec[i + 1];
			}
			for (int i = 1; i <= m; i++) {
				ans[i] += vec[m % i];
			}
		}
		for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
		puts("");
	}

}