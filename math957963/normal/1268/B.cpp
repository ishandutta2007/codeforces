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
	int n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	s = 0;
	f(i, n) {
		scanf("%I64d", &x);
		ans += x;
		if (x % 2 == 1) {
			if (i % 2 == 0)s++;
			else s--;
		}
	}
	s = abs(s);
	ans = (ans - s) / 2;
	printf("%I64d\n", ans);
	return 0;
}