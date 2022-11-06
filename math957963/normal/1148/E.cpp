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
#define N 300100


int main() {
	vector<pair<long long, long long> >a;
	vector<long long>b;
	vector<long long>aa;
	vector<long long>ab;
	vector<long long>ac;
	long long n, k;
	long long x, y, z, xx, yy;
	long long s, ans;
	bool v = true;
	ans = 0;
	xx = 0;
	yy = 0;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &x);
		xx += x;
		a.push_back(make_pair(x, i));
	}
	f(i, n) {
		scanf("%I64d", &x);
		yy += x;
		b.push_back(x);
	}
	if (xx != yy) {
		printf("NO\n");
		return 0;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	x = 0;
	y = 0;
	while (x < n) {
		while (a[x].first >= b[x]) {
			if (a[x].first > b[x]) {
				printf("NO\n");
				return 0;
			}
			x++;
			if (x >= n)break;
		}
      			if (x >= n)break;
		while (a[y].first <= b[y]) {
			y++;
			if (y == n) {
				printf("NO\n");
				return 0;
			}
		}
		xx = b[x] - a[x].first;
		yy = a[y].first - b[y];
		if (xx < 0) {
			printf("NO\n");
			return 0;
		}
		if (yy < 0) {
			printf("NO\n");
			return 0;
		}
		if (xx < yy) {
			if (xx > 0) {
				aa.push_back(a[x].second + 1);
				ab.push_back(a[y].second + 1);
				ac.push_back(xx);
				a[x].first += xx;
				a[y].first -= xx;
			}
			x++;
		}
		else if (xx > yy) {
			if (yy > 0) {
				aa.push_back(a[x].second + 1);
				ab.push_back(a[y].second + 1);
				ac.push_back(yy);
				a[x].first += yy;
				a[y].first -= yy;
			}
			y++;
		}
		else {
			if (yy > 0) {
				aa.push_back(a[x].second + 1);
				ab.push_back(a[y].second + 1);
				ac.push_back(yy);
				a[x].first += yy;
				a[y].first -= yy;
			}
			x++;
			y++;
		}
	}
	printf("YES\n");
	printf("%d\n", aa.size());
	f(i, aa.size()) {
		printf("%I64d %I64d %I64d\n", aa[i], ab[i], ac[i]);
	}
	return 0;
}