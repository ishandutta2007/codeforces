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
#define N 1000010


	int main() {
		char a[N + 1];
		long long b[N];
		long long c[N];
		f(i, N + 1)a[i] = 0;
		int n;
		long long s, ans;
		bool v = true;
		ans = 0;
		scanf("%s", a);
		n = strlen(a);
		b[0] = 0;
		f(i, n-1) {
			if (a[i] == 'v'&&a[i + 1] == 'v')b[i + 1] = b[i] + 1;
			else b[i + 1] = b[i];
		}
		c[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] == 'v'&&a[i + 1] == 'v')c[i] = c[i + 1] + 1;
			else c[i] = c[i + 1];
		}
		f(i, n) {
			if (a[i] == 'o')ans += (b[i] * c[i]);
		}

		printf("%I64d\n", ans);


		return 0;
	}