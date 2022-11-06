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
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d %I64d", &x,&y,&z);

	if (x < y)ans = (2 * x) + (2 * z) + 1;
	else if(x>y)ans = (2 * y) + (2 * z) + 1;
	else ans = (x + y) + (2 * z);
	printf("%I64d\n", ans);


	return 0;
}