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
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z, q;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &q);
	f(qq, q) {
		v = false;
		scanf("%d", &n);
		f(i, n) {
			scanf("%d", &x);
			if (i > 0) {
				if (abs(x - y) > 1) {
					v = true;
					z = i;
				}
			}
			y = x;
		}
		if (v) {
			printf("YES\n");
			printf("%d %d\n", z, z + 1);
		}
		else printf("NO\n");
	}

	return 0;
}