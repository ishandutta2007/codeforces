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
#define N 310000


int main() {
	vector<int>a[N];
	int ans[N];
	int n, t;
	int x, y;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, n) {
			scanf("%d", &x);
			a[x-1].push_back(i);
			ans[i] = MOD;
		}
		f(i, n) {
			x = a[i].size();
			if (x > 0) {
				a[i].push_back(-1);
				a[i].push_back(n);
				sort(a[i].begin(), a[i].end());
				x++;
				y = 0;
				f(j, x) {
					y = max(y, a[i][j + 1] - a[i][j]);
				}
				ans[y - 1] = min(ans[y - 1], i + 1);
				a[i].clear();
			}
		}
		f(i, n-1) {
			ans[i + 1] = min(ans[i], ans[i + 1]);
		}
		f(i, n) {
			if (ans[i] == MOD)ans[i] = -1;
		}
		f(i, n-1) {
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[n - 1]);
	}

	return 0;
}