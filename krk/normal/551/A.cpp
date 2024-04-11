#include <cstdio>
using namespace std;

const int Maxm = 2005;

int n;
int a[Maxm];
int freq[Maxm];
int res[Maxm];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); freq[a[i]]++;
	}
	int cur = 1;
	for (int i = Maxm - 1; i >= 0; i--) {
		res[i] = cur; cur += freq[i];
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[a[i]], i + 1 < n? ' ': '\n');
	return 0;
}