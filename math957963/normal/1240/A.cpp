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
	int t;
	vector<long long> a;
	vector<long long>b;
	int n;
	long long aa, bb;
	int l, r, m;
	int xx, yy;
	long long x, y, z;
	long long s, k;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		a.clear();
		f(i, n) {
			scanf("%I64d", &x);
			x /= 100;
			a.push_back(x);
		}
		sort(a.begin(), a.end(), greater<long long>());
		scanf("%I64d %d", &aa, &xx);
		scanf("%I64d %d", &bb, &yy);
		scanf("%I64d", &k);
		b.clear();
		f(i, n) {
			x = 0;
			if ((i + 1) % xx == 0)x += aa;
			if ((i + 1) % yy == 0)x += bb;
			b.push_back(x);
		}
		sort(b.begin(), b.end(), greater<long long>());
		s = 0;
		f(i, n) {
			x = a[i] * b[i];
			s += x;
		}
		if (s < k)printf("-1\n");
		else {
			l = 0;
			r = n;
			while (l + 1 < r) {
				m = (l + r) / 2;
				b.clear();
				f(i, m) {
					x = 0;
					if ((i + 1) % xx == 0)x += aa;
					if ((i + 1) % yy == 0)x += bb;
					b.push_back(x);
				}
				sort(b.begin(), b.end(), greater<long long>());
				s = 0;
				f(i, m) {
					x = a[i] * b[i];
					s += x;
				}
				if (s < k)l = m;
				else r = m;
			}
			printf("%d\n", r);
		}

	}

	return 0;
}