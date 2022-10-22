#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxl = 26;
const int Maxn = 123;
const int mod = 12345;

ll n;
int c;
vector <int> neigh[Maxl];
int lcm[Maxl];
int prod;
int mods1[Maxl], mods2[Maxl];
int res;

struct matrix {
	int x[Maxn][Maxn];
	matrix(int diag = 0) {
		for (int i = 0; i < prod; i++)
			for (int j = 0; j < prod; j++)
				x[i][j] = (i == j) * diag;
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < prod; i++)
			for (int j = 0; j < prod; j++)
				for (int k = 0; k < prod; k++)
					c.x[i][j] = (c.x[i][j] + ll(x[i][k]) * ll(b.x[k][j]) % ll(mod)) % mod;
		return c;
	}
};

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void getMods(int num, int mods[])
{
	for (int i = Maxl - 1; i >= 0; i--) if (!neigh[i].empty()) {
		mods[i] = num % lcm[i]; num /= lcm[i];
	}
}

int Get(int a, int b)
{
	getMods(a, mods1); getMods(b, mods2);
	bool was = false;
	int add = 0;
	for (int i = 0; i < Maxl; i++) if (!neigh[i].empty())
		if ((mods1[i] + 1) % lcm[i] == mods2[i])
			if (mods1[i] == mods2[i]) add++;
			else if (was) return 0;
				 else was = true;
		else if (mods1[i] != mods2[i]) return 0;
	if (was) return 1;
	return add;
}

bool Valid(int mods[])
{
	for (int i = 0; i < Maxl; i++) if (!neigh[i].empty()) {
		int j = 0;
		while (j < neigh[i].size() && mods[i] % neigh[i][j]) j++;
		if (j == neigh[i].size()) return false;
	}
	return true;
}

int main()
{
	scanf("%I64d %d", &n, &c);
	while (c--) {
		char let; int mult; scanf(" %c %d", &let, &mult);
		neigh[let - 'A'].push_back(mult);
	}
	prod = 1;
	for (int i = 0; i < Maxl; i++) if (!neigh[i].empty()) {
		lcm[i] = 1;
		for (int j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j];
			lcm[i] = lcm[i] / gcd(lcm[i], u) * u;
		}
		prod *= lcm[i];
	}
	matrix r(1), a;
	for (int i = 0; i < prod; i++)
		for (int j = 0; j < prod; j++)
			a.x[i][j] = Get(j, i);
	while (n) {
		if (n & 1ll) r = r * a;
		n >>= 1ll; a = a * a;
	}
	for (int i = 0; i < prod; i++) {
		getMods(i, mods1);
		if (Valid(mods1)) res = (res + r.x[i][0]) % mod;
	}
	printf("%d\n", res);
	return 0;
}