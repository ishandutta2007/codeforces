#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int n;
vector <int> V;

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

void Simple(bool plus)
{
	vector <int> nV;
	for (int i = 0; i + 1 < V.size(); i++) {
		if (plus) nV.push_back((V[i] + V[i + 1]) % mod);
		else nV.push_back((V[i] - V[i + 1] + mod) % mod);
		plus = !plus;
	}
	V = nV;
}

int Solve()
{
	int n = V.size() / 2;
	int res = 0;
	for (int i = 0; i < V.size(); i += 2)
		res = (res + ll(V[i]) * C(n, i / 2)) % mod;
	return res;
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		V.push_back(a);
	}
	bool plus = true;
	while (true)
		if (V.size() % 4 == 1) { printf("%d\n", Solve()); return 0; }
		else {
			Simple(plus);
			if (V.size() % 2) plus = !plus;
		}
	return 0;
}