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
	vector<int>b;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	s = 0;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	ans += a[0];
	b.push_back(1);
	f(i, n-1) {
		if (a[0] >= (2 * a[i + 1])) {
			ans += a[i + 1];
			b.push_back(i + 2);
		}
	}
	if (ans > (s - ans)) {
		printf("%d\n", b.size());
		f(i, b.size()) {
			printf("%d", b[i]);
			if (i < b.size() - 1)printf(" ");
			else printf("\n");
		}
	}
	else printf("0\n");


	return 0;
}