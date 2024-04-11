#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int n, k;
int fac[Maxn], inv[Maxn];
map <int, int> L;
int lft;
int ways[Maxn];
int res;

void gcd(int a, int &x, int b, int &y)
{
	if (!a) { x = 0; y = 1; }
	else {
		int xx, yy; gcd(b % a, xx, a, yy);
		x = yy - b / a * xx; y = xx;
	}
}

int getInv(int a)
{
	int x, y;
	gcd(a, x, mod, y);
	if (x < 0) x += mod;
	return x;
}

bool Lucky(int x)
{
	while (x) {
		if (x % 10 != 4 && x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

int C(int n, int k) { return ll(fac[n]) * ll(inv[k]) % ll(mod) * ll(inv[n - k]) % ll(mod); }

int main()
{
	scanf("%d %d", &n, &k);
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = ll(fac[i - 1]) * ll(i) % ll(mod);
		inv[i] = getInv(fac[i]);
	}
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (Lucky(a)) L[a]++;
		else lft++;
	}
	ways[0] = 1;
	for (map <int, int>::iterator it = L.begin(); it != L.end(); it++)
		for (int i = k; i >= 1; i--)
			ways[i] = (ways[i] + ll(ways[i - 1]) * ll(it->second) % ll(mod)) % mod;
	for (int i = max(0, k - lft); i <= k; i++) {
		res = (res + ll(ways[i]) * ll(C(lft, k - i)) % ll(mod)) % mod;
	}
	printf("%d\n", res);
	return 0;
}