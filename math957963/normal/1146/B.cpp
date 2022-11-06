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
	char a[N + 1];
	char b[N + 1];
	char c[N + 1];
	char d[N + 1];
	f(i, N + 1) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
	}
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	x = 0;
	n = strlen(a);
	f(i, n) {
		if (a[i] == 'a')x++;
	}
	if ((n - x) % 2 == 1) {
		printf(":(\n");
		return 0;
	}
	k = (n - x) / 2;
	x = 0;
	f(i, n) {
		if (a[i] != 'a') {
			if (x < k) {
				b[x] = a[i];
			}
			else c[x - k] = a[i];
			x++;
		}
		if (x < (k + 1))d[i] = a[i];
      else if(a[i]=='a')v=false;
	}
	f(i, k)if (b[i] != c[i])v = false;
	if(v)printf("%s\n", d);
	else printf(":(\n");


	return 0;
}