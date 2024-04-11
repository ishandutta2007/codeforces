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
		scanf("%d %d %d", &n, &x, &y);
		f(i, x) {
			scanf("%d", &z);
			if (z == n)v = true;
		}
		f(i, y) {
			scanf("%d", &z);
			if (z == n)v = false;
		}
		if (v)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}