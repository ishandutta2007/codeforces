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

const ll MOD = 1e9 + 7;

int nd = 1;

vector<set<int> > vv;

set<int> go[120000];
int fl[120000];
int n, m;
ll pw2[120000];
int ad[120000];

int geto(int a, int x) {
	int z = 0;
	if (x == 0)
		z = *go[a].begin();
	else
		z = *go[a].rbegin();
	if ((int)vv[z].size() < 2)
		return 0;
	if (abs(*vv[z].begin()) == a)
		return *vv[z].rbegin();
	else
		return *vv[z].begin();
}

int getm(int a, int x) {
	int z = 0;
	if (x == 0)
		z = *go[a].begin();
	else
		z = *go[a].rbegin();
	for (int j: vv[z])
		if (abs(j) == a)
			return j;
	return 0;
}

void un(int a, int b) {
	if (a < 0)
		a = -a, b = -b;
	fl[abs(b)] = 1;
	if (ad[abs(b)]) {
		if (b > 0)
			ad[a] ^= ad[b];
		else
			nd ^= ad[-b], ad[a] ^= ad[-b];
	}
	for (int j: go[abs(b)]) {
		set<int> tmp;
		go[a].insert(j);
		for (int k: vv[j]) {
			if (k == b)
				tmp.insert(a);
			else if (k == -b)
				tmp.insert(-a);
			else
				tmp.insert(k);
		}
		vv[j] = tmp;
	}
	go[abs(b)].clear();
}

void set1(int a, int x) {
	if (a < 0)
		a = -a, x ^= 1;
	fl[a] = 1;
	if (x == 1 && ad[a])
		nd ^= 1;
	for (int j: go[a]) {
		int now = 0;
		for (int k: vv[j])
			if (k == a)
				now |= x;
			else if (k == -a)
				now |= 1 - x;
		if (now) {
			for (int k: vv[j])
				if (abs(k) != a)
					go[abs(k)].erase(j);
			nd ^= 1;
			vv[j].clear();
		}
		else {
			vv[j].erase(a);
			vv[j].erase(-a);
		}
	}
	go[a].clear();
}



