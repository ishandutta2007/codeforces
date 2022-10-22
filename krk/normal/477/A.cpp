#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int inv2 = 500000004;

int a, b;
int res;

int main()
{
	scanf("%d %d", &a, &b);
	if (b == 1) { printf("0\n"); return 0; }
	int c1 = b;
	int c2 = b - 1;
	int c3 = a;
	int c4 = (2 + b + ll(a) * b) % mod;
	res = c1;
	res = ll(res) * c2 % mod;
	res = ll(res) * c3 % mod;
	res = ll(res) * c4 % mod;
	res = ll(res) * inv2 % mod;
	res = ll(res) * inv2 % mod;
	printf("%d\n", res);
	return 0;
}