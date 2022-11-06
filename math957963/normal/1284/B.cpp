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
	vector<long long> a[N];
	long long b[N];
	long long c[N];
	long long d[N];
	bool e[N];
	vector<long long>g;
	vector<long long>h;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &b[i]);
		f(j, b[i]) {
			scanf("%I64d", &x);
			a[i].push_back(x);
		}
	}
	f(i, n) {
		c[i] = -1;
		d[i] = 1000000000000;
		e[i] = true;
		f(j, b[i]) {
			if (d[i] < a[i][j])e[i] = false;
			c[i] = max(c[i], a[i][j]);
			d[i] = min(d[i], a[i][j]);
		}
		if (e[i]) {
			g.push_back(c[i]);
			h.push_back(d[i]);
		}
	}
	g.push_back(1000000000000);
	sort(g.begin(), g.end());
	sort(h.begin(), h.end());
	k = 0;
	s = 0;
	f(i, h.size()) {
		while (g[k] <= h[i])k++;
		s += k;
	}
	ans = n * n;
	ans -= s;
	printf("%I64d\n", ans);


	return 0;
}