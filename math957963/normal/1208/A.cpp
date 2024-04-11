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
	int t;
	int x, y, z;
	int s, ans;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d %d", &x, &y, &z);
		if (z % 3 == 0)ans = x;
		else if (z % 3 == 1)ans = y;
		else ans = (x^y);
		printf("%d\n", ans);
	}


	return 0;
}