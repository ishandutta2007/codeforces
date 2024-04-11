#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 250010
vector<int>e[N];
bool used[N];

void dfs(int k, int d) {
	used[k] = true;
	f(i, e[k].size()) {
		if (!used[e[k][i]] && (e[k][i] != d))dfs(e[k][i], d);
	}
	return;
}




int main() {
	int t;
	int n, m, a, b;
	int x, y;
	long long xx, yy;

	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d %d %d", &n, &m,&a, &b);
		a--;
		b--;
		f(i, m) {
			scanf("%d %d", &x, &y);
			x--;
			y--;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		f(i, n)used[i] = false;
		dfs(a, b);
		xx = 0;
		f(i, n) {
			if (!used[i])xx++;
		}
		f(i, n)used[i] = false;
		dfs(b, a);
		yy = 0;
		f(i, n) {
			if (!used[i])yy++;
		}
		xx--;
		yy--;
		printf("%lld\n", (xx*yy));
		f(i, n) {
			e[i].clear();
		}
	}

	return 0;
}