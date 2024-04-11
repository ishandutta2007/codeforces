#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
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
#define N 400000
 
 
int main() {
	char a[N + 1];
	char b[N + 1];
	vector<int>c;
	f(i, N + 1) {
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	int x1, x2;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	scanf("%s", a);
	y = 0;
	f(i, n) {
		if (a[i] == '(')y++;
		else y--;
	}
	if (y != 0) {
		printf("0\n");
		printf("1 1\n");
		return 0;
	}
	if (n == 2) {
		printf("1\n");
		printf("1 2\n");
		return 0;
	}
	x = -1;
	y = 0;
	z = 0;
k=0;
	f(i, n) {
		if (a[i] == '(')y++;
		else y--;
		if (y < z) {
			z = y;
			x = i;
k=1;
		}
else if(y==z)k++;

	}
	if ((k * 2) == n) {
		printf("%d\n", k);
		printf("1 1\n");
		return 0;
	}
	int xx = (x + 1) % n;
	f(i, n) {
		y = (i + xx) % n;
		b[i] = a[y];
	}
	s = -1;
	y = 0;
	x = 0;
	z = 0;
	k = 0;
	f(i, n) {
		if (b[i] == '(')y++;
		else y--;
		if (y == 2)z++;
		if (y == 1) {
			if (k < z) {
				x1 = s + 1;
				x2 = i;
				x1 = (x1 + xx + n) % n;
				x2 = (x2 + xx + n) % n;
				x1++;
				x2++;
				k = z;
			}
			z = 0;
			s = i;
		}
		if (y == 0)x++;
	}
	ans = x + k;
 
	int x3, x4;
	s = -1;
	y = 0;
	x = 0;
	z = 0;
	k = 0;
	f(i, n) {
		if (b[i] == '(')y++;
		else y--;
		if (y == 1)z++;
		if (y == 0) {
			if (k < z) {
				x3 = s + 1;
				x4 = i;
				x3 = (x3 + xx + n) % n;
				x4 = (x4 + xx + n) % n;
				x3++;
				x4++;
				k = z;
			}
			z = 0;
			s = i;
		}
	}
	if (ans < k) {
		printf("%d\n", k);
		printf("%d %d\n", x3, x4);
		return 0;
	}
	printf("%d\n", ans);
	printf("%d %d\n", x1, x2);
	   
	return 0;
}