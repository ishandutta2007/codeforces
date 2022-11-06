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
	int n, x, k;
	vector<int>a;
	vector<int>b;
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("NO\n");
		return 0;
	}
	k = n;
	n = n / 2;
	f(i, n) {
		x = (4 * i);
		x++;
		a.push_back(x);
		x++;
		b.push_back(x);
		x++;
		b.push_back(x);
		x++;
		a.push_back(x);
	}
	k = 2 * k;
	k--;
	a.push_back(k);
	k++;
	b.push_back(k);
	printf("YES\n");
	f(i, a.size()) {
		printf("%d ", a[i]);
}
	f(i, b.size()) {
		printf("%d", b[i]);
		if (i < (b.size() - 1))printf(" ");
		else printf("\n");
	}


	return 0;
}