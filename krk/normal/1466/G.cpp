#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxlen = 1000005;
const int Maxn = 100005;
const int Maxl = 26;
const int mod = 1000000007;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int arg1, arg2;
int pw1[Maxlen], pw2[Maxlen];
int twopow[Maxlen];
char tmp[Maxlen + 1];
int n, q;

struct hashedString {
	string s;
	vector <ii> H;
	void Hash()
	{
		H.resize(s.length());
		ii h = ii(0, 0);
		for (int i = 0; i < s.length(); i++) {
			h.first = (ll(h.first) * arg1 + ll(s[i] - 'a' + 1)) % mod1;
			h.second = (ll(h.second) * arg2 + ll(s[i] - 'a' + 1)) % mod2;
			H[i] = h;
		}
	}
	ii Get(int l, int r)
	{
		ii res = H[r];
		if (--l >= 0) {
			res.first = (res.first - ll(H[l].first) * pw1[r - l] % mod1 + mod1) % mod1;
			res.second = (res.second - ll(H[l].second) * pw2[r - l] % mod2 + mod2) % mod2;
		}
		return res;
	}
};

hashedString s0;
string T;
hashedString A;
hashedString B;
int len[Maxn];
int add[Maxn][Maxl];
hashedString cur;

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int randomPrime(int lef, int rig)
{
	int res = uniform_int_distribution<int>(lef, rig)(rng);
	while (!Prime(res)) res++;
	return res;
}

void getA()
{
	int pnt = 0;
	for (int i = 0; i < s0.s.length(); i++)
		tmp[pnt++] = s0.s[i];
	int from = pnt, forb = pnt;
	int wh = 0;
	while (pnt < Maxlen)
		if (from == forb) {
			forb = pnt; from = 0;
			tmp[pnt++] = T[wh];
			wh = (wh + 1) % int(T.length());
		} else tmp[pnt++] = tmp[from++];
	tmp[Maxlen] = '\0';
	A.s = tmp;
	A.Hash();
}

void getB()
{
	int pnt = Maxlen - 1;
	for (int i = int(s0.s.length()) - 1; i >= 0; i--)
		tmp[pnt--] = s0.s[i];
	int from = pnt, forb = pnt;
	int wh = 0;
	while (pnt >= 0)
		if (from == forb) {
			forb = pnt; from = Maxlen - 1;
			tmp[pnt--] = T[wh];
			wh = (wh + 1) % int(T.length());
		} else tmp[pnt--] = tmp[from--];
	tmp[Maxlen] = '\0';
	B.s = tmp;
	B.Hash();
}

int main()
{
	mod1 = randomPrime(1000000000, 1500000000);
	mod2 = randomPrime(1000000000, 1500000000);
	arg1 = randomPrime(1000000, 2000000);
	arg2 = randomPrime(1000000, 2000000);
	pw1[0] = pw2[0] = twopow[0] = 1;
	for (int i = 1; i < Maxlen; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
		twopow[i] = 2ll * twopow[i - 1] % mod;
	}
	scanf("%d %d", &n, &q);
	Read(s0.s);
	s0.Hash();
	Read(T);
	getA();
	getB();
	len[0] = s0.s.length();
	for (int i = 1; i <= n; i++)
		len[i] = min(2 * Maxlen, 2 * len[i - 1] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < Maxl; j++)
			add[i][j] = 2 * add[i - 1][j] % mod;
		if (len[i] >= 2 * Maxlen)
			add[i][T[i - 1] - 'a'] = (add[i][T[i - 1] - 'a'] + 1) % mod;
	}
	while (q--) {
		int k; scanf("%d", &k);
		Read(cur.s);
		cur.Hash();
		int res = 0;
		for (int i = 0; i + cur.s.length() <= s0.s.length(); i++)
			res += cur.Get(0, cur.s.length() - 1) == s0.Get(i, i + cur.s.length() - 1);
		res = ll(res) * twopow[k] % mod;
		for (int i = 0; i < cur.s.length(); i++) {
			int let = cur.s[i] - 'a';
			int lef = i;
			int rig = int(cur.s.length()) - 1 - i;
			if ((lef == 0 || B.Get(int(B.s.length()) - lef, int(B.s.length()) - 1) == cur.Get(0, i - 1)) &&
				(rig == 0 || A.Get(0, rig - 1) == cur.Get(i + 1, int(cur.s.length()) - 1))) {
				for (int i = 1; i <= k && len[i] < 2 * Maxlen; i++) if (T[i - 1] - 'a' == let)
					if (lef <= len[i - 1] && rig <= len[i - 1])
						res = (res + twopow[k - i]) % mod;
				res = (res + add[k][let]) % mod;
			}
		}
		printf("%d\n", res);
	}
    return 0;
}