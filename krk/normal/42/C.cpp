#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 4;

ll num[Maxn];

int main()
{
	scanf("%I64d %I64d %I64d %I64d", &num[0], &num[1], &num[2], &num[3]);
	while (num[0] + num[1] + num[2] + num[3] > 5) {
		int i;
		for (i = 0; i < Maxn; i++)
			if (num[i] % 2 == 0 && num[(i + 1) % Maxn] % 2 == 0) break;
		if (i < Maxn) { printf("/%d\n", i + 1); num[i] /= 2; num[(i + 1) % Maxn] /= 2; }
		else {
			for (i = 0; i < Maxn; i++) if (num[i] % 2 == 0) break;
			if (i < Maxn) {
				printf("+%d\n", (i + 1) % Maxn + 1); num[(i + 1) % Maxn]++; num[(i + 2) % Maxn]++;
				printf("/%d\n", i + 1); num[i] /= 2; num[(i + 1) % Maxn] /= 2;
			} else { printf("+1\n+3\n"); num[0]++; num[1]++; num[2]++; num[3]++; }
		}
	}
	if (num[0] + num[1] + num[2] + num[3] == 5) {
		int i;
		for (i = 0; i < Maxn; i++) if (num[i] == 2) break;
		printf("+%d\n", (i + 1) % Maxn + 1);
		printf("+%d\n", (i + 2) % Maxn + 1);
		printf("/%d\n", (i + 3) % Maxn + 1);
		printf("+%d\n", (i + 2) % Maxn + 1);
		printf("/%d\n", (i + 1) % Maxn + 1);
		printf("/%d\n", (i + 2) % Maxn + 1);
	}
	return 0;
}