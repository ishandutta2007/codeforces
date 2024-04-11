#include <cstdio>
using namespace std;

const int mod = 1000000007;
const int Maxn = 1000005;
const int Maxb = 20;

int pw[Maxn];
int n;
int cnt[1 << Maxb];

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	for (int j = 0; j < Maxb; j++)
		for (int i = 0; i < 1 << Maxb; i++)
			if (i & 1 << j) cnt[i ^ 1 << j] += cnt[i];
	int res = 0;
	for (int i = 0; i < 1 << Maxb; i++) {
		int bits = 0;
		for (int j = 0; j < Maxb; j++)
			bits += bool(i & 1 << j);
		if (bits % 2) res = (res - pw[cnt[i]] + mod) % mod;
		else res = (res + pw[cnt[i]]) % mod;
	}
	printf("%d\n", res);
	return 0;
}