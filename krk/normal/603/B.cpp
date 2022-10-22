#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int p, k;
bool tk[Maxn];
int res;

int toPow(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	scanf("%d %d", &p, &k);
	if (k == 0) res = p - 1;
	else {
		if (k == 1) res++;
		tk[0] = true;
		for (int i = 1; i < p; i++)
			if (!tk[i]) {
				res++;
				int num = i;
				while (!tk[num]) {
					tk[num] = true;
					num = ll(num) * k % p;
				}
			}
	}
	printf("%d\n", toPow(p, res));
	return 0;
}