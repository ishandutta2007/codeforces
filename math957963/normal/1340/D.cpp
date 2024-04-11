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
#define N 200000
vector<int>e[N];
vector<int>ansx;
vector<int>ansy;
bool used[N];
void dfs(int k, int t) {
	ansx.push_back(k + 1);
	ansy.push_back(t);
	used[k] = true;
	int x, y, z;
	x = e[k].size() - t;
	y = t + 1;
	if (x <= 0) {
		ansx.push_back(k + 1);
		ansy.push_back(-x);
		y = 1 - x;
	}
	f(i, e[k].size()) {
		if (!used[e[k][i]]) {
			dfs(e[k][i], y);
			ansx.push_back(k + 1);
			ansy.push_back(y);
			x--;
			y++;
			if (x == 0) {
				ansx.push_back(k + 1);
				ansy.push_back(0);
				y = 1;
			}
		}
	}
}


int main() {
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n - 1) {
		scanf("%d %d", &x, &y);
		e[x - 1].push_back(y - 1);
		e[y - 1].push_back(x - 1);
	}
	f(i, n) {
		used[i] = false;
	}
	dfs(0, 0);
	printf("%d\n", ansx.size() - 1);
	f(i, ansx.size() - 1)printf("%d %d\n", ansx[i], ansy[i]);


	return 0;
}