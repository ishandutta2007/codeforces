#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const ll MOD = 1000000007;
const int MX = 1000010;
const int MAXN = 220000;
ll fct[MAXN];
ll bfct[MAXN];
int pr[MX];
int sd[MX];
ll gg[MX];

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}

void initCnk() {
	fct[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fct[i] = (fct[i - 1] * i) % MOD;
	for (int i = 0; i < MAXN; ++i)
		bfct[i] = pw(fct[i], MOD - 2);
}

ll getCnk(int n, int k) {
	if (n < k)
		return 0;
	ll ans = (fct[n] * bfct[k]) % MOD;
	return (ans * bfct[n - k]) % MOD;
}

void initPrime() {
	for (int i = 2; i < MX; ++i) {
		if (pr[i] != 0)
			continue;
		for (ll j = (ll)i * i; j < MX; j += i) {
			if (!pr[j])
				pr[j] = i;
		}
	}
}
int n, k, q;
int ac;
int aa[120];

void init() {
	for (int i = 1; i < MX; ++i) {
		ac = 0;
		int tmp = i;
		while (tmp != 1) {
			int k = pr[tmp];
			if (k == 0) {
				aa[ac++] = tmp;
				break;
			}
			aa[ac++] = k;
			while (tmp % k == 0)
				tmp /= k;
		}
		for (int j = 0; j < (1 << ac); ++j) {
			int cc = 0;
			int tmp = i;
			for (int k = 0; k < ac; ++k)
				if ((j >> k) & 1) {
					++cc;
					tmp /= aa[k];
				}
			if (cc & 1)
				gg[i] -= tmp;
			else
				gg[i] += tmp;
		}
		if (gg[i] < 0)
			gg[i] += MOD;
		if (gg[i] >= MOD)
			gg[i] -= MOD;
	}
}

vector<int> vv;


ll add(int x) {
/*	vv.clear();
	cnt.clear();
	int tmpx = x;
	while (tmpx != 1) {
		int k = pr[tmpx];
		if (k == 0) {
			vv.push_back(k);
			cnt.push_back(1);
			break;
		}
		int cc = 0;
		vv.push_back(k);
		while (tmpx % k == 0)
			tmpx /= k, ++cc;
		cnt.push_back(cc);
	}*/
	ll sum = 0;
	vv.clear();
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			vv.push_back(i);
			if (i * i != x)
				vv.push_back(x / i);
		}
	}
	for (int i = 0; i < (int)vv.size(); ++i) {
		sum += getCnk(sd[vv[i]], k - 1) * gg[vv[i]];
		sum %= MOD;
		sd[vv[i]] += 1;
	}
	return sum;
}



int main() {
	initCnk();
	initPrime();
	init();
	scanf("%d%d%d", &n, &k, &q);
	ll pr = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		pr += add(a);
		if (pr >= MOD)
			pr -= MOD;
	}
	for (int i = 0; i < q; ++i) {
		int a;
		scanf("%d", &a);
		pr += add(a);
		if (pr >= MOD)
			pr -= MOD;
		printf("%lld\n", pr);
	}
	return 0;
}