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
	vector<int>xx;
	vector<int>yy;
	int n, m, k;
	bool a[2000];
	a[0] = false;
	a[1] = false;
	a[2] = true;
	a[3] = true;
	for (int i = 4; i < 2000;i++) {
		a[i] = true;
		for (int j = 2; j < i; j++) {
			if (i%j == 0)a[i] = false;
		}
	}
	scanf("%d", &n);
	f(i, n - 1) {
		xx.push_back(i + 1);
		yy.push_back(i + 2);
	}
	xx.push_back(1);
	yy.push_back(n);
	m = n;
	k = n / 2;
	while (!a[m]) {
		xx.push_back(m - n + 1);
		yy.push_back(m - n + k + 1);
		m++;
	}
	printf("%d\n", m);
	f(i, m) {
		printf("%d %d\n", xx[i], yy[i]);
	}

	return 0;
}