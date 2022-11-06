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
	int n, m, c, x;
	int a[2000];
	int b[2000];
	f(i, 2000) {
		a[i] = 100000;
		b[i] = -1;
	}
	bool v;
	scanf("%d %d %d", &n, &m, &c);
	while (true) {
		scanf("%d", &x);
		if ((2 * x) <= c) {
			f(i, n) {
				if (a[i] > x) {
					printf("%d\n", i + 1);
					fflush(stdout);
					a[i] = x;
					b[i] = x;
					break;
				}
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				if (b[i] < x) {
					printf("%d\n", i + 1);
					fflush(stdout);
					a[i] = x;
					b[i] = x;
					break;
				}
			}
		}
		v = true;
		f(i, n)if (b[i] < 0)v = false;
		f(i, n - 1)if (b[i] > b[i + 1])v = false;
		if (v)return 0;
	}
	return 0;
}