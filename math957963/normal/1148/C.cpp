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
#define N 300100


int main() {
	int a[N];
	int b[N];
	f(i, N)a[i] = 0;
	vector<int>c;
	vector<int>d;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &a[i]);
		a[i]--;
		b[a[i]] = i;
	}
	k = n / 2;
	f(i, k) {
		if (b[k + i] != k + i) {
			if (b[k + i] < k) {
				c.push_back(b[k + i]);
				d.push_back(n - 1);
				a[b[k + i]] = a[n - 1];
				b[a[n - 1]] = b[k + i];
				a[n - 1] = k + i;
				b[k + i] = n - 1;
			}
		}
		if (b[k + i] != k + i) {
			c.push_back(0);
			d.push_back(b[k + i]);
			a[b[k + i]] = a[0];
			b[a[0]] = b[k + i];
			a[0] = k + i;
			b[k + i] = 0;
		}
		if (b[k + i] != k + i) {
			c.push_back(b[k + i]);
			d.push_back(k + i);
			a[b[k + i]] = a[k + i];
			b[a[k + i]] = b[k + i];
			a[k + i] = k + i;
			b[k + i] = k + i;
		}
		if (b[k - i - 1] != k - i - 1) {
			if (b[k - i - 1] >= k) {
				c.push_back(0);
				d.push_back(b[k - i - 1]);
				a[b[k - i - 1]] = a[0];
				b[a[0]] = b[k - i - 1];
				a[0] = k - i - 1;
				b[k - i - 1] = 0;
			}
		}
		if (b[k - i - 1] != k - i - 1) {
			c.push_back(b[k - i - 1]);
			d.push_back(n - 1);
			a[b[k - i - 1]] = a[n - 1];
			b[a[n - 1]] = b[k - i - 1];
			a[n - 1] = k - i - 1;
			b[k - i - 1] = n - 1;
		}
		if (b[k - i - 1] != k - i - 1) {
			c.push_back(k - i - 1);
			d.push_back(b[k - i - 1]);
			a[b[k - i - 1]] = a[k - i - 1];
			b[a[k - i - 1]] = b[k - i - 1];
			a[k - i - 1] = k - i - 1;
			b[k - i - 1] = k - i - 1;
		}
	}
	printf("%d\n", c.size());
	f(i, c.size()) {
		printf("%d %d\n", c[i] + 1, d[i] + 1);
	}


	return 0;
}