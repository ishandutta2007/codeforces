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
#define N 600100
long long a[N];
vector<pair<long long, long long> >e[N];
bool used[N];
long long p[N];
long long q[N];
long long r[N];

long long dfs(long long k) {
	used[k] = true;
	long long re = 1;
	f(i, e[k].size()) {
		if (!used[e[k][i].first]) {
			re += dfs(e[k][i].first);
		}
	}
	a[k] = re;
	return re;
}




int main() {
	f(i, N)a[i] = 0;
	long long n, k, t;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld", &n);
		n = 2 * n;
		f(i, n-1) {
			scanf("%lld %lld %lld", &x, &y, &z);
			e[x - 1].push_back(make_pair(y - 1, z));
			e[y - 1].push_back(make_pair(x - 1, z));
			p[i] = x - 1;
			q[i] = y - 1;
			r[i] = z;

		}
		f(i, n)used[i] = false;
		dfs(0);
		s = 0;
		ans = 0;
		f(i, n - 1) {
			x = min(a[p[i]], a[q[i]]);
			if (x % 2 == 1)s += r[i];
			y = min(x, n - x);
			ans += (y*r[i]);
		}
		f(i, n) {
			e[i].clear();
		}
		printf("%lld %lld\n", s, ans);
	}
	   	  	return 0;
}