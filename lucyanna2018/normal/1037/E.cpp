#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define ran 202222
int n, k, m;
set<int> e[ran];
int X[ran], Y[ran];
bool ok[ran];
int q[ran], op, cl;
int res[ran];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		e[X[i]].insert(Y[i]);
		e[Y[i]].insert(X[i]);
	}
	op = cl = 0;
	for (int i = 1; i <= n; i++) {
		ok[i] = true;
		if (e[i].size() < k) {
			q[op++] = i;
			ok[i] = false;
		}
	}

	for (int i = m; i >= 1; i--) {
		while (cl != op) {
			int x = q[cl++];
			for (auto w : e[x]) {
				e[w].erase(x);
				if (e[w].size() < k && ok[w]) {
					q[op++] = w;
					ok[w] = false;
				}
			}
			e[x].clear();
		}
		res[i] = n - cl;
		int xx = X[i], yy = Y[i];
		if (ok[xx] && ok[yy]) {
			e[xx].erase(yy);
			e[yy].erase(xx);
			if (e[xx].size() < k) {
				q[op++] = xx;
				ok[xx] = false;
			}
			if (e[yy].size() < k) {
				q[op++] = yy;
				ok[yy] = false;
			}
		}
	}

	for (int i = 1; i <= m; i++)printf("%d\n", res[i]);
	return 0;
}