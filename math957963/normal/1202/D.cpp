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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


int main() {
	long long t, n, a, b, c, d, x, y;
	scanf("%I64d", &t);
	f(tt, t) {
		scanf("%I64d", &n);
		x = 0;
		while (true) {
			y = (2 * x) + 1;
			y *= x;
			y *= 2;
			if (y > n) {
				x--;
				break;
			}
          x++;
		}
		a = x;
		d = x + 1;
		if (x == 0) {
			b = n;
			c = 0;
		}
		else {
			x = (3 * a*d);
			n -= x;
			b = 0;
			c = 0;
			while (true) {
				if (n%a == 0) {
					c = n / a;
					break;
				}
				b++;
				n -= d;
			}
		}
		f(i, a)printf("1");
		printf("3");
		f(i, b)printf("1");
		printf("3");
		f(i, c)printf("7");
		printf("3");
		f(i, d)printf("7");
      		printf("\n");
	}


	return 0;
}