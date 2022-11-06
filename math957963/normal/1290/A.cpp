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
	int a[N];
	int b[N];
	vector<int>c;
	f(i, N)a[i] = 0;
	int n, k, m, t, l, r, mid;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt,t){
		scanf("%d %d %d", &n, &m, &k);
		f(i, n) {
			scanf("%d", &a[i]);
		}
		c.clear();
		f(i, m) {
			b[i] = max(a[i], a[n - m + i]);
			c.push_back(b[i]);
		}
		sort(c.begin(), c.end());
		l = 0;
		r = m;
		while ((l + 1) < r) {
			mid = (l + r) / 2;
			x = 0;
			y = 0;
			f(i, m) {
				if (b[i] >= c[mid])x++;
				else {
					y = max(x, y);
					x = 0;
				}
			}
			y = max(x, y);
			x = 0;
			if (y >= (m - k))l = mid;
			else r = mid;
		}

		printf("%d\n", c[l]);
	}




	return 0;
}