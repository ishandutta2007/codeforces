#include <cstdio>
using namespace std;

const int Maxn = 105;

int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 0; j < n; j++) {
			int b; scanf("%d", &b);
			if (b != -1) res |= b;
		}
		printf("%d%c", res, i + 1 < n? ' ': '\n');
	}
	return 0;
}