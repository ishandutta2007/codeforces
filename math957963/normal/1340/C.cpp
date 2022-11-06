#pragma GCC optimize("O3")
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
bool used[1001][10000];
int main() {
	int n, x, xx, y, z, g, r;
	vector<int>a;
	priority_queue<pair<int, pair<int, int> > >pq;
	vector<pair<int, int> >q;
	vector<int>p;
	pair<int, pair<int, int> > pp;
	int b[N];
	int c[N];
	int ans, s;
	scanf("%d %d", &x, &n);
	f(i, n) {
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	scanf("%d %d", &g, &r);
	f(i, N) {
		b[i] = 10000;
		c[i] = 10000;
	}
	f(i, n - 1) {
		b[i] = a[i + 1] - a[i];
		c[i + 1] = a[i + 1] - a[i];
	}
	if (a[n - 1] <= g) {
		printf("%d\n", a[n - 1]);
		return 0;
	}
	f(i, g + 1) {
		f(j, n) {
			used[i][j] = false;
		}
	}
	q.push_back(make_pair(0, 0));
	used[0][0] = true;
	s = r + g;
	ans = MOD;
	int sz;
	while (q.size()>0) {
		x = 0;
		while (x < q.size()) {
			y = q[x].first;
			z = q[x].second;
			if (y == g) {
				if (a[n - 1] - a[z] <= g) {
					ans = min(ans, s + a[n - 1] - a[z]);
				}
				if (!used[0][z]) {
					p.push_back(z);
				}
			}
			if ((y + b[z]) <= g) {
				if (!used[y + b[z]][z + 1]) {
					q.push_back(make_pair(y + b[z], z + 1));
					used[y + b[z]][z + 1] = true;
				}
			}
			if ((y + c[z]) <= g) {
				if (!used[y + c[z]][z - 1]) {
					q.push_back(make_pair(y + c[z], z - 1));
					used[y + c[z]][z - 1] = true;
				}
			}
			x++;
		}
		if (ans < MOD) {
			printf("%d\n", ans);
			return 0;
		}
		s += r + g;
		sz = p.size();
		q.clear();
		f(i, sz) {
			q.push_back(make_pair(0, p[i]));
			used[0][p[i]] = true;
		}
		p.clear();
	}
		printf("-1\n");
		return 0;
}