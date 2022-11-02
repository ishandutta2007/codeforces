#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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

int sgn(int i, int j, int k) {
	printf("2 %d %d %d\n", i, j, k);
	fflush(stdout);
	int n;
	scanf("%d", &n);
	return n;
}

ll get_area(int i, int j, int k) {
	printf("1 %d %d %d\n", i, j, k);
	fflush(stdout);
	ll n;
	scanf("%lld", &n);
	return n;
}

int main() {
	int n;
	scanf("%d", &n);

	int ground = 1;
	int other = 2;
	for (int i = 3; i <= n; i++) {
		if (sgn(ground, other, i) < 0) {
			other = i;
		}
	}

	vector< pair<ll,int> > order;
	for (int i = 2; i <= n; i++) {
		if (i == other) continue;

		ll area = get_area(ground, other, i);
		order.eb(area, i);
	}

	sort(all(order));
	int last = order.back().y;

	vi before, after;
	for (ii pr : order) {
		if (pr.y == last || sgn(1, last, pr.y) > 0)
			before.pb(pr.y);
		else
			after.pb(pr.y);
	}

	reverse(all(before));

	printf("0 1 %d", other);
	for (int x : after)
		printf(" %d", x);
	// printf(" %d", last);
	for (int x : before)
		printf(" %d", x);
	printf("\n");
	return 0;
}