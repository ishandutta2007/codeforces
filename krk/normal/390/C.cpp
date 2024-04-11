#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, k, w;
char s[Maxn];
int sum[Maxn], ssum[Maxn];

int main()
{
	scanf("%d %d %d", &n, &k, &w); gets(s);
	gets(s);
	for (int i = 0; i < n; i++) {
		sum[i] = (i - 1 >= 0? sum[i - 1]: 0) + (s[i] == '1');
		ssum[i] = (i - k >= 0? ssum[i - k]: 0) + (s[i] == '1');
	}
	while (w--) {
		int l, r; scanf("%d %d", &l, &r); l--; r--;
		int tot = sum[r] - (l - 1 >= 0? sum[l - 1]: 0);
		int stot = ssum[r] - (l - 1 >= 0? ssum[l - 1]: 0);
		int spl = (r - l + 1) / k;
		printf("%d\n", spl - stot + tot - stot);
	}
	return 0;
}