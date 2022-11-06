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
bool l[N];
bool p[N];
int d[N];
bool v0, v1;

void dfs(int k,int dd) {
	d[k] = dd;
	if (l[k] == true) {
		if (d[k] % 2 == 0)v0 = true;
		else v1 = true;
	}
	f(i, e[k].size()) {
		if (d[e[k][i]] < 0) {
			dfs(e[k][i], dd + 1);
		}
	}
	return;
}


int main() {
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n-1) {
		scanf("%d %d", &x, &y);
		e[x - 1].push_back(y - 1);
		e[y - 1].push_back(x - 1);
	}
	if (n == 2) {
		printf("1 1\n");
		return 0;
	}
	f(i, n) {
		l[i] = false;
		p[i] = false;
	}
	f(i, n) {
		if (e[i].size() == 1) {
			l[i] = true;
			p[e[i][0]] = true;
		}
	}
	s = n - 1;
	f(i, n) {
		if (l[i])s--;
		if (p[i]) s++;
	}
	f(i, n)d[i] = -1;
	v0 = false;
	v1 = false;
	dfs(0, 0);
	if (v0&&v1) {
		printf("3 %d\n", s);
	}
	else printf("1 %d\n", s);

	return 0;
}