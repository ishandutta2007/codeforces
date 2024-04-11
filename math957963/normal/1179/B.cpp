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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main() {
	int n, m, k;
	vector<int>x;
	vector<int>y;
	int xx, yy, zz;
	int s, ans;
	scanf("%d %d", &n, &m);
	if (n % 2 == 0) {
		k = n / 2;
		f(i, k) {
			f(j, m) {
				x.push_back(i + 1);
				y.push_back(j + 1);
				x.push_back(n - i);
				y.push_back(m - j);
			}
		}
	}
	else {
		k = n / 2;
		f(i, k) {
			f(j, m) {
				x.push_back(i + 1);
				y.push_back(j + 1);
				x.push_back(n - i);
				y.push_back(m - j);
			}
		}
			xx = (n + 1) / 2;
			k = m / 2;
			f(i, k) {
				x.push_back(xx);
				y.push_back(i + 1);
				x.push_back(xx);
				y.push_back(m - i);
			}
			if (m % 2 == 1) {
				yy = (m + 1) / 2;
				x.push_back(xx);
				y.push_back(yy);
			}
	}
	f(i, x.size()) {
		printf("%d %d\n", x[i], y[i]);
}


	return 0;
}