#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxl = 100005;

int m;
int a[Maxn], b[Maxn], c[Maxn];
int s[Maxl], len;
int n;
ll q[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		if (a[i] == 1) {
			if (len < Maxl) s[len++] = b[i];
		} else {
			scanf("%d", &c[i]);
			for (int j = 0; j < c[i] && len < Maxl; j++)
				for (int l = 0; l < b[i] && len < Maxl; l++)
					s[len++] = s[l];
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &q[i]); q[i]--;
	}
	int pnt = 0;
	ll clen = 0;
	for (int i = 0; i < m; i++)
		if (a[i] == 1) {
			clen++;
			while (pnt < n && q[pnt] < clen) { res[pnt] = s[q[pnt]]; pnt++; }
		} else {
			while (pnt < n && q[pnt] < clen + ll(b[i]) * c[i]) {
				res[pnt] = s[(q[pnt] - clen) % b[i]]; pnt++;
			}
			clen += ll(b[i]) * c[i];
		}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}