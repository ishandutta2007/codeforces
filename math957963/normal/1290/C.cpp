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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 400010


int p[N];
int d[N];
int cc[N];
int x0[N];
int x1[N];
int xx[N];
vector<int>g[N];
vector<bool>gg[N];

void dfs(int k, int x) {
	cc[k] = x;
	f(i, g[k].size()) {
		if (cc[g[k][i]] == -1) {
			if (gg[k][i])dfs(g[k][i], x);
			else dfs(g[k][i], (x + 1) % 2);
		}
	}
	return;
}


void init(void) {
	f(i, N) {
		p[i] = i;
		d[i] = 1;
		if (cc[i] == 0) {
			x0[i] = 1;
			x1[i] = 0;
		}
		else {
			x0[i] = 0;
			x1[i] = 1;
		}
		xx[i] = -1;
	}
	return;
}

int pa(int x) {
	if (p[x] == x)return x;
	else return p[x] = pa(p[x]);
}


void uni(int x, int y) {
	int px = pa(x);
	int py = pa(y);
	if (px == py)return;
	if (d[px] < d[py]) {
		p[px] = py;
		d[py] = max(d[py], d[px] + 1);
		x0[py] += x0[px];
		x1[py] += x1[px];
		xx[py] = max(xx[py], xx[px]);
	}
	else {
		p[py] = px;
		d[px] = max(d[px], d[py] + 1);
		x0[px] += x0[py];
		x1[px] += x1[py];
		xx[px] = max(xx[py], xx[px]);
	}
	return;
}

bool jud(int x, int y) {
	int px = pa(x);
	int py = pa(y);
	if (px == py)return true;
	else return false;
}

int ret(int k) {
	if (xx[k] == -1)return min(x0[k], x1[k]);
	else if (xx[k] == 0)return x0[k];
	else return x1[k];
}


int main() {
	int b[N];
	int c[N];
	int e[N];
	char a[N];
	f(i, N) {
		a[i] = 0;
		b[i] = -1;
		c[i] = -1;
		e[i] = 0;
	}
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &k);
	scanf("%s", a);

	f(i, k) {
		scanf("%d", &x);
		f(j, x) {
			scanf("%d", &y);
			y--;
			if (e[y] == 0) {
				b[y] = i;
				e[y]++;
			}
			else {
				c[y] = i;
				e[y]++;
				g[b[y]].push_back(c[y]);
				g[c[y]].push_back(b[y]);
				if (a[y] == '1') {
					gg[b[y]].push_back(true);
					gg[c[y]].push_back(true);
				}
				else {
					gg[b[y]].push_back(false);
					gg[c[y]].push_back(false);
				}
			}
		}
	}
	f(i, k)cc[i] = -1;
	f(i, k) {
		if (cc[i] == -1)dfs(i,0);
	}


	init();
	s = 0;
	f(i, n) {
		if (e[i] == 1) {
			x = pa(b[i]);
			if (xx[x] == -1) {
				if (a[i] == '0') {
					s -= min(x0[x], x1[x]);
					if (cc[b[i]] == 0) {
						xx[x] = 0;
						s += x0[x];
					}
					else {
						xx[x] = 1;
						s += x1[x];
					}
				}
				else {
					s -= min(x0[x], x1[x]);
					if (cc[b[i]] == 0) {
						xx[x] = 1;
						s += x1[x];
					}
					else {
						xx[x] = 0;
						s += x0[x];
					}
				}
			}
		}
		else if (e[i] == 2) {
			x = pa(b[i]);
			y = pa(c[i]);
			if (x != y) {
				s -= ret(x);
				s -= ret(y);
				uni(x, y);
				x = pa(x);
				s += ret(x);
			}
		}
		printf("%d\n", s);
	}





	return 0;
}