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

const int MX = 10000010;
const int MAXN = 510000;
const ll MOD = 1000000007;

int er[MX];
vector<int> vv;
int cc[MX];
//int cc2[MX];
int gc[MX];
//int gc2[MX];
int fl[MX];
ll gg[MX];
ll pw21[MAXN];
int n;
int gli;

void run(int i, int now) {
	if (i == (int)vv.size()) {
		++cc[now];
		return;
	}
	run(i + 1, now);
	run(i + 1, now * vv[i]);
}

int run1(int i, int now) {
	if (i == (int)vv.size())
		return cc[now];
	return run1(i + 1, now) - run1(i + 1, now * vv[i]);
}

void run2(int i, int now) {
	if (i == (int)vv.size()) {
		if (now != gli) {
			gg[now] -= gg[gli];
			if (gg[now] < 0)
				gg[now] += MOD;
		}
		return;
	}
	run2(i + 1, now);
	run2(i + 1, now * vv[i]);
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i < MX; ++i) {
		if (!er[i]) {
			for (ll j = (ll)i * i; j < MX; j += i)
				if (!er[j])
					er[j] = i;
		}
	}
	for (int i = 2; i < MX; ++i) {
		if (er[i] && (fl[i / er[i]] || er[i] == er[i / er[i]] || er[i] == i / er[i]))
			fl[i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		/*for (int j = 1; j < MX; ++j)
			if (x % j == 0 && !fl[j])
				++cc2[j];
		for (int j = 1; j < MX; ++j)
			if (__gcd(j, x) == 1 && !fl[j])
				++gc2[j];*/
		vv.clear();
		while (x != 1) {
			if (!er[x])
				vv.push_back(x), x = 1;
			else
				vv.push_back(er[x]), x /= er[x];
		}
		vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
		run(0, 1);
	}
	for (int i = 2; i < MX; ++i) {
		if (!er[i]) {
			gc[i] = n - cc[i];
			continue;
		}
		if (fl[i])
			continue;
		vv.clear();
		int x = i;
		while (x != 1) {
			if (!er[x])
				vv.push_back(x), x = 1;
			else
				vv.push_back(er[x]), x /= er[x];
		}
		gc[i] = run1(0, 1);
	}
	//for (int i = 2; i < MX; ++i)
	//	assert(cc2[i] == cc[i] && gc2[i] == gc[i]);
	pw21[0] = 1;
	for (int i = 0; i < n; ++i)
		pw21[i + 1] = (pw21[i] * 2) % MOD;
	for (int i = 0; i <= n; ++i) {
		--pw21[i];
		if (pw21[i] < 0)
			pw21[i] += MOD;
	}
	for (int i = 1; i < MX; ++i)
		gg[i] = pw21[cc[i]];
	for (int i = MX - 1; i > 1; --i) {
		if (fl[i] || !er[i])
			continue;
		gli = i;
		vv.clear();
		int x = i;
		while (x != 1) {
			if (!er[x])
				vv.push_back(x), x = 1;
			else
				vv.push_back(er[x]), x /= er[x];
		}
		run2(0, 1);
	}
	ll ans = 0;
	for (int i = 2; i < MX; ++i)
		if (!fl[i]) {
			ans = (ans + gc[i] * gg[i]) % MOD;
		}
	cout << ans << "\n";
	return 0;
}