#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg = 37;
const int Maxn = 50005;
const int Maxl = 26;

int pw1[Maxn], pw2[Maxn];
char lin[Maxn];
int len;
bool er[Maxn];
int h1[Maxn], h2[Maxn];

int getHash(int pw[], int h[], int mod, int l, int r)
{
	int H = h[r] - (l? h[l - 1]: 0);
	if (H < 0) H += mod;
	return ll(H) * pw[len - 1 - r] % mod;
}

ii Hash(int l, int r) { return ii(getHash(pw1, h1, mod1, l, r), getHash(pw2, h2, mod2, l, r)); }

int toLeft(int a, int b)
{
	int l = 1, r = min(a, b) + 1;
	int res = 0;
	while (l <= r) {
		int m = l + r >> 1;
		if (Hash(a - m + 1, a) == Hash(b - m + 1, b)) { res = m; l = m + 1; }
		else r = m - 1;
	}
	return res;
}

int toRight(int a, int b)
{
	int l = 1, r = len - max(a, b);
	int res = 0;
	while (l <= r) {
		int m = l + r >> 1;
		if (Hash(a, a + m - 1) == Hash(b, b + m - 1)) { res = m; l = m + 1; }
		else r = m - 1;
	}
	return res;
}

bool Test(int d)
{
	for (int i = 0; i + d < len; i += d)
		if (toLeft(i, i + d) + toRight(i, i + d) - 1 >= d) 
			return true;
	return false;
}

void Erase(int d)
{
	bool rep = true;
	while (rep) {
		rep = false;
		for (int i = 0; i < len; i++) {
			h1[i] = ll(pw1[i]) * (lin[i] - 'a') % mod1;
			h2[i] = ll(pw2[i]) * (lin[i] - 'a') % mod2;
			if (i) {
				h1[i] = (h1[i - 1] + h1[i]) % mod1;
				h2[i] = (h2[i - 1] + h2[i]) % mod2;
			}
		}
		for (int i = 0; i + 2 * d <= len; i++)
			if (Hash(i, i + d - 1) == Hash(i + d, i + 2 * d - 1)) {
				int lim = i + d;
				while (i < lim) { er[i] = true; i++; }
				i--;
			}
		int nlen = 0;
		for (int i = 0; i < len; i++) 
			if (!er[i]) lin[nlen++] = lin[i];
			else { rep = true; er[i] = false; }
		len = nlen;
	}
}

int main()
{
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg % mod2;
	}
	scanf("%s", lin); len = strlen(lin);
	for (int i = 1; i <= len; i++)
		if (Test(i)) Erase(i);
	lin[len] = '\0';
	printf("%s\n", lin);
	return 0;
}