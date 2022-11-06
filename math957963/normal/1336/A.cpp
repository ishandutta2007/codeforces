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
#define N 200010
vector<long long>e[N];
long long a[N];
long long d[N];
bool used[N];

long long dfs(long long k, long long dd) {
	used[k] = true;
	d[k] = dd;
	long long re = 1;
	long long sz = e[k].size();
	f(i, sz) {
		if (!used[e[k][i]])re += dfs(e[k][i], dd + 1);
	}
	a[k] = re;
	return re;
 }


int main() {
	vector<long long>b;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld %lld", &n, &k);
	f(i, n-1) {
		scanf("%lld %lld", &x, &y);
		e[x - 1].push_back(y - 1);
		e[y - 1].push_back(x - 1);
	}
	f(i, n)used[i] = false;
	dfs(0, 0);
	f(i, n)b.push_back(d[i] - a[i] + 1);
	sort(b.begin(), b.end(), greater<long long>());
	f(i, k)ans += b[i];
	printf("%lld\n", ans);
	return 0;
}