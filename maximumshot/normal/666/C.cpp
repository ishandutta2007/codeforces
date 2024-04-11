#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const int mod = inf + 7;

int binpow(int n, int p) {
	if(p == 0) return 1;
	int q = binpow(n, p / 2);
	q = (1ll * q * q) % mod;
	if(p % 2) q = (1ll * q * n) % mod;
	return q;
}

const int NMAX = 100100;

int fact[NMAX];
int rfact[NMAX];
int p25[NMAX];
int p26[NMAX];
int res[NMAX];
vec< pii > que[NMAX];

int C(int n, int k) {
	if(n < k) return 0;
	int res = fact[n];
	res = (1ll * res * rfact[k]) % mod;
	res = (1ll * res * rfact[n - k]) % mod;
	return res;
}

bool solve() {

	fact[0] = 1;
	rfact[0] = binpow(fact[0], mod - 2);
	p25[0] = 1;
	p26[0] = 1;

	for(int i = 1;i < NMAX;i++) {
		fact[i] = (1ll * fact[i - 1] * i) % mod;
		rfact[i] = binpow(fact[i], mod - 2);
		p25[i] = (p25[i - 1] * 25ll) % mod;
		p26[i] = (p26[i - 1] * 26ll) % mod;
	}

	int m, len;

	scanf("%d", &m);

	char buff[NMAX];

	scanf("%s", &buff);
	len = strlen(buff);

	int cur = 0;

	for(int ty, n, i = 0;i < m;i++) {
		scanf("%d", &ty);
		if(ty == 1) {
			scanf("%s", &buff);
			len = strlen(buff);
		}else {
			scanf("%d", &n);
			que[len].push_back(mp(n, cur++));
		}
	}

	for(int n, id, len = 1;len < NMAX;len++) {
		if(que[len].empty()) continue;
		int mx = max_element(ALL(que[len]))->first;
		vec< int > dp(mx + 1);
		if(len <= mx) dp[len] = 1;
		for(int j = len + 1;j <= mx;j++) {
			dp[j] = (dp[j - 1] * 26ll % mod + 1ll * C(j - 1, len - 1) * p25[j - len] % mod) % mod;
		}
		for(auto it : que[len]) {
			n = it.first;
			id = it.second;
			res[id] = dp[n];
		}
	}

	for(int i = 0;i < cur;i++) printf("%d ", res[i]);
	printf("\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}