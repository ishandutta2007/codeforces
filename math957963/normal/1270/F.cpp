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
#define N 200100


int main() {
	vector<long long>c;
	vector<long long>b;
	char a[N];
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	n = strlen(a);
	f(kk, 200) {
		b.clear();
		s = 0;
		b.push_back(s);
		f(i, n) {
			if (a[i] == '1')s += kk;
			else s--;
			b.push_back(s);
		}
		sort(b.begin(), b.end());
		x = 1;
		f(i, n) {
			if (b[i] != b[i + 1]) {
				s = x * (x - 1);
				s = s / 2;
				ans += s;
				x = 1;
			}
			else x++;
		}
		s = x * (x - 1);
		s = s / 2;
		ans += s;
	}
	c.push_back(-1);
	f(i, n)if (a[i] == '1')c.push_back(i);
	c.push_back(n);
	k = c.size();
	for (int kk = 1; kk <= 1000; kk++) {
		if (kk + 1 < k) {
			x = 0;
			f(i, n) {
				y = c[x + kk];
				z = c[x + kk + 1];
				y = (y - i) / kk;
				z = (z - i) / kk;
				y = max(y, (long long)200);
				ans += max(z - y, (long long)0);
				if (a[i] == '1') {
					x++;
					if (x >= (k - kk - 1))break;
				}
			}
		}
	}

	printf("%I64d\n", ans);


	return 0;
}