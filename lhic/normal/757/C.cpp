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
#include <ctime>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

const ll M1 = 1e9 + 7;
const ll M2 = 1e9 + 9;
ll P = 1e6 + 3;
const ll MOD = 1e9 + 7;
const int MXM = 1200000;

struct hsh {
	ll a, b;
	hsh() {
		a = b = 0;
	}
	hsh(ll x) {
		a = x % M1;
		b = x % M2;
	}
	hsh(ll A, ll B) {
		a = A % M1;
		b = B % M2;
	}
	hsh operator*(hsh x) {
		return hsh(a * x.a, b * x.b);
	}
	hsh operator+(hsh x) {
		return hsh(a + x.a, b + x.b);
	}
	ll get() {
		return a * M2 + b;
	}
};

map<int, int> mm;
hsh hs[MXM];
map<ll, int> mm2;
ll fc[MXM];
hsh pw[MXM];
int n;
ll m;

int main() {
	srand(time(NULL));
	P = max(1000003, (int)(rand() % 100000000));
	scanf("%d%lld", &n, &m);
	fc[0] = 1;
	for (int i = 1; i <= m; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	pw[0] = 1ll;
	for (int i = 1; i <= n; ++i)
		pw[i] = pw[i - 1] * P;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		mm.clear();
		for (int j = 0; j < k; ++j) {
			int a;
			scanf("%d", &a);
			++mm[a - 1];
		}
		for (auto j: mm)
			hs[j.first] = hs[j.first] + pw[i] * j.second;
	}
	for (int i = 0; i < m; ++i) {
		++mm2[hs[i].get()];
	}
	ll ans = 1;
	for (auto j: mm2)
		ans = (ans * fc[j.second]) % MOD;
	cout << ans << "\n";
	return 0;
}