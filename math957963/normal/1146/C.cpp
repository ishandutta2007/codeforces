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
	vector<int>b;
	vector<int>c;
	int t;
	int a[10];
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	a[0] = 1;
	f(i, 9)a[i + 1] = a[i] * 2;
	f(tt, t) {
		scanf("%d", &n);
		ans = 0;
		f(i, 7) {
          		b.clear();
		c.clear();
			f(j, n) {
				if (j%a[i + 1] < a[i])b.push_back(j + 1);
				else c.push_back(j + 1);
			}
			if (b.size() > 0 && c.size() > 0) {
				printf("%d %d ", b.size(), c.size());
				f(i, b.size())printf("%d ", b[i]);
				f(i, c.size() - 1)printf("%d ", c[i]);
				printf("%d\n", c[c.size() - 1]);
				fflush(stdout);
				scanf("%d", &x);
				if (x == -1)return 0;
				ans = max(ans, x);
			}
		}
		printf("-1 %d\n", ans);
		fflush(stdout);
	}


	return 0;
}