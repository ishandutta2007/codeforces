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
#define N 300000

vector<int>e[N];
bool used[N][2];
bool on[N][2];
bool suc;
bool drw;
vector<int>as;

void dfs(int k, int c) {
	int cc = (c + 1) % 2;
	used[k][c] = true;
	on[k][c] = true;
	if ((e[k].size() == 0) && (c == 1)) {
		suc = true;
		as.push_back(k);
		return;
	}
		f(i, e[k].size()) {
			if (on[e[k][i]][0]) {
				drw = true;
			}
			if (on[e[k][i]][1]) {
				drw = true;
			}
		}
	f(i, e[k].size()) {
		if (!used[e[k][i]][cc]) {
			dfs(e[k][i], cc);
			if (suc) {
				as.push_back(k);
				return;
			}
		}
	}
	on[k][c] = false;
	return;
}


int main() {
	int a[N];
	f(i, N)a[i] = 0;
	int n, m, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	f(i, N) {
		used[i][0] = false;
		used[i][1] = false;
		on[i][0] = false;
		on[i][1] = false;

	}
	scanf("%d %d", &n, &m);
	f(i, n) {
		scanf("%d", &k);
		f(j, k) {
			scanf("%d", &x);
			e[i].push_back(x - 1);
		}
	}
	scanf("%d", &z);
	z--;
	suc = false;
	drw = false;
	dfs(z, 0);
	if (suc) {
		printf("Win\n");
		k = as.size();
		f(i, k) {
			printf("%d", as[k - i - 1] + 1);
			if (i < (k - 1))printf(" ");
			else printf("\n");
		}
		return 0;
	}
	if (drw) {
		printf("Draw\n");
		return 0;
	}

	printf("Lose\n");


	return 0;
}