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
#define N 300010


int main() {
	vector<int>a;
	int b[N];
	int c[N];
	int mb[N];
	int mc[N];
	int n, k, t;
	int x, y, z;
	long long s, ans;
	bool v = true;
	bool v2 = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &k);
		a.clear();
		f(i, n) {
			scanf("%d", &x);
			a.push_back(x);
		}
		b[0] = 0;
		f(i, n) {
			if (a[i] < k)b[i + 1] = b[i] + 1;
			else b[i + 1] = b[i] - 1;
		}
		c[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] < k)c[i] = c[i + 1] + 1;
			else c[i] = c[i + 1] - 1;
		}
		mb[n] = b[n];
		for (int i = n - 1; i >= 0; i--) {
			mb[i] = min(mb[i + 1], b[i]);
		}
		mc[0] = c[0];
		f(i, n) {
			mc[i + 1] = min(mc[i], c[i + 1]);
		}
		v = false;
		f(i, n) {
			if (a[i] >= k) {
				if (i < (n - 1)) {
					if (mb[i + 2] <= b[i + 1])v = true;
				}
				if (i > 0) {
					if (mc[i - 1] <= c[i])v = true;
				}
				if (v)break;
			}
		}
		v2 = false;
		f(i, n)if (a[i] == k)v2 = true;
		if (n == 1) {
			if (a[0] == k)v = true;
			else v = false;
		}
		if (v&&v2)printf("yes\n");
		else printf("no\n");
	}

	return 0;
}