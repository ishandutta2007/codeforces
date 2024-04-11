#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int pw[Maxn];
int mn[Maxn], mx[Maxn];
int mult[Maxn], multcnt[Maxn];
int sum[Maxn], sumcnt[Maxn];
string lef, rig;

int Add(int x, ll add) { return x = (x + add) % mod; }

int Sub(int x, ll sub) { return (x - sub % mod + mod) % mod; }

int Solve(const string &s)
{
	int res = 0;
	int lst = 0;
	for (int i = 1; i < s.length(); i++) {
		res = Add(res, ll(lst) * mn[i]);
		res = Add(res, mult[i]);
		lst = mx[i];
	}
	int pref = 0;
	for (int i = 0, lft = int(s.length()) - 1 - i; i < s.length(); i++, lft--) {
		pref = (10ll * pref + 4ll) % mod;
		if (s[i] == '7') {
			int a = lst;
			int b = (ll(pref) * pw[lft] + mn[lft]) % mod;
			res = Add(res, ll(a) * b);
			lst = (ll(pref) * pw[lft] + mx[lft]) % mod;
			res = Add(res, ll(pref) * pref % mod * pw[lft] % mod * pw[lft] % mod * multcnt[lft]);
			res = Add(res, 2ll * ll(pref) * pw[lft] % mod * sum[lft]);
			res = Sub(res, ll(pref) * pw[lft] % mod * mn[lft]);
			res = Sub(res, ll(pref) * pw[lft] % mod * mx[lft]);
			res = Add(res, mult[lft]);
			pref = Add(pref, 3);
		}
	}
	res = Add(res, ll(pref) * lst);
	return res;
}

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		mn[i] = (mn[i] + 4ll * ll(pw[i - 1])) % mod;
		mx[i] = (mx[i] + 7ll * ll(pw[i - 1])) % mod;
		pw[i] = 10ll * ll(pw[i - 1]) % mod;
	}
	sumcnt[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		for (int d = 4; d <= 7; d += 3) {
			mult[i] = Add(mult[i], ll(d) * d * pw[i - 1] % mod * pw[i - 1] % mod * multcnt[i - 1]);
			mult[i] = Add(mult[i], 2ll * ll(d) * pw[i - 1] % mod * sum[i - 1]);
			mult[i] = Sub(mult[i], ll(d) * pw[i - 1] % mod * mn[i - 1]);
			mult[i] = Sub(mult[i], ll(d) * pw[i - 1] % mod * mx[i - 1]);
			mult[i] = Add(mult[i], mult[i - 1]);
			multcnt[i] = Add(multcnt[i], multcnt[i - 1]);
			sum[i] = Add(sum[i], ll(d) * pw[i - 1] % mod * sumcnt[i - 1]) % mod;
			sum[i] = Add(sum[i], sum[i - 1]);
			sumcnt[i] = Add(sumcnt[i], sumcnt[i - 1]);
		}
		mn[i] = (4ll * pw[i - 1] + mn[i - 1]) % mod;
		mx[i] = (7ll * pw[i - 1] + mx[i - 1]) % mod;
		int a = (4ll * pw[i - 1] + mx[i - 1]) % mod;
		int b = (7ll * pw[i - 1] + mn[i - 1]) % mod;
		mult[i] = Add(mult[i], ll(a) * b);
		multcnt[i] = Add(multcnt[i], 1);
	}
	getline(cin, lef);
	getline(cin, rig);
	printf("%d\n", Sub(Solve(rig), Solve(lef)));
    return 0;
}