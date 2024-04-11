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
#define N 200010


int main() {
	char a[N];
	char b[N];
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &k);
	scanf("%s", a);
	f(i, n) {
		x = i % k;
		b[i] = a[x];
	}
	v = true;
	f(i, n) {
		if (a[i] > b[i]) {
			v = false;
			break;
		}
		else if (a[i] < b[i]) {
			break;
		}
	}
	if (!v) {
		for (int i = k - 1; i >= 0; i--) {
			if (b[i] != '9') {
				b[i]++;
				break;
			}
			else b[i] = '0';
		}
		f(i, n) {
			x = i % k;
			b[i] = b[x];
		}
	}
	printf("%d\n", n);
	printf("%s\n", b);


	return 0;
}