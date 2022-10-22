#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int n;
int a[Maxn];
int dv[Maxn], cnt[Maxn], len;
set <int> ok;
int res;

void Gen(int lvl, int has)
{
	if (lvl == len) ok.insert(has);
	else {
		int mult = 1;
		for (int i = 0; i <= cnt[lvl]; i++) {
			if (i) mult *= dv[lvl];
			Gen(lvl + 1, has * mult);
		}
	}
}

ll toPow(int a, int p)
{
	if (p == 0) return 1;
	ll tmp = toPow(a, p / 2);
	tmp = tmp * tmp % ll(mod);
	if (p % 2)
		tmp = tmp * ll(a) % ll(mod);
	return tmp;
}

int F(int b)
{
	len = 0;
	for (int i = 2; i * i <= b; i++)
		if (b % i == 0) {
			int cn = 0;
			do {
				b /= i;
				cn++;
			} while (b % i == 0);
			dv[len] = i; cnt[len] = cn; len++;
		}
	if (b > 1) { dv[len] = b; cnt[len] = 1; len++; }
	ok.clear();
	Gen(0, 1);
	vector <int> V(ok.size());
	int i = 0;
	for (set <int>::iterator it = ok.begin(); it != ok.end(); it++)
		V[i++] = n - (lower_bound(a, a + n, *it) - a);
	for (int i = 0; i + 1 < V.size(); i++)
		V[i] -= V[i + 1];
	int res1 = 1;
	for (int i = 0; i + 2 < V.size(); i++)
		res1 = ll(res1) * toPow(i + 1, V[i]) % ll(mod);
	int res2 = res1;
	for (int i = V.size() - 2; i < V.size(); i++)
		res1 = ll(res1) * toPow(i + 1, V[i]) % ll(mod);
	res2 = ll(res2) * toPow(V.size() - 1, V[V.size() - 2] + V[V.size() - 1]) % ll(mod);
	res1 -= res2;
	if (res1 < 0) res1 += mod;
	return res1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int bmax = 1; bmax <= a[n - 1]; bmax++)
		res = (res + F(bmax)) % mod;
	printf("%d\n", res);
	return 0;
}