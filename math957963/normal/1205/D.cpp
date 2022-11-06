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
#define N 20000
int n, k;
int p[N];
int ch[N];
vector<int>e[N];
int c[N];
vector<int>e1[N];
vector<int>e2[N];
vector<pair<int, int> >hur;
int cent;
vector<int>ansx;
vector<int>ansy;
vector<int>ansz;

int d[N];
int xx, yy;

int dfs(int k) {
	int re = 1;
	int x;
	bool v = true;
	f(i, e[k].size()) {
		if (e[k][i] != p[k]) {
			p[e[k][i]] = k;
			x = dfs(e[k][i]);
			if ((2 * x) >= n)v = false;
			re += x;
		}
	}
	ch[k] = re;
	if ((2 * re) < n)v = false;
	if (v)cent = k;
	return re;
}

void dfs2(int k, int cc) {
	c[k] = cc;
	f(i, e[k].size()) {
		if ((e[k][i] != cent)&&(c[e[k][i]]==0)) {
			if (cc == 1) {
				e1[k].push_back(e[k][i]);
				e1[e[k][i]].push_back(k);
				dfs2(e[k][i], cc);
			}
			else {
				e2[k].push_back(e[k][i]);
				e2[e[k][i]].push_back(k);
				dfs2(e[k][i], cc);
			}
		}
	}
	return;
}

void dfs3(int k) {
	f(i, e1[k].size()) {
		if (d[e1[k][i]] < 0) {
			d[e1[k][i]] = xx;
			ansx.push_back(k);
			ansy.push_back(e1[k][i]);
			ansz.push_back(xx - d[k]);
			xx++;
			dfs3(e1[k][i]);
		}
}
	return;
}

void dfs4(int k) {
	f(i, e2[k].size()) {
		if (d[e2[k][i]] < 0) {
			d[e2[k][i]] = yy;
			ansx.push_back(k);
			ansy.push_back(e2[k][i]);
			ansz.push_back(((yy - d[k])*xx));
			yy++;
			dfs4(e2[k][i]);
		}
	}
	return;
}



int main() {
	int a[N];
	int x, y, z;
	int sx, sy;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n-1) {
		scanf("%d %d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cent = 0;
	p[0] = -1;
	dfs(0);
	f(i, e[cent].size()) {
		if (e[cent][i] == p[cent]) {
			x = n - ch[cent];
			hur.push_back(make_pair(x, e[cent][i]));
		}
		else {
			hur.push_back(make_pair(ch[e[cent][i]], e[cent][i]));
		}
	}
	sort(hur.begin(), hur.end());
	sx = 0;
	sy = 0;
	f(i, N)c[i] = 0;
	c[cent] = 3;
	for (int i=hur.size() - 1; i >= 0; i--) {
		if (sy < sx) {
			x = hur[i].second;
				c[x] = 2;
			e2[x].push_back(cent);
			e2[cent].push_back(x);
			dfs2(x, 2);
			sy += (hur[i].first);
		}
		else {
			x = hur[i].second;
			c[x] = 1;
			e1[x].push_back(cent);
			e1[cent].push_back(x);
			dfs2(x, 1);
			sx += (hur[i].first);
		}
	}
	f(i, N)d[i] = -1;
	d[cent] = 0;
	xx = 1;
	dfs3(cent);
	yy = 1;
	dfs4(cent);
	f(i, ansx.size()) {
		printf("%d %d %d\n", ansx[i]+1, ansy[i]+1, ansz[i]);
	}


	return 0;
}