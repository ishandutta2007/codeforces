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
#define N 400010






int main() {
	vector<int>a;
	int aa[N];
	int n, k;
	int x, y, z;
	int xx, yy;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &aa[i]);
	}
	k = 2;
	x = 1;
	z = 0;
	f(tt, 28) {
		s = 0;
		a.clear();
		f(i, n) {
			y = aa[i] % k;
			a.push_back(y);
		}
		sort(a.begin(), a.end());
		xx = 0;
		yy = n - 1;
		while (xx < n) {
			if (yy < 0) {
				s += (long long)(n - 1);
				xx++;
			}
			else if ((a[xx] + a[yy]) >= x) {
				yy--;
			}
			else {
				s += (long long)(n - yy - 1);
				if (yy < xx)s--;
				xx++;
			}
		}
		xx = 0;
		yy = n - 1;
		while (xx < n) {
			if (yy < 0) {
				s -= (long long)(n - 1);
				xx++;
			}
			else if ((a[xx] + a[yy]) >= k) {
				yy--;
			}
			else {
				s -= (long long)(n - yy - 1);
				if (yy < xx)s++;
				xx++;
			}
		}

		xx = 0;
		yy = n - 1;
		while (xx < n) {
			if (yy < 0) {
				s += (long long)(n - 1);
				xx++;
			}
			else if ((a[xx] + a[yy]) >= (k+x)) {
				yy--;
			}
			else {
				s += (long long)(n - yy - 1);
				if (yy < xx)s--;
				xx++;
			}
		}
		s = s / 2;
		if (s % 2 == 1)z += x;
		x = x * 2;
		k = x * 2;
	}

	printf("%d\n", z);


	return 0;
}