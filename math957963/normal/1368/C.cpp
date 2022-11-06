#pragma GCC optimize("O3")
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
	vector<int>a;
	vector<int>b;
	int sz, n, x;
	scanf("%d", &n);
	if (n % 2 == 1) {
		a.push_back(-1);
		b.push_back(10);
		a.push_back(-1);
		b.push_back(11);
		a.push_back(0);
		b.push_back(11);
		n--;
	}
	x = 2;
	while (n > 0) {
		a.push_back(x);
		b.push_back(-1);
		a.push_back(x);
		b.push_back(1);
		a.push_back(x + 1);
		b.push_back(-1);
		a.push_back(x + 1);
		b.push_back(1);
		n -= 2;
		x += 3;
	}
	f(i, 10) {
		a.push_back(0);
		b.push_back(i);
	}
	f(i, 1000) {
		a.push_back(i);
		b.push_back(10);
	}
	f(i, 10) {
		a.push_back(1000);
		b.push_back(10 - i);
	}
	f(i, 1000) {
		a.push_back(1000 - i);
		b.push_back(0);
	}
	sz = a.size();
	printf("%d\n", sz);
	f(i, sz) {
		printf("%d %d\n", a[i], b[i]);
	}
	return 0;
}