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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

const int SQRT = 330;
const int MAXS = 1 << 22;

bool solve() {
		
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	vec< int > a(n + 1);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
	}

	vec< pair< pii, int > > q(m);
	vec< ll > ans(m);

	for(int l, r, i = 0;i < m;i++) {
		scanf("%d %d", &l, &r);
		q[i] = mp(mp(l - 1, r), i);
	}

	sort(ALL(q), [](const pair< pii, int > & p1, const pair< pii, int > & p2) {
		if(p1.first.first / SQRT != p2.first.first / SQRT)
			return p1.first.first / SQRT < p2.first.first / SQRT;
		else 
			return p1.first.second > p2.first.second;
	});

	ll value = 0;
	int ql = 0, qr = -1;

	vec< int > c(MAXS);

	for(int i = 0;i < m;i++) {
		int l, r, id;
		tie(l, r) = q[i].first;
		id = q[i].second;
		while(qr < r) {
			int x = a[qr + 1]; 
			value += c[x ^ k];
			c[x]++;
			qr++;
		}
		while(ql > l) {
			int x = a[ql - 1];
			value += c[x ^ k];
			c[x]++;
			ql--;
		}
		while(qr > r) {
			int x = a[qr];
			c[x]--;
			value -= c[x ^ k];
			qr--;
		}
		while(ql < l) {
			int x = a[ql];
			c[x]--;
			value -= c[x ^ k];
			ql++;
		}
		ans[id] = value;
	}

	for(int i = 0;i < m;i++) printf("%I64d\n", ans[i]);

	return true;
}


int main() {

	//while(solve());
	solve();

	return 0;
}