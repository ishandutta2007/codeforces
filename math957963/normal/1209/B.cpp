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
	char aa[N + 1];
	f(i, N + 1)aa[i] = 0;
	bool a[N];
	int b[N];
	int c[N];
	f(i, N)a[i] = false;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	scanf("%s", aa);
	f(i, n) {
		scanf("%d %d", &b[i], &c[i]);
	}
	f(i, n) {
		if (aa[i] == '1')a[i] = true;
	}
	s = 0;
	f(i, 1000) {
		s = 0;
		f(j, n) {
			if (a[j])s++;
			if ((i >= c[j]) && ((i%b[j]) == (c[j] % b[j]))) {
				if (a[j])a[j] = false;
				else a[j] = true;
			}
		}
		ans = max(ans, s);
	}

	printf("%d\n", ans);


	return 0;
}