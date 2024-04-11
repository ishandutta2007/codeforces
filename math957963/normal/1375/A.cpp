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
	int a[N];
	f(i, N)a[i] = 0;
	int n, k, t;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, n) {
			scanf("%d", &a[i]);
		}
		if (a[0] < 0) {
			f(i, n - 1) {
				if (i % 2 == 0) {
					if (a[i + 1] < 0)a[i + 1] = -a[i + 1];
				}
				else {
					if (a[i + 1] > 0)a[i + 1] = -a[i + 1];
				}
			}
		}
		else {
			f(i, n - 1) {
				if (i % 2 == 0) {
					if (a[i + 1] > 0)a[i + 1] = -a[i + 1];
				}
				else {
					if (a[i + 1] < 0)a[i + 1] = -a[i + 1];
				}
			}
		}
		f(i, n - 1)printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}