#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 500005;

int n;
int a[Maxn];
bool tk[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0, j; i < n; i = j) {
		j = i + 1;
		if (j < n && a[i] == a[j]) {
			tk[i] = true;
			while (j < n && a[i] == a[j]) {
				tk[j] = true; j++;
			}
		}
	}
	tk[0] = tk[n - 1] = true;
	int cnt = 0;
	for (int i = 0, j; i < n; i = j)
		if (tk[i]) j = i + 1;
		else {
			j = i;
			while (j < n && !tk[j]) j++;
			int cnt = j - i;
			res = max(res, (cnt + 1) / 2);
			if (cnt % 2)
				for (int l = i; l < j; l++)
					a[l] = a[i - 1];
			else {
				for (int l = i; l < i + cnt / 2; l++)
					a[l] = a[i - 1];
				for (int l = i + cnt / 2; l < j; l++)
					a[l] = a[j];
			}
		}
	printf("%d\n", res);
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	return 0;
}