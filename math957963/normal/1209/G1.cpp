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
#define N 200100


int main() {
	int a[N];
	int r[N];
	int c[N];
	f(i, N) {
		a[i] = 0;
		r[i] = -1;
		c[i] = 0;
	}
	int sc, mc;
	int n, k, x;
	int ans;
	int rr = -1;
	ans = 0;
	scanf("%d %d", &n,&k);
	f(i, n) {
		scanf("%d", &a[i]);
		r[a[i]] = i;
		c[a[i]]++;
	}
	x = 0;
	sc = 0;
	mc = 0;
	while (x < n) {
		sc++;
		rr = max(rr, r[a[x]]);
		mc = max(mc, c[a[x]]);
		if (rr == x) {
			ans += (sc - mc);
			sc = 0;
			mc = 0;
		}
      x++;
	}


	printf("%d\n", ans);


	return 0;
}