int main() {
	pw2[0] = 1;
	for (int i = 1; i < 120000; ++i)
		pw2[i] = (pw2[i - 1] * 2) % MOD;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		if (k == 1) {
			int a;
			scanf("%d", &a);
			set<int> g = {a};
			vv.push_back(g);
			go[abs(a)].insert(vv.size() - 1);
		}
		else {
			int a, b;
			scanf("%d%d", &a, &b);
			set<int> g = {a, b};
			vv.push_back(g);
			go[abs(a)].insert(vv.size() - 1);
			go[abs(b)].insert(vv.size() - 1);
		}
	}
	ll ml = 1;
	ll ans = 0;
	int hv = m;
	int flend = 0;
	for (int i = 1; i <= m; ++i) {
		if (fl[i])
			continue;
		if (ad[i] == 0) {
			if ((int)go[i].size() == 0) {
				ml = (ml * 2) % MOD;
				fl[i] = 1;
				--hv;
				continue;
			}
			if ((int)go[i].size() == 1) {
				int x = geto(i, 0);
				if (x == 0) {
					ans += ml * pw2[hv - 1];
					ans %= MOD;
					flend = 1;
					break;
				}
				if (abs(x) == i) {
					nd ^= 1;
					ml = (ml * 2) % MOD;
					fl[i] = 1;
					--hv;
					continue;
				}
				ans += ml * pw2[hv - 2];
				ans %= MOD;
				hv -= 2;
				fl[i] = 1;
				ml = (ml * 2) % MOD;
				set1(x, 1);
				continue;
			}
			int x = geto(i, 0);
			int y = geto(i, 1);
			int m1 = getm(i, 0);
			int m2 = getm(i, 1);
			if (x == 0 || y == 0) {
				if (x == 0 && y == 0) {
					ml = (ml * 2) % MOD;
					--hv;
					set1(i, 0);
					continue;
				}
				else if (x == 0) {
					ans += ml * pw2[hv - 2];
					ans %= MOD;
					hv -= 2;
					set1(i, 0);
					ml = (ml * 2) % MOD;
					set1(y, 0);
					continue;
				}
				else {
					ans += ml * pw2[hv - 2];
					ans %= MOD;
					hv -= 2;
					set1(i, 0);
					ml = (ml * 2) % MOD;
					set1(x, 0);
					continue;
				}
			}
			else if (abs(x) == abs(y)) {
				if (x == y) {
					ml = (ml * 2) % MOD;
					hv -= 1;
					set1(i, 0);
				}
				else {
					ans += ml * pw2[hv - 1];
					ans %= MOD;
					flend = 1;
					break;
				}
			}
			else {
				ans += ml * pw2[hv - 2];
				ans %= MOD;
				if (m1 != m2) {
					nd ^= 1;
					if (x < 0)
						nd ^= 1, ad[-x] ^= 1;
					else
						ad[x] ^= 1;
				}
				for (int j: go[i]) {
					for (int k: vv[j])
						if (abs(k) != i)
							go[abs(k)].erase(j);
					vv[j].clear();
				}
				go[i].clear();
				set1(i, 0);
				un(x, y);
				hv -= 2;
				ml = (ml * 2) % MOD;
			}
		}
		else {
			if ((int)go[i].size() == 0) {
				ans += ml * pw2[hv - 1];
				ans %= MOD;
				flend = 1;
				break;
			}
			if ((int)go[i].size() == 1) {
				int x = geto(i, 0);
				if (x == 0) {
					if (getm(i, 0) < 0)
						nd ^= 1;
					ml = (ml * 2) % MOD;
					fl[i] = 1;
					--hv;
					continue;
				}
				if (abs(x) == i) {
					ans += ml * pw2[hv - 1];
					ans %= MOD;
					flend = 1;
					break;
				}
				ans += ml * pw2[hv - 2];
				ans %= MOD;
				hv -= 2;
				set1(i, 0);
				ml = (ml * 2) % MOD;
				set1(x, 0);
				continue;
			}
			int x = geto(i, 0);
			int y = geto(i, 1);
			int m1 = getm(i, 0);
			int m2 = getm(i, 1);
			if (x == 0 || y == 0) {
				if (x == 0 && y == 0) {
					ans += ml * pw2[hv - 1];
					ans %= MOD;
					flend = 1;
					break;
				}
				else if (x == 0) {
					ans += ml * pw2[hv - 2];
					ans %= MOD;
					hv -= 2;
					set1(i, 0);
					ml = (ml * 2) % MOD;
					set1(y, 1);
					continue;
				}
				else {
					ans += ml * pw2[hv - 2];
					ans %= MOD;
					hv -= 2;
					set1(i, 0);
					ml = (ml * 2) % MOD;
					set1(x, 1);
					continue;
				}
			}
			else if (abs(x) == abs(y)) {
				if (x != y) {
					ml = (ml * 2) % MOD;
					hv -= 1;
					set1(i, 0);
				}
				else {
					ans += ml * pw2[hv - 1];
					ans %= MOD;
					flend = 1;
					break;
				}
			}
			else {
				ans += ml * pw2[hv - 2];
				ans %= MOD;
				if (m1 > 0) {
					if (x < 0)
						nd ^= 1, ad[-x] ^= 1;
					else
						ad[x] ^= 1;
				}
				else {
					nd ^= 1;
				}
				if (m2 > 0) {
					if (y < 0)
						nd ^= 1, ad[-y] ^= 1;
					else
						ad[y] ^= 1;
				}
				else {
					nd ^= 1;
				}
				for (int j: go[i]) {
					for (int k: vv[j])
						if (abs(k) != i)
							go[abs(k)].erase(j);
					vv[j].clear();
				}
				go[i].clear();
				set1(i, 0);
				un(x, -y);
				hv -= 2;
				ml = (ml * 2) % MOD;
			}
		}
	}
	if (!flend) {
		if (nd == 0)
			ans += ml;
	}
	cout << ans % MOD << "\n";
	return 0;
}