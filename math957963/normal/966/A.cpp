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
	set<int>a;
	set<int>b;
	int n, m, k, q;
	int x, y,xx,yy, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	f(i, n) {
		scanf("%d", &x);
		a.insert(x);
	}
	f(i, m) {
		scanf("%d", &x);
		b.insert(x);
	}
	a.insert(-500000000);
	a.insert(500000000);
	b.insert(-500000000);
	b.insert(500000000);
	auto itra = a.begin();
	auto itrb = b.begin();
	scanf("%d", &q);
	f(qq, q) {
		scanf("%d %d %d %d", &y, &x, &yy, &xx);
		if (y == yy) {
			printf("%d\n", abs(x - xx));
		}
		else {
			if (x > xx) {
				swap(x, xx);
				swap(y, yy);
			}
			ans = MOD;
			itra = a.lower_bound(x);
			itra--;
			z = *itra;
			s = abs(z - x) + abs(z - xx) + abs(y - yy);
			ans = min(ans, s);
			itra = a.upper_bound(xx);
			itra--;
			z = *itra;
			s = abs(z - x) + abs(z - xx) + abs(y - yy);
			ans = min(ans, s);
			itra = a.upper_bound(xx);
			z = *itra;
			s = abs(z - x) + abs(z - xx) + abs(y - yy);
			ans = min(ans, s);

			itrb = b.lower_bound(x);
			itrb--;
			z = *itrb;
			s = abs(z - x) + abs(z - xx) + ((abs(y - yy) + k - 1) / k);
			ans = min(ans, s);
			itrb = b.upper_bound(xx);
			itrb--;
			z = *itrb;
			s = abs(z - x) + abs(z - xx) + ((abs(y - yy) + k - 1) / k);
			ans = min(ans, s);
			itrb = b.upper_bound(xx);
			z = *itrb;
			s = abs(z - x) + abs(z - xx) + ((abs(y - yy) + k - 1) / k);
			ans = min(ans, s);
			printf("%d\n", ans);
		}

	}
	return 0;
}