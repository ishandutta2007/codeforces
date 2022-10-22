#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int fac[Maxn], inv[Maxn];
int n;
int a[Maxn];
int L[Maxn], R[Maxn];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int x)
{
	return toPower(x, mod - 2);
}

int C(int n, int k)
{
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int getRes()
{
	int res = 1;
	int l = 1, r = n;
	int upp = n;
	while (R[l] < L[r])
		if (a[R[l]] > a[L[r]]) {
			int has = upp - a[R[l]];
			int need = R[l] - l;
			if (need > has) return 0;
			res = ll(res) * C(has, need) % mod;
			if (r - L[r] < has - need) return 0;
			l = R[l] + 1; r -= has - need; upp -= has + 1;
		} else {
			int has = upp - a[L[r]];
			int need = r - L[r];
			if (need > has) return 0;
			res = ll(res) * C(has, need) % mod;
			if (R[l] - l < has - need) return 0;
			l += has - need; r = L[r] - 1; upp -= has + 1;
		}
	if (R[l] == L[r])
		if (a[R[l]] == 1) res = ll(res) * C(upp - 1, R[l] - l) % mod;
		else {
			int has = upp - a[R[l]];
			int tot = 0;
			if (r - L[r] <= has)
				for (int i = 0; i < R[l] - l && i <= a[R[l]] - 2; i++)
					tot = (tot + ll(C(a[R[l]] - 2, i)) * C(has, r - L[r]) % mod) % mod;
			if (R[l] - l <= has)
				for (int i = 0; i < r - L[r] && i <= a[R[l]] - 2; i++)
					tot = (tot + ll(C(a[R[l]] - 2, i)) * C(has, R[l] - l) % mod) % mod;
			res = ll(res) * tot % mod;
		}
	else for (int i = 0; i < upp - 1; i++)
			res = res * 2 % mod;
	return res;
}

int main()
{
	fac[0] = 1; inv[0] = Inv(fac[0]);
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%d", &n);
	L[0] = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		L[i] = a[i]? i: L[i - 1];
	}
	R[n + 1] = n + 2;
	for (int i = n; i >= 1; i--)
		R[i] = a[i]? i: R[i + 1];
	printf("%d\n", getRes());
	return 0;
}