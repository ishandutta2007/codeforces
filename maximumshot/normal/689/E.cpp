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
#include <complex>

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

int sum(int a, int b) {
	return (a + b) % mod;
}

int mul(int a, int b) {
	return (1ll * a * b) % mod;
}

int binpow(int n, int p) {
	if(p == 0) return 1;
	int q = binpow(n, p / 2);
	q = mul(q, q);
	if(p % 2) q = mul(q, n);
	return q;
}

int del(int a, int b) {
	return mul(a, binpow(b, mod - 2));
}

const int N = 200200;

int fact[N], rfact[N];

int C(int n, int k) {
	if(n < k) return 0;
	else return mul(fact[n], mul(rfact[n - k], rfact[k]));
}

bool solve() {

	fact[0] = 1;
	for(int i = 1;i < N;i++) fact[i] = mul(fact[i - 1], i);
	for(int i = 0;i < N;i++) rfact[i] = binpow(fact[i], mod - 2);
	
	int n, k;

	scanf("%d %d", &n, &k);

	vec< pii > seg(n);
	vec< int > crd;

	for(int i = 0;i < n;i++) {
		scanf("%d %d", &seg[i].first, &seg[i].second);
		crd.push_back(seg[i].first);
		crd.push_back(seg[i].second);
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());

	int sz = (int)crd.size();

	vec< int > inc(sz), dec(sz);

	for(int pos, i = 0;i < n;i++) {
		pos = lower_bound(ALL(crd), seg[i].first) - crd.begin();
		inc[pos]++;
		pos = lower_bound(ALL(crd), seg[i].second) - crd.begin();
		dec[pos]++;
	}

	//cout << "ok\n";

	int res = 0;

	/*for(int x : crd) cout << x << " ";
	cout << "\n";
	for(int x : inc) cout << x << " ";
	cout << "\n";
	for(int x : dec) cout << x << " ";
	cout << "\n";*/

	for(int cur = 0, i = 0;i < sz;i++) {
		cur += inc[i];
		res = sum(res, C(cur, k));
		cur -= dec[i];
		if(i + 1 < sz) {
 			int L, R;
			L = crd[i] + 1;
			R = crd[i + 1] - 1;
			if(L <= R) {
				res = sum(res, mul(R - L + 1, C(cur, k)));
			}
		}
	}

	printf("%d\n", res);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}