#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int L[Maxn], R[Maxn];
int S[Maxn], slen;
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		while (slen && a[S[slen - 1]] >= a[i]) slen--;
		L[i] = slen? S[slen - 1]: 0;
		S[slen++] = i;
	}
	slen = 0;
	for (int i = n; i >= 1; i--) {
		while (slen && a[S[slen - 1]] >= a[i]) slen--;
		R[i] = slen? S[slen - 1]: n + 1;
		S[slen++] = i;
		int diam = R[i] - L[i] - 1;
		res[diam] = max(res[diam], a[i]);
	}
	for (int i = n - 1; i > 0; i--)
		res[i] = max(res[i], res[i + 1]);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}