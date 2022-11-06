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
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n-1) {
		scanf("%d %d", &x, &y);
		a[x - 1]++;
		a[y - 1]++;
	}
	f(i, n) {
		if (a[i] == 2)v = false;
	}
	if(v)printf("YES\n");
	else printf("NO\n");


	return 0;
}