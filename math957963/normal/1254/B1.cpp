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
#define N 200000


int main() {
	vector<long long>b;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &x);
		if (x == 1)b.push_back(i);
	}
	ans = 100000000000000000;
	k = b.size();
	for(int i=2;i<=k;i++){
		if (k%i == 0) {
			s = 0;
			f(j, k) {
				x = j / i;
				y = x*i;
				z = (i + 1) / 2;
				y += (z - 1);
				if (j < y)s += (b[y] - b[j]);
				if (j > y)s += (b[j] - b[y]);
			}
			if (s < ans)ans = s;
		}
	}
	if (ans == 100000000000000000) {
		printf("-1\n");
		return 0;
	}
	printf("%I64d\n", ans);


	return 0;
}