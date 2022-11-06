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
using namespace std;
#define MOD 998244353
#define f(i,n) for(int i=0;i<(int) n; i++ )
#define N 200010
int md;
int mdv;
bool used[N];
vector<int>e[N];
int dd[N];
int dd2[N];

void dfs(int k, int d) {
	used[k] = true;
	dd[k] = d;
	if (md < d) {
		md = d;
		mdv = k;
	}
	f(i, e[k].size()) {
		if (!used[e[k][i]]) {
			dfs(e[k][i], d + 1);
		}
	}
	return;
}



int main(void) {
	int n, k;
	int x, y;
	int c;
	scanf("%d %d", &n, &k);
	f(i, n - 1) {
		scanf("%d %d", &x, &y);
		e[x - 1].push_back(y - 1);
		e[y - 1].push_back(x - 1);
	}
	md = -1;
	f(i, n)used[i] = false;
	dfs(0, 0);
	md = -1;
	f(i, n)used[i] = false;
	dfs(mdv, 0);
	if (md != (2 * k)) {
		printf("No\n");
		return 0;
	}
	f(i, n)dd2[i] = dd[i];
	md = -1;
	f(i, n)used[i] = false;
	dfs(mdv, 0);
	f(i, n) {
		if (dd[i] == k && dd2[i] == k) {
			c = i;
			break;
		}
	}
  	md = -1;
	f(i, n)used[i] = false;
	dfs(c, 0);
	f(i, n) {
		if (i == c) {
			if (e[i].size() < 3) {
				printf("No\n");
				return 0;
			}
		}
		else {
			if (e[i].size() == 1) {
				if (dd[i] != k) {
					printf("No\n");
					return 0;
				}
			}
			else if (e[i].size() < 4) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}