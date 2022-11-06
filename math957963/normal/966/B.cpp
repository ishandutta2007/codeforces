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
	vector<pair<long long,long long> >a;
	vector<long long>b;
	vector<long long>c;
	long long n, k1, k2;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld %lld %lld", &n, &k1, &k2);
	f(i, n) {
		scanf("%lld", &x);
		a.push_back(make_pair(x, i + 1));
	}
	sort(a.begin(), a.end());
	x = n - 1;
	y = 1;
	while (x >= 0) {
		b.push_back(a[x].second);
		if (((a[x].first)*y) >= k1)break;
		x--;
		y++;
	}
	x--;
	y = 1;
	while (x >= 0) {
		c.push_back(a[x].second);
		if (((a[x].first)*y) >= k2) {
			printf("Yes\n");
			x = b.size();
			y = c.size();
			printf("%lld %lld\n", x, y);
			f(i, x - 1)printf("%lld ", b[i]);
			printf("%lld\n", b[x - 1]);
			f(i, y - 1)printf("%lld ", c[i]);
			printf("%lld\n", c[y - 1]);
          return 0;
		}
		x--;
		y++;
	}
	b.clear();
	c.clear();
	x = n - 1;
	y = 1;
	while (x >= 0) {
		c.push_back(a[x].second);
		if (((a[x].first)*y) >= k2)break;
		x--;
		y++;
	}
	x--;
	y = 1;
	while (x >= 0) {
		b.push_back(a[x].second);
		if (((a[x].first)*y) >= k1) {
			printf("Yes\n");
			x = b.size();
			y = c.size();
			printf("%lld %lld\n", x, y);
			f(i, x - 1)printf("%lld ", b[i]);
			printf("%lld\n", b[x - 1]);
			f(i, y - 1)printf("%lld ", c[i]);
			printf("%lld\n", c[y - 1]);
          return 0;
		}
		x--;
		y++;
	}

	printf("No\n");


	return 0;
}