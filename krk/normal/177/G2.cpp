#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxg = 27;
const int Maxn = 100005;
const int Maxm = 2 * Maxn;
const int arg = 7919;
const int Maxd = 2;

string gen[Maxg];
int pw[Maxm];
int ghash[Maxm];
ll k;
int m;
char s[Maxn];
int slen;
int chash[Maxn];
bool S[Maxn], B[Maxn];
int small, big;
int freq[Maxg];

void Mult(int a[][Maxd], int b[][Maxd])
{
	int c[Maxd][Maxd] = {};
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			for (int k = 0; k < Maxd; k++)
				c[i][j] = (c[i][j] + ll(a[i][k]) * ll(b[k][j]) % ll(mod)) % mod;
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			a[i][j] = c[i][j];
}

int F(ll n)
{
	if (n == 0) return 0;
	n--;
	int res[2][2], a[2][2];
	res[0][0] = 1; res[0][1] = 0;
	res[1][0] = 0; res[1][1] = 1;
	a[0][0] = 1; a[0][1] = 1;
	a[1][0] = 1; a[1][1] = 0;
	while (n) {
		if (n & 1ll) Mult(res, a);
		n >>= 1ll; Mult(a, a);
	}
	return res[0][0];
}

int G(ll n) { return F(n) - n % 2; }

int Hash(int h[], int a, int b) { return h[b] - (a? h[a - 1] * pw[b - a + 1]: 0); }

int Get(int k)
{
	if (freq[k] == -1)
		if (k == 0) freq[k] = slen == 1 && s[0] == 'a';
		else if (k == 1) freq[k] = slen == 1 && s[0] == 'b';
		else if (k == 2) freq[k] = slen == 2 && s[0] == 'b' && s[1] == 'a' || slen == 1;
		else {
			int res = (Get(k - 1) + Get(k - 2)) % mod;
			if (k == 2 && slen == 2 && s[0] == 'b' && s[1] == 'a') res = (res + 1) % mod;
			for (int i = 1; i < slen && i <= gen[k - 2].length(); i++) {
				int j = slen - i;
				if (j > gen[k - 1].length()) continue;
				res = (res + ((k - 1) % 2 == 0? B[i]: S[i])) % mod;
			}
			freq[k] = res;
		}
	return freq[k];
}

int Solve(ll k)
{
	if (k < Maxg) return Get(k);
	int res = ll(Get(Maxg - 1)) * ll(F(k - Maxg + 2)) % ll(mod);
	res = (res + ll(Get(Maxg - 2)) * ll(F(k - Maxg + 1)) % ll(mod)) % mod;
	res = (res + ll(big) * ll(F(k - Maxg + 1)) % ll(mod)) % mod;
	res = (res + ll(big) * ll(G(k - Maxg)) % ll(mod)) % mod;
	res = (res + ll(small) * ll(G(k - Maxg + 1)) % ll(mod)) % mod;
	return res;
}

int main()
{
	gen[0] = "a"; gen[1] = "b";
	for (int i = 2; i < Maxg; i++)
		gen[i] = gen[i - 1] + gen[i - 2];
	pw[0] = 1;
	for (int i = 1; i < Maxm; i++)
		pw[i] = arg * pw[i - 1];
	for (int i = 0; i < gen[Maxg - 1].length(); i++)
		ghash[i] = (i? ghash[i - 1]: 0) * arg + (gen[Maxg - 1][i] - 'a');
	scanf("%I64d %d", &k, &m);
	while (m--) {
		scanf("%s", s); slen = strlen(s);
		for (int i = 0; i < slen; i++)
			chash[i] = (i? chash[i - 1]: 0) * arg + (s[i] - 'a');
		small = big = 0;
		for (int i = 1; i < slen; i++) {
			S[i] = Hash(chash, slen - i, slen - 1) == Hash(ghash, 0, i - 1) && 
				   Hash(chash, 0, slen - i - 1) == Hash(ghash, gen[Maxg - 2].length() - (slen - i), gen[Maxg - 2].length() - 1);
			B[i] = Hash(chash, slen - i, slen - 1) == Hash(ghash, 0, i - 1) &&
				   Hash(chash, 0, slen - i - 1) == Hash(ghash, gen[Maxg - 1].length() - (slen - i), gen[Maxg - 1].length() - 1);
			small += S[i]; big += B[i];
		}
		fill(freq, freq + Maxg, -1);
		printf("%d\n", Solve(k - 1));
	}
	return 0;
}