#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Maxl = 26;
const int mod = 1000000007;
const int Maxm = 2 * Maxn;

char tmp[Maxn];
int fac[Maxm], inv[Maxm];
int simple[Maxm];
string a, b;
int freq[Maxl], cur[Maxl];
int prec[Maxl + 1];

int C(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int Solve(const string &s)
{
	for (int i = 0; i < Maxl; i++)
		cur[i] = freq[i];
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		int has = 0;
		prec[Maxl] = 1;
		for (int j = Maxl - 1; j >= 0; j--) {
			has += cur[j];
			prec[j] = ll(prec[j + 1]) * C(has, cur[j]) % mod;
		}
		int bef = 1, lft = int(s.length()) - i - 1;
		for (int j = 0; j + 'a' < s[i]; j++) if (cur[j]) {
			cur[j]--;
			res = (res + ll(bef) * C(lft, cur[j]) % mod * prec[j + 1]) % mod;
			cur[j]++;
			bef = ll(bef) * C(lft, cur[j]) % mod;
			lft -= cur[j];
		}
		if (cur[s[i] - 'a'] > 0) cur[s[i] - 'a']--;
		else break;
	}
	return res;
}

int main()
{
	cin.getline(tmp, Maxn); a = tmp;
	cin.getline(tmp, Maxn); b = tmp;
	fac[0] = inv[0] = 1;
	simple[1] = 1;
	for (int i = 1; i < Maxm; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = ll(inv[i - 1]) * simple[i] % mod;
		if (i + 1 < Maxm)
			simple[i + 1] = (mod - ll(mod / (i + 1)) * simple[mod % (i + 1)] % mod) % mod;
	}
	for (int i = 0; i < a.length(); i++)
		freq[a[i] - 'a']++;
	int res = (Solve(b) - Solve(a) - 1 + mod) % mod;
	printf("%d\n", res);
	return 0;
}