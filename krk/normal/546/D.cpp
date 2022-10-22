#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 5000005;

ll C[Maxn];
int t;
int a, b;

int main()
{
	for (int i = 2; i < Maxn; i++) if (C[i] == 0) {
		ll cur = i;
		while (cur < Maxn) {
			for (int j = cur; j < Maxn; j += cur)
				C[j]++;
			cur *= i;
		}
	}
	for (int i = 2; i < Maxn; i++)
		C[i] += C[i - 1];
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%I64d\n", C[a] - C[b]);
	}
	return 0;
}