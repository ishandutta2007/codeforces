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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


int main() {
	vector<long long>r[N];
	long long cc[N];
	long long xx[N];
	f(i, N) {
		cc[i] = 0;
		xx[i] = 0;
	}
	long long a[N];
	long long n, k, m, q;
	long long x, y;
	long long z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d", &n, &m);
	f(i, m) {
		scanf("%I64d %I64d", &x, &y);
		if (x > y)swap(x, y);
		x--;
		y--;
		cc[x]++;
		cc[y]++;
		xx[x]++;
		r[x].push_back(y);
	}

	f(i, n) {
		z = xx[i] * (cc[i] - xx[i]);
		ans += z;
	}
	printf("%I64d\n", ans);
	scanf("%I64d", &q);
	f(qq, q) {
		scanf("%I64d", &x);
		x--;
		z = xx[x] * (cc[x] - xx[x]);
		ans -= z;
		f(i, r[x].size()) {
			z = 2 * xx[r[x][i]];
			z++;
			z = cc[r[x][i]] - z;
			ans += z;
			r[r[x][i]].push_back(x);
			xx[r[x][i]]++;
		}
		r[x].clear();
		xx[x] = 0;
		printf("%I64d\n", ans);
	}


	return 0;
}