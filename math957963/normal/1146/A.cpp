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
	char a[N + 1];
	f(i, N + 1)a[i] = 0;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	x = 0;
	n = strlen(a);
	f(i, n) {
		if (a[i] == 'a')x++;
	}
	ans = min(n, (2 * x) - 1);
	printf("%d\n", ans);


	return 0;
}