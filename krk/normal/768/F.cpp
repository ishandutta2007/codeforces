#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int f, w, h;

int Inv(int a)
{
	int res = 1;
	int p = mod - 2;
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

int Place(int places, int elements, int minheight)
{
	if (places < 0) return 0;
	if (places == 0) return elements == 0;
	if (places <= elements / minheight)
		return C(elements - places * minheight + places - 1, places - 1);
	else return 0;
}

int main() 
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%d %d %d", &f, &w, &h);
	int good = 0, tot = 0;
	for (int i = 0; i <= 100005; i++) {
		tot = (tot + ll(Place(i, f, 1)) * (Place(i - 1, w, 1) + Place(i, w, 1))) % mod;
		good = (good + ll(Place(i, f, 1)) * (Place(i - 1, w, h + 1) + Place(i, w, h + 1))) % mod;
		tot = (tot + ll(Place(i, w, 1)) * (Place(i - 1, f, 1) + Place(i, f, 1))) % mod;
		good = (good + ll(Place(i, w, h + 1)) * (Place(i - 1, f, 1) + Place(i, f, 1))) % mod;
	}
	int res = ll(good) * Inv(tot) % mod;
	printf("%d\n", res);
    return 0;
}