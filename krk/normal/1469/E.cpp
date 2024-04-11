#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int arg1, arg2;
int pw1[Maxn], pw2[Maxn]; 
int q;
int k, n;
char str[Maxn];
set <ii> H;
char res[Maxn];

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

bool Solve(int lvl, ii h)
{
	if (lvl >= k)
		return H.find(h) == H.end();
	else {
		res[lvl] = '0';
		h.first = (ll(h.first) * arg1 + 1) % mod1;
		h.second = (ll(h.second) * arg2 + 1) % mod2;
		if (Solve(lvl + 1, h)) return true;
		res[lvl] = '1';
		h.first = (h.first + 1) % mod1;
		h.second = (h.second + 1) % mod2;
		return Solve(lvl + 1, h);
	}
}

int main()
{
	mod1 = uniform_int_distribution<int>(1000000000, 1100000000)(rng);
	mod2 = uniform_int_distribution<int>(1000000000, 1100000000)(rng);
	arg1 = uniform_int_distribution<int>(10000000, 11000000)(rng);
	arg2 = uniform_int_distribution<int>(10000000, 11000000)(rng);
	while (!Prime(mod1)) mod1++;
	while (!Prime(mod2)) mod2++;
	while (!Prime(arg1)) arg1++;
	while (!Prime(arg2)) arg2++;
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &n, &k);
		scanf("%s", str);
		ii h = ii(0, 0);
		for (int i = 0; i < k - 1; i++) {
			str[i] = str[i] == '0'? '1': '0';
			h.first = (ll(h.first) * arg1 + ll(str[i] - '0' + 1)) % mod1;
			h.second = (ll(h.second) * arg2 + ll(str[i] - '0' + 1)) % mod2;
		}
		H.clear();
		for (int i = k - 1; i < n; i++) {
			str[i] = str[i] == '0'? '1': '0';
			h.first = (ll(h.first) * arg1 + ll(str[i] - '0' + 1)) % mod1;
			h.second = (ll(h.second) * arg2 + ll(str[i] - '0' + 1)) % mod2;
			H.insert(h);
			h.first = (h.first - ll(str[i - (k - 1)] - '0' + 1) * pw1[k - 1] % mod1 + mod1) % mod1;
			h.second = (h.second - ll(str[i - (k - 1)] - '0' + 1) * pw2[k - 1] % mod2 + mod2) % mod2;
		}
		int fil = max(0, k - 25);
		if (fil) fill(res, res + fil, '0');
		ii my = ii(0, 0);
		for (int i = 0; i < fil; i++) {
			my.first = (ll(my.first) * arg1 + 1) % mod1;
			my.second = (ll(my.second) * arg2 + 1) % mod2;
		}
		if (Solve(fil, my)) {
			printf("YES\n");
			res[k] = '\0';
			printf("%s\n", res);
		} else printf("NO\n");
	}
    return 0;
}