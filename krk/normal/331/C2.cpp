#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxd = 10;
const int Maxn = 1000001;

int dig[Maxn];
int best[Maxd][Maxn], reach[Maxd][Maxn];
ll n;
ll res;

int getMax(int x)
{
	int res = 0;
	while (x) {
		res = max(res, x % 10);
		x /= 10;
	}
	return res;
}

int main()
{
	for (int i = 0; i < Maxn; i++)
		dig[i] = getMax(i);
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxn; j++) {
			int k = j - max(i, dig[j]);
			if (k > 0) { best[i][j] = 1 + best[i][k]; reach[i][j] = reach[i][k]; }
			else { best[i][j] = 1; reach[i][j] = k; }
		}
	scanf("%I64d", &n);
	int cur1 = n / (Maxn - 1), cur2 = n % (Maxn - 1);
	while (cur1 > 0 || cur2 > 0) {
		res += best[dig[cur1]][cur2]; cur2 = reach[dig[cur1]][cur2];
		if (cur1 > 0 && cur2 == 0) { res++; cur2 -= dig[cur1]; }
		if (cur1 > 0 && cur2 != 0) { cur1--; cur2 += Maxn - 1; }
	}
	printf("%I64d\n", res);
	return 0;
}