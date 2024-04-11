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
#define N 600000
vector<int>e[N];
vector<int>ee[N];
vector<int>ans;


int main() {
	int n, m;
	int a[N];
	int b[N];
	int c[N];
	int d[N];
	int sz;
	int cur;
	bool v[N];
	int x, y;
	scanf("%d %d", &n, &m);
	f(i, m) {
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
	}
	f(i, n) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	f(i, n)d[i] = 0;
	f(i, m) {
		if (c[a[i]] == c[b[i]]) {
			printf("-1\n");
			return 0;
		}
		if (c[a[i]] < c[b[i]]) {
			e[a[i]].push_back(b[i]);
			ee[b[i]].push_back(a[i]);
			d[b[i]]++;
		}
		if (c[a[i]] > c[b[i]]) {
			ee[a[i]].push_back(b[i]);
			e[b[i]].push_back(a[i]);
			d[a[i]]++;
		}
	}
	f(i, n) {
		f(j, c[i])v[j] = false;
		sz = ee[i].size();
		f(j, sz)v[c[ee[i][j]]] = true;
		f(j, c[i]) {
			if (!v[j]) {
				printf("-1\n");
				return 0;
			}
		}
	}
	cur = 0;
	sz = 0;
	f(i, n) {
		if (d[i] == 0) {
			ans.push_back(i);
			sz++;
		}
	}
	while (cur < sz) {
		x = ans[cur];
		y = e[x].size();
		f(i, y) {
			d[e[x][i]]--;
			if (d[e[x][i]] <= 0) {
				ans.push_back(e[x][i]);
				sz++;
			}
		}
		cur++;
	}
	if (sz < n) {
		printf("-1\n");
		return 0;
	}
	f(i, n - 1)printf("%d ", ans[i]+1);
	printf("%d\n", ans[n - 1]+1);


	return 0;
}