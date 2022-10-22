#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int m;
int b[Maxn];
int res;

void Read(int &n, int a[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

int main()
{
	Read(n, a); Read(m, b);
	sort(a, a + n); sort(b, b + m);
	int cur = 0;
	for (int j = 0; j < m && cur < n; j++) {
		while (cur < n && b[j] - a[cur] > 1) cur++;
		if (cur == n) continue;
		if (abs(b[j] - a[cur]) <= 1) { res++; cur++; }
	}
	printf("%d\n", res);
	return 0;
}