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
#define N 400000


int main() {
	vector<long long>a;
	long long b[N];
	long long n, l, r, h,m,x;
	scanf("%I64d %I64d", &n,&h);
	f(i, n)scanf("%I64d", &b[i]);
	l = 0;
	r = n + 1;
	while (l + 1 < r) {
		m = (l + r) / 2;
		a.clear();
		f(i, m)a.push_back(b[i]);
		sort(a.begin(), a.end(),greater<long long>());
		x = 0;
		f(i, (m + 1) / 2) {
			x += a[(2 * i)];
			if (x > h)break;
		}
		if (x > h)r = m;
		else l = m;
	}
	printf("%I64d\n", l);

	return 0;
}