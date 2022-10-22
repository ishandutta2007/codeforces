#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 400006;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int n, k;
int L[Maxn], R[Maxn];
vector <int> un;
int BIT[Maxn];
int res;

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

void Insert(int x, int val)
{
	for (int i = x; i <= un.size(); i += i & -i)
		BIT[i] += val;
}

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &L[i], &R[i]);
		un.push_back(L[i]); un.push_back(R[i] + 1);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		int lef = lower_bound(un.begin(), un.end(), L[i]) - un.begin() + 1;
		int rig = lower_bound(un.begin(), un.end(), R[i] + 1) - un.begin() + 1;
		Insert(lef, 1); Insert(rig, -1);
	}
	for (int i = 0; i + 1 < un.size(); i++) {
		int has = Get(i + 1);
		res = (res + ll(un[i + 1] - un[i]) * C(has, k)) % mod;
	}
	printf("%d\n", res);
	return 0;
}