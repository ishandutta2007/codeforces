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
	long long a[N];
	long long b[N];
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	int t, n, ans;
	long long s;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, n) {
			scanf("%lld", &a[i]);
		}
		s = 0;
		b[0] = a[0];
		f(i, n-1) {
			b[i + 1] = max(a[i + 1], b[i]);
			s = max(s, b[i + 1] - a[i + 1]);
		}
		ans = 0;
		while (s > 0) {
			ans++;
			s /= 2;
		}
		printf("%d\n", ans);
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}