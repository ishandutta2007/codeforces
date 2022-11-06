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
	char a[N + 1];
	char b[N + 1];
	f(i, N + 1) {
		a[i] = 0;
		b[i] = 0;
	}
	int n, m, k, t;
	int ans;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%s", a);
		n = strlen(a);
		scanf("%s", b);
		m = strlen(b);
		for (int i = m - 1; i >= 0; i--) {
			if (b[i] == '1') {
				k = m - i;
				break;
			}
		}
		ans = 0;
		while (true) {
			if (a[n - k - ans] == '0')ans++;
			else break;
		}
		printf("%d\n", ans);

		f(i, n + 1)a[i] = 0;
		f(i, m + 1)b[i] = 0;
	}

	return 0;
}