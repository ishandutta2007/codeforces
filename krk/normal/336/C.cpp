#include <cstdio>
#include <set>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
set <int> S;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int i;
	for (i = 30; i >= 0; i--) {
		S.clear();
		int res = (1 << i) - 1;
		for (int j = 0; j < n; j++)
			if (a[j] & 1 << i) { S.insert(a[j]); res &= a[j]; }
		if (!S.empty() && res == 0) break;
	}
	if (i < 0) {
		S.clear();
		for (int j = 0; j < n; j++)
			S.insert(a[j]);
	}
	printf("%d\n", S.size());
	for (set <int>::iterator it = S.begin(); it != S.end(); it++) {
		if (it != S.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n");
	return 0;
}