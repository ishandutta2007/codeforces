#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 500005;

int n;
int a[Maxn];
ll L[Maxn], R[Maxn];
int delt[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		L[i] = L[i - 1] + a[i];
	}
	if (L[n] % 3) printf("0\n");
	else {
		ll need = L[n] / 3;
		for (int i = n; i >= 1; i--) {
			R[i] = R[i + 1] + a[i];
			delt[i] = delt[i + 1] + (R[i] == need);
		}
		for (int i = 1; i <= n; i++)
			if (L[i] == need) res += delt[i + 2];
		printf("%I64d\n", res);
	}
	return 0;
}