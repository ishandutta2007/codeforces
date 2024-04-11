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

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	assert(k < n);

	if (k == 1) {
		printf("! 1\n");
		return 0;
	}

	vi pos(k);
	REP(i, k) pos[i] = i+1;

	vi A(n + 1, INT_MAX);

	vi nums, values;
	// n-k+1 (<= n-1) queries:
	for (int i = 0; i <= min(k-1, n-k); i++) {
		printf("?");
		for (int x : pos) printf(" %d", x);
		printf("\n");
		fflush(stdout);

		int p, v;
		scanf("%d%d", &p, &v);
		A[p] = v;

		nums.pb(p);
		values.pb(v);

		int idx = find(all(pos), p) - pos.begin();
		pos[idx] = i + k + 1;
	}

	// nums contains n-k+1 numbers
	if (k <= n-k+1) {
		// n-k+2 queries :)
		assert(nums.size() == k);

		printf("?");
		REP(i, k) printf(" %d", nums[i]);
		printf("\n");
		fflush(stdout);

		sort(values.begin(), values.begin() + k);
		int p, v;
		scanf("%d%d", &p, &v);

		// cout << "options: " << values[0] << ", " << values[1] << endl;

		int m = 1 + find(values.begin(), values.begin() + k, v) - values.begin();
		// cout << m << endl;
		assert(1 <= m && m <= k);
		printf("! %d\n", m);
		return 0;
	}

	// do a last query on all the unknowns (k-1) and one that is known.
	vi unknown;
	for (int i=1; i <= n; i++) {
		if (A[i] == INT_MAX)
			unknown.pb(i);
	}
	assert(unknown.size() == k-1);

	// k-1 queries, total: n queries.
	int nlo = 0, nhi = 0;
	if (values[0] > values[1]) {
		swap(nums[0], nums[1]);
		swap(values[0], values[1]);
	}
	for (int j = 0; j < k-1; j++) {
		// skip j
		printf("?");
		for (int i = 0; i < k-1; i++)
			if (i != j) printf(" %d", unknown[i]);


		printf(" %d %d\n", nums[0], nums[1]);
		fflush(stdout);

		int p, v;
		scanf("%d%d", &p, &v);
		assert(p == nums[0] || p == nums[1]);
		if (p == nums[0])
			nhi++;
		else
			nlo++;
	}

	assert(nlo + nhi == k-1);
	printf("! %d\n", nlo + 1);
	return 0;
}