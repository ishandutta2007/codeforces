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
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		v = true;
		f(i, n) {
			scanf("%d", &a[i]);
		}
		f(i, n-1) {
			if (a[i] + 1 < a[i + 1])v = false;
		}
		if (v)printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}