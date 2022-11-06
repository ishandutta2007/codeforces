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
int a[N];
int c[N];
vector<int>e[N];
int p[N];
int b[N];
int pp;
bool vv;

int dfs(int k) {
	int re = 0;
	f(i, e[k].size()) re += dfs(e[k][i]);
	if (a[k] > re)vv = false;
	b[k] = re + 1;
	return (re + 1);
}

vector<pair<int,int> > dfs2(int k) {
	vector<pair<int,int> >q;
	vector<pair<int,int> >qq;
	if (b[k] == 1) {
		c[k] = 1;
		qq.push_back(make_pair(c[k], k));
		return qq;
	}
	f(i, e[k].size()) {
		q=dfs2(e[k][i]);
		f(i, q.size()) {
			qq.push_back(q[i]);
		}
	}
	sort(qq.begin(), qq.end());
	c[k] = a[k] + 1;
	f(i, qq.size()) {
		if (i < a[k]) {
			qq[i].first = i + 1;
			c[qq[i].second] = qq[i].first;
		}
		else {
			qq[i].first = i + 2;
			c[qq[i].second] = qq[i].first;
		}
	}
	qq.push_back(make_pair(c[k], k));
	return qq;
}

int main() {
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d %d", &p[i], &a[i]);
		p[i]--;
		if (p[i] >= 0)e[p[i]].push_back(i);
		else pp = i;
	}
	vv = true;
	dfs(pp);
	if (!vv) {
		printf("NO\n");
		return 0;
	}
	dfs2(pp);
	printf("YES\n");
	f(i, n) {
		printf("%d", c[i]);
		if (i < (n - 1))printf(" ");
		else printf("\n");
	}

	return 0;
}