#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int pw[Maxn];
int m;
char str[Maxn];
int slen;
vector <vector <int> > dp;
int globalIndex;
map <int, int> ID;

int Inv(int a)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int C(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

void Calc()
{
	vector <int> cur(Maxn);
	for (int i = 0; i < slen; i++)
		cur[i] = 0;
	for (int i = slen; i < Maxn; i++) {
		cur[i] = ll(cur[i - 1]) * 26 % mod;
		cur[i] = (cur[i] + ll(C(i - 1, slen - 1)) * pw[i - slen]) % mod;
	}
	dp.push_back(cur);
}

int main()
{
	fac[0] = inv[0] = pw[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
		pw[i] = ll(25) * pw[i - 1] % mod;
	}
	scanf("%d", &m);
	scanf("%s", str); slen = strlen(str);
	Calc(); globalIndex = 0;
	ID[slen] = globalIndex;
	while (m--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			scanf("%s", str); slen = strlen(str);
			if (ID.find(slen) == ID.end()) {
				globalIndex = dp.size();
				ID[slen] = dp.size(); 
				Calc();
			} else globalIndex = ID[slen];
		} else {
			int n; scanf("%d", &n);
			printf("%d\n", dp[globalIndex][n]);
		}
	}
	return 0;
}