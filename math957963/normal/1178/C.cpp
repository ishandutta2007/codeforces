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
#define MOD 998244353
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main() {
	int x, y, z;
	long long s, ans;
	scanf("%d %d", &x, &y);
	ans = 1;
	f(i, x + y)ans = (ans * 2) % MOD;

	printf("%I64d\n", ans);


	return 0;
}