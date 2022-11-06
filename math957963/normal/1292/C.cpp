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

long long n;
bool used[3000][3000];
bool us[3000];
long long a[3000][3000];
vector<long long>e[3000];
vector<long long>r[3000];
vector<long long>d[3000];
long long st[3000][3000];
long long go[3000][3000];
queue<pair<long long, long long> >q;

long long dfs(long long k) {
	long long re;
	long long ret = 1;
	us[k] = true;
	f(i, e[k].size()) {
		if (!us[e[k][i]]) {
			re = dfs(e[k][i]);
			d[k][i] = re;
			d[e[k][i]][r[k][i]] = n - re;
			ret += re;
		}
	}
	return ret;
}


int main() {
	f(i, 3000) {
		f(j, 3000) {
			used[i][j] = false;
			a[i][j] = 10000000000000;
		}
		used[i][i] = true;
		a[i][i] = 0;
		us[i] = false;
}
	long long x, y, z, xx, yy;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n-1) {
		scanf("%I64d %I64d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		d[x].push_back(-1);
		r[x].push_back(e[y].size());
		e[y].push_back(x);
		d[y].push_back(-1);
		r[y].push_back(e[x].size()-1);
	}
	dfs(0);
	f(i, n) {
		f(j, e[i].size()) {
			if (i > e[i][j]) {
				st[i][e[i][j]] = n - d[i][j];
				go[i][e[i][j]] = d[i][j];
				a[i][e[i][j]] = st[i][e[i][j]] * go[i][e[i][j]];
				q.push(make_pair(i, e[i][j]));
			}
		}
	}
	ans = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		ans = max(ans, a[x][y]);
		used[x][y] = true;
		f(i, e[x].size()) {
			xx = max(y, e[x][i]);
			yy = min(y, e[x][i]);
			if (!used[xx][yy]) {
				s = a[x][y] + (d[x][i] * go[x][y]);
				if (a[xx][yy] == 10000000000000) {
					if (xx == y) {
						st[xx][yy] = go[x][y];
						go[xx][yy] = d[x][i];
					}
					else {
						st[xx][yy] = d[x][i];
						go[xx][yy] = go[x][y];
					}
					a[xx][yy] = s;
					q.push(make_pair(xx, yy));
				}
				else a[xx][yy] = max(a[xx][yy], s);
			}
		}
		f(i, e[y].size()) {
			xx = max(x, e[y][i]);
			yy = min(x, e[y][i]);
			if (!used[xx][yy]) {
				s = a[x][y] + (d[y][i] * st[x][y]);
				if (a[xx][yy] == 10000000000000) {
					if (xx == x) {
						st[xx][yy] = st[x][y];
						go[xx][yy] = d[y][i];
					}
					else {
						st[xx][yy] = d[y][i];
						go[xx][yy] = st[x][y];
					}
					a[xx][yy] = s;
					q.push(make_pair(xx, yy));
				}
				else a[xx][yy] = max(a[xx][yy], s);
			}
		}
		q.pop();
	}

	printf("%I64d\n", ans);


	return 0;
}