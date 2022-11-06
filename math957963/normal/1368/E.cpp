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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 300010


int main() {
	int t;
	bool ex[N];
	int n, m;
	int x, y;
	int sz, sz2;
	vector<int>e[N];
	vector<int>ans;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &m);
		f(i, n) {
			e[i].clear();
			ex[i] = true;
		}
		f(i, m) {
			scanf("%d %d", &x, &y);
			e[y - 1].push_back(x - 1);
		}
		f(i, n) {
				sz = e[i].size();
				f(ii, sz) {
					if (ex[e[i][ii]]) {
						sz2 = e[e[i][ii]].size();
						f(jj, sz2) {
							if (ex[e[e[i][ii]][jj]])ex[i] = false;
						}
					}
				}
		}
		ans.clear();
		f(i, n)if (!ex[i])ans.push_back(i + 1);
		sz = ans.size();
		printf("%d\n", sz);
		f(i, sz - 1)printf("%d ", ans[i]);
		if (sz > 0)printf("%d\n", ans[sz - 1]);
	}
	return 0;
}