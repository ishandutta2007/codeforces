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
#define N 100


int main() {
	vector<int>a;
	int x, y;
	int n;
	a.push_back(1);
	a.push_back(2);
	x = 3;
	y = 1;
	while ((x+y) <= 10000000) {
		a.push_back(x + y);
		a.push_back(x + y + 1);
		y = x - y;
		x = (2 * x) + 1;
	}
	scanf("%d", &n);
	f(i, a.size()) {
		if (n == a[i]) {
			printf("1\n");
			return 0;
		}
	}
	printf("0\n");


	return 0;
}