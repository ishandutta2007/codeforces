#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, l, r[1000201];
long long m, a[1000201];
bool b[1000201];
const int P = 1000009;
struct node {
	long long v;
	int c;
	node *next;
} *first[P + 1000], c[1000201];

long long find(int base, long long v) {
}

long long read() {
	long long cnt = 0;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		cnt = cnt * 10 + ch - '0';
	return cnt;
}

char str[1111];

int main() {
	scanf("%d%lld\n", &n, &m);
	a[1] = 0;
	for (int i = 2; i <= n; i++) {
		gets(str);

		int x = 0; long long y = 0;
		int len = strlen(str); int c = 0;
		for (int j = 0; j < len; j++)
			if (str[j] == ' ')
				c = 1;
			else
				if (str[j] >= '0' && str[j] <= '9')
					if (!c)
						x = x * 10 + str[j] - '0';
					else
						y = y * 10 + str[j] - '0';
		//int x = int(read()); long long y = read();
		//scanf("%d%lld", &x, &y);
		a[i] = a[x] ^ y;
	}
	long long ans = 0; 
	memset(b, false, sizeof(b));
	memset(r, 255, sizeof(r));
	for (int i = 61; i >= 0; i--) {
		l = 0;
		memset(first, 0, sizeof(first));
		long long res = 0, s = ans >> i;
		for (int j = 1; j <= n && res < m; j++) {
			//if (r[j] == -1) {
				bool ok = true;
				long long base = a[j] >> i;
				int W = base % P;
				for (node *x = first[W]; x && ok; x = x->next)
					if (x->v == base)
						x->c++, ok = false;
				if (ok) {
					c[++l].v = base; c[l].c = 1;
					c[l].next = first[W];
					first[W] = &c[l];
				}
				long long k = base ^ s;
				for (node *x = first[k % P]; x; x = x->next)
					if (x->v == k) {
						res += 2 * x->c;
						break;
					}
				if (k == base)
					--res;
			}
		if (res < m) {
			m -= res, ans += 1LL << i;
		}
	}
	printf("%lld\n", ans);
}