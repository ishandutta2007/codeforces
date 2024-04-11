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
#define N 1000010


int main() {
	char a[N + 1];
	char b[N + 1];
	f(i, N + 1) {
		a[i] = 0;
		b[i] = 0;
	}
    int n, k, x, y;
	scanf("%s", a);
	n = strlen(a);
	k = n / 4;
	x = 0;
	y = n - 1;
	f(i, k) {
		if (a[x] == a[y])b[i] = a[x];
		else if (a[x] == a[y - 1])b[i] = a[x];
		else if (a[x + 1] == a[y])b[i] = a[x + 1];
		else if (a[x + 1] == a[y - 1])b[i] = a[x + 1];
		x += 2;
		y -= 2;
	}
	if (n % 4 == 0) {
		f(i, k)b[k + i] = b[k - i-1];
	}
	else {
		b[k] = a[x];
		f(i, k)b[k + i + 1] = b[k - i-1];
	}

	printf("%s\n", b);


	return 0;
}