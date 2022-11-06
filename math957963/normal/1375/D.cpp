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


int main() {
	int n, k, t, x, sz;
	int a[N];
	vector<int>b;
	vector<int>ans;
	bool v;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, n)scanf("%d", &a[i]);
		ans.clear();
		while (true) {
			v = true;
			f(i, n - 1) {
				if (a[i] > a[i + 1])v = false;
			}
			if (v)break;
			b.clear();
			f(i, n)b.push_back(a[i]);
			sort(b.begin(), b.end());
			x = 0;
			f(i, n) {
				if (x < b[i])break;
				x = b[i] + 1;
			}
			if (x == n) {
				f(i, n) {
					if (a[i] != i) {
						k = i;
						break;
					}
				}
				f(i, n) {
					if (a[i] == k) {
						k = i;
						break;
					}
				}
				ans.push_back(k + 1);
				a[k] = n;
			}
			else {
				ans.push_back(x + 1);
				a[x] = x;
			}
		}
		sz = ans.size();
		printf("%d\n", sz);
		f(i, sz - 1)printf("%d ", ans[i]);
		if (sz > 0)printf("%d", ans[sz - 1]);
		printf("\n");
	}

	return 0;
}