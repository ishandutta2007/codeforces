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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 1100000


int main() {
	int b[25];
	vector<pair<long long, long long> >c[N];
	vector<pair<long long, long long> >e;
	vector<long long>ans;
	long long d[N];
	long long cc[N];
	bool used[N];
	long long s = 0;
	b[0] = 1;
	f(i, 24)b[i + 1] = b[i] * 2;
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k, t,nn,kk;
	long long x, y, z;
	bool v = true;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld %lld", &nn, &kk);
		n = b[nn] - 1;
		k = b[kk] - 1;
		f(i, n) {
			scanf("%d", &a[i+1]);
			used[i + 1] = false;
		}
		ans.clear();
		s = 0;
		f(i, b[kk - 1])c[i].clear();
		x = b[kk - 1];
		f(i, nn - kk+1) {
			f(j, b[kk - 1]) {
				f(ii, b[i]) {
					c[j].push_back(make_pair(a[x], x));
					x++;
				}
			}
		}
		f(i, b[kk - 1]) {
			sort(c[i].begin(), c[i].end(), greater<pair<int,int> >());
			x = c[i].size() - 1;
			used[c[i][x].second] = true;
			d[b[kk - 1] + i] = c[i][x].second;
			s += c[i][x].first;
		}
		for (int i = kk - 2; i >= 0; i--) {
				f(j, b[i]) {
					x = 0;
					y = 0;
					e.clear();
					e.push_back(make_pair(a[(b[i] + j)],b[i]+j));
					while ((x < c[(2 * j)].size()) && (y < c[(2 * j) + 1].size())) {
						if (c[(2 * j)][x] > c[(2 * j) + 1][y]) {
							if (used[(c[(2 * j)][x].second)]) {
								while (!used[(c[(2 * j) + 1][y].second)]) {
									ans.push_back(b[i + 1] + (2 * j) + 1);
									y++;
								}
								break;
							}
							e.push_back(c[(2 * j)][x]);
							x++;
						}
						else {
							if (used[(c[(2 * j) + 1][y].second)]) {
								while (!used[(c[(2 * j)][x].second)]) {
									ans.push_back(b[i + 1] + (2 * j));
									x++;
								}
								break;
							}
							e.push_back(c[(2 * j) + 1][y]);
							y++;
						}
					}
					c[j] = e;
					x = c[j].size() - 1;
					used[c[j][x].second] = true;
					d[b[i] + j] = c[j][x].second;
					s += c[j][x].first;
				}
		}
		x = ans.size();
		f(i, n - k - x)ans.push_back(1);
printf("%lld\n",s);
		f(i, n - k-1) {
			printf("%lld ", ans[n - k - i - 1]);
		}
		printf("%lld\n", ans[0]);
	}

	return 0;
}