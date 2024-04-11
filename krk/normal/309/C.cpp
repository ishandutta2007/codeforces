#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 30;

int n, m;
int a[Maxn], b[Maxn];
int has[Maxm];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < Maxm; j++)
			if (a[i] & 1 << j) has[j]++;
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(b, b + m);
	int i;
	for (i = 0; i < m; i++) {
		int j = b[i];
		while (j < Maxm && !has[j]) j++;
		if (j == Maxm) break;
		for (; j > b[i]; j--) {
			has[j]--; has[j - 1] += 2;
		}
		has[b[i]]--;
	}
	printf("%d\n", i);
	return 0;
}