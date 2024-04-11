#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const int Maxn = 100005;
 
int n;
int a[Maxn];
ll sum;
int fac[Maxn], inv[Maxn];
map <int, int> M;
 
int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}
 
int Inv(int x) { return toPower(x, mod - 2); }
 
int C(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}
 
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		M[a[i]]++;
	}
	if (sum % n) { printf("0\n"); return 0; }
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	int pos = 0, neg = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > sum / n) pos++;
		else if (a[i] < sum / n) neg++;
	int res;
	if (pos <= 1 || neg <= 1) res = fac[n];
	else {
		res = 0;
		for (int i = 1; i <= n; i++) {
			res = (res + ll(C(i - 1, pos - 1)) * C(n - i, neg) % mod) % mod;
			res = (res + ll(C(n - i, pos - 1)) * C(i - 1, neg) % mod) % mod;
		}
		res = ll(res) * fac[pos] % mod * fac[neg] % mod * fac[n - pos - neg] % mod;
	}
	for (auto it: M)
		res = ll(res) * inv[it.second] % mod;
	printf("%d\n", res);
    return 0;
}