#pragma GCC optimize("O3")
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
#define N 310000
#define pb push_back


int main() {
	vector<int>a;
	vector<int>b;
	vector<int>c;
	vector<int>d;
	vector<int>e;
	int n, t, k, cur;
	int x, y, s;
	scanf("%d", &t);
	f(tt, t) {
		a.clear();
		b.clear();
		c.clear();
		d.clear();
		e.clear();
		scanf("%d", &n);
		s = 0;
		f(i, n) {
			scanf("%d", &x);
			a.push_back(x);
			b.push_back(i + 1 - a[i]);
			s += x;
		}
		if (s%n != 0) {
			printf("-1\n");
			continue;
		}
		s /= n;
		for (int i = n - 2; i >= 1; i--) {
			b[i] = min(b[i], b[i + 1]);
		}
		cur = 1;
		k = 1;
		while (k<n) {
			if (a[0] < b[k])break;
			while (k < n) {
				if (a[0] < b[k]) {
					break;
				}
				k++;
			}
          k--;
			if (b[k] < 0) {
				c.pb(k + 1);
				d.pb(1);
				x = a[k] / (k + 1);
				e.pb(x);
              a[k]-=(x*(k+1));
			}
			c.pb(1);
			d.pb(k + 1);
			x = k + 1 - a[k];
			e.pb(x);
			c.pb(k+1);
			d.pb(1);
			e.pb(1);
			a[0] += a[k];
			a[k] = 0;
			for (int i = cur; i < k; i++) {
				c.pb(1);
				d.pb(i + 1);
				x = a[i] % (i + 1);
				x = (i + 1 - x) % (i + 1);
				e.pb(x);
				c.pb(i + 1);
				d.pb(1);
				x = (a[i] + x) / (i + 1);
				e.pb(x);
				a[0] += a[i];
				a[i] = 0;
			}
			k++;
			cur = k;
		}
		f(i, n-1) {
			if (a[i+1] > s) {
				printf("-1\n");
				continue;
			}
			c.pb(1);
			d.pb(i + 2);
			e.pb(s - a[i + 1]);
		}
		x = c.size();
		printf("%d\n", x);
		f(i, x) {
			printf("%d %d %d\n", c[i], d[i], e[i]);
		}
	}

	return 0;
}