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
int n;
	long long  x, y;
	scanf("%d", &n);
	f(i, n) {
		scanf("%I64d", &x);
		y = x % 14;
		if ((0 < y) && (y < 7)&&(x>14))printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}