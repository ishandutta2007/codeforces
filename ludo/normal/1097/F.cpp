#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MAXV = 7001;
const int MAXN = 1e5 + 1;

int sqf[MAXV] = {};
bitset<MAXV> A[MAXN], create[MAXV], mask[MAXV];

int main() {
	fill_n(sqf, MAXV, 1);
	for (int i = 2; i * i < MAXV; i++) {
		int j = i * i;
		for (int k = j; k < MAXV; k += j) sqf[k] = 0;
	}

	for (int i = 1; i < MAXV; i++) {
		vi divs;
		for (int j = 1; j * j <= i; j++) {
			if (i % j != 0) continue;

			divs.pb(j);
			divs.pb(i / j);
		}
		if (divs.back() * divs.back() == i) divs.pop_back();

		for (int d : divs) {
			create[i].set(d);
			if (sqf[i/d]) mask[d].set(i);
		}
	}

	int n, q;
	scanf("%d%d", &n, &q);
	while (q--) {
		int op, a, b, c;
		scanf("%d%d%d", &op, &a, &b);
		if (op == 1) A[a] = create[b];
		else if (op == 2) { scanf("%d", &c); A[a] = A[b] ^ A[c]; }
		else if (op == 3) { scanf("%d", &c); A[a] = A[b] & A[c]; }
		else if (op == 4) printf("%lu", (A[a] & mask[b]).count() & 1);
	}
	printf("\n");
	return 0;
}