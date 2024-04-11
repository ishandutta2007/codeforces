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


int main() {
	int a[5][110];
	int b[4][4];
	int bb[4][4];
	vector < pair<int, pair<int, int> > >p;
	int c[4];
	int n, k, t, m;
	int x, y, z;
	int s, ans;
	bool v = true;
	bool vv;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d",&n, &m);
		p.clear();
		ans = 0;
		f(i, n) {
			f(j, m) {
				scanf("%d", &a[i][j]);
				p.push_back(make_pair(a[i][j], make_pair(i, j)));
			}
		}
		k = min(n, m);
		sort(p.begin(), p.end(), greater<pair<int, pair<int, int> > >());
		x = 0;
		y = 0;
		while (y < k) {
			v = true;
			f(i, y) {
				if (p[x].second.second == c[i])v = false;
			}
			if (v) {
				c[y] = p[x].second.second;
				y++;
			}
			x++;
		}
		f(i, n) {
			f(j, k) {
				b[i][j] = a[i][c[j]];
			}
}
		m = 0;
		ans = 0;
			f(ii, n) {
				f(jj, n) {
					f(kk, n) {
						s = 0;
						f(i, n) {
							m = 0;
							f(j, k) {
								if (j == 0)bb[i][j] = b[i][j];
								if (j == 1)bb[i][j] = b[((i+ii)%n)][j];
								if (j == 2)bb[i][j] = b[((i + jj) % n)][j];
								if (j == 3)bb[i][j] = b[((i + kk) % n)][j];
								m = max(m, bb[i][j]);
							}
							s += m;
						}
						ans = max(ans, s);
					}
				}
			}
		printf("%d\n", ans);
	}


	return 0;
}