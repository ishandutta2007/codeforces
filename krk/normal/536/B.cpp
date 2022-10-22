#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int n, m;
char p[Maxn];
int plen;
int y[Maxn];
int Z[Maxn];
int res = 1;

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s", p); plen = strlen(p);
	for (int i = 0; i < m; i++)
		scanf("%d", &y[i]);
	int l = -1, r = -1;
	for (int i = 1; i < plen; i++) {
		if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
		while (i + Z[i] < plen && p[Z[i]] == p[i + Z[i]]) Z[i]++;
		if (i + Z[i] - 1 > r) { l = i; r = i + Z[i] - 1; }
	}
	int lst = 0;
	for (int i = 0; i < m; i++) {
		if (lst < y[i])
			while (lst + 1 < y[i]) {
				res = ll(res) * 26 % mod;
				lst++;
			}
		else {
			int ind = y[i] - (lst - plen + 1);
			if (Z[ind] < lst - y[i] + 1) res = 0;
		}
		lst = y[i] + plen - 1;
	}
	while (lst + 1 <= n) {
		res = ll(res) * 26 % mod;
		lst++;
	}
	printf("%d\n", res);
	return 0;
}