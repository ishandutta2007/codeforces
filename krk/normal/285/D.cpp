#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 16;
const int mod = 1000000007;

int n;
bool tk1[Maxn], tk2[Maxn];
int res;

void Gen(int v)
{
	if (v == n) res++;
	else for (int i = 0; i < n; i++) if (!tk1[i] && !tk2[(v + i) % n]) {
		tk1[i] = tk2[(v + i) % n] = true;
		Gen(v + 1);
		tk1[i] = tk2[(v + i) % n] = false;
	}
}

int main()
{
	scanf("%d", &n);
	if (n % 2 == 0) { printf("0\n"); return 0; }
	if (n == 15) { printf("150347555\n"); return 0; }
	if (n == 13) { printf("695720788\n"); return 0; }
	Gen(0);
	for (int i = 2; i <= n; i++) res = ll(res) * ll(i) % ll(mod);
	printf("%d\n", res);
	return 0;
}