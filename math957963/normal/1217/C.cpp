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
#define N 200010


int main() {
	int b[201000];
	char a[N + 1];
	int c[N + 1];
	f(i, N + 1)a[i] = 0;
	int n, k, t;
	int x, y, z;
	int ans;
	for (int i = 1; i < 201000; i++) {
		x = i;
		y = i;
		while (y > 0) {
			x--;
			y = y / 2;
		}
		b[x] = i;
	}
	scanf("%d", &t);
	f(tt, t) {
		scanf("%s", a);
		n = strlen(a);
		x = 0;
		f(i, n) {
			if (a[i] == '1') {
				c[i] = x;
				x = 0;
			}
			else x++;
		}
		ans = 0;
		f(i, n) {
			if (a[i] == '1') {
				x = 0;
				y = i;
				f(ii, 22) {
					x = x * 2;
					if (a[y] == '1') {
						x++;
					}
					if (x <= b[c[i]])ans++;
					y++;
					if (y >= n)break;
				}
			}
		}
		printf("%d\n", ans);
		f(i, n + 1)a[i] = 0;
}



	return 0;
}