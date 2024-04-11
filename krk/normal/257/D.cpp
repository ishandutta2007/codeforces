#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
char res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (sum < 0) { sum += a[i]; res[i] = '+'; }
		else { sum -= a[i]; res[i] = '-'; }
	}
	if (sum < 0)
		for (int i = 0; i < n; i++) res[i] = res[i] == '+'? '-': '+';
	for (int i = 0; i < n; i++)
		printf("%c", res[i]);
	printf("\n");
	return 0;
}