#include <cstdio>
using namespace std;

typedef long long ll;

int t;
int k;
ll l, r;
int p;

int Pow(int a, ll p, int mod)
{
	int res = 1;
	while (p) {
		if (p & 1ll) res = ll(res) * ll(a) % ll(mod);
		p >>= 1ll; a = ll(a) * ll(a) % ll(mod);
	}
	return res;
}

int Calc(ll x)
{
	int pw = Pow(2, x, p - 1);
	int res = Pow(k, pw, p);
	return (res - 1 + p) % p;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %I64d %I64d %d", &k, &l, &r, &p);
		if (p == 2) printf("%d\n", 1 - k % 2);
		else {
			int a, b = Calc(l);
			if (k % p == 0) a = 1;
			else if (b == 0) a = Pow(2, r - l + 1, p);
			else {
				a = Calc(r + 1);
				b = Pow(b, p - 2, p);
				a = ll(a) * ll(b) % ll(p);
			}
			if (k % 2) a = ll(a) * ll(Pow(Pow(2, r - l, p), p - 2, p)) % ll(p);
			printf("%d\n", a);
		}
	}
	return 0;
}