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
#define N 200100


int main() {
	char a[N + 1];
	char b[N + 1];
	f(i, N + 1) {
		a[i] = 0;
		b[i] = 0;
	}
	char d;
	int n, t;
	int l, r;
	bool v = true;
	bool vv;

	scanf("%d", &t);
	n = 0;
	f(tt, t) {
		scanf("%d", &n);
		scanf("%s", a);
		vv = false;
		f(q, 11) {
			l = n + 1;
			r = -1;
			f(i, n) {
				if (a[i] < ('0' + q)) {
					b[i] = '1';
					r = i;
				}
				else if (a[i] > ('0' + q)) {
					b[i] = '2';
					if (l == (n + 1))l = i;
				}
			}
			f(i, n) {
				if (a[i] == ('0' + q)) {
					if (i < l)b[i] = '2';
					else if (i > r)b[i] = '1';
				}
			}
			d = '0' - 1;
			v = true;
			f(i, n) {
				if (b[i] == 0) {
					v = false;
					break;
				}
				else if (b[i] == '1') {
					if (d > a[i]) {
						v = false;
						break;
					}
					d = a[i];
				}
			}
			if (v) {
				f(i, n) {
					if (b[i] == '2') {
						if (d > a[i]) {
							v = false;
							break;
						}
						d = a[i];
					}
				}
			}
			if (v) {
				printf("%s\n", b);
				vv = true;
				break;
			}
		}
		if (!vv) {
			printf("-\n");
		}
		f(i, n + 1) {
			a[i] = 0;
			b[i] = 0;
		}
	}

	return 0;
}