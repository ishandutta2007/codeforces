#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

char s[Maxn];
int slen;
int k;
int alen;
int res;

int Pow1(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * ll(a) % ll(mod);
		p >>= 1; a = ll(a) * ll(a) % ll(mod);
	}
	return res;
}

int Pow2(int a, int p, int &res)
{
	if (p == 0) { res = 1; return 0; }
	int sum = Pow2(a, p / 2, res);
	sum = ll(1 + res) * ll(sum) % ll(mod); res = ll(res) * ll(res) % ll(mod);
	if (p % 2) { sum = (sum + res) % mod; res = ll(res) * ll(a) % ll(mod); }
	return sum;
}

int main()
{
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &k);
	alen = Pow1(2, slen);
	int tmp;
	for (int i = 0; i < slen; i++)
		if (s[i] == '0' || s[i] == '5') res = (res + ll(Pow1(2, i)) * ll(Pow2(alen, k, tmp)) % ll(mod)) % mod;
	printf("%d\n", res);
	return 0;
}