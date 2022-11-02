#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

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

const int LGN = 18;
const int maxn = 1 << LGN;
const int INF = 1e9;

struct SegmentTree {
	int dpmax[2 * maxn], dpmin[2 * maxn];

	SegmentTree() {
		fill_n(dpmax, 2 * maxn, -INF);
		fill_n(dpmin, 2 * maxn, +INF);
	}

	void update(int i, int vmax, int vmin) {
		dpmax[i + maxn] = vmax;
		dpmin[i + maxn] = vmin;
	}

	void build_tree() {
		for (int i = maxn; --i > 0; ) {
			dpmax[i] = max(dpmax[2*i], dpmax[2*i+1]);
			dpmin[i] = min(dpmin[2*i], dpmin[2*i+1]);
		}
	}

	int qmax(int a, int b) {
		int ra = -INF, rb = -INF;
		for (a += maxn, b += maxn; a < b; a/=2, b/=2) {
			if (a & 1) ra = max(ra, dpmax[a++]);
			if (b & 1) rb = max(rb, dpmax[--b]);
		}
		return max(ra, rb); }
	int qmin(int a, int b) {
		int ra = INF, rb = INF;
		for (a += maxn, b += maxn; a < b; a/=2, b/=2) {
			if (a & 1) ra = min(ra, dpmin[a++]);
			if (b & 1) rb = min(rb, dpmin[--b]);
		}
		return min(ra, rb); }
};

// waiting 2^i days.
SegmentTree trees[LGN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vi A(n + n);
	REP(i, n) cin >> A[i];

	// repeat elements
	REP(i, n) A[i+n] = A[i];
	int n2 = n + n;

	for (int i = 0; i < n2; i++) {
		trees[0].update(i, i + A[i], i - A[i]);
	}
	trees[0].build_tree();

	for (int i = 1; i < LGN; i++) {
		for (int j = 0; j < n2; j++) {
			int rhs = min(n2 - 1, trees[i-1].dpmax[j + maxn]);
			int lhs = max(0, trees[i-1].dpmin[j + maxn]);

			assert(lhs <= rhs);

			trees[i].update(j,
				trees[i-1].qmax(lhs, rhs + 1),
				trees[i-1].qmin(lhs, rhs + 1));
		}
		trees[i].build_tree();
	}

	// now do queries
	for (int i = 0; i < n; i++) {
		// do a binary search on number of days needed
		int i2 = i + n + 1;

		int il = i, ir = i2 - 1;

		int answer = 0;
		int lastMAX = LGN;// lgn;

		while (lastMAX > 0) {
			assert(i <= il && il < ir && ir <= i + n);

			int kd = lastMAX - 1;
			int lhs, rhs;
			while (kd >= 0) {
				lhs = max(trees[kd].qmax(i, il + 1), trees[kd].qmax(ir, i2)-n);
				rhs = min(trees[kd].qmin(i, il + 1)+n, trees[kd].qmin(ir, i2));
				if (lhs < rhs - 1) break;
				// too much days.
				kd--;
			}
			if (kd < 0) break;

			assert(~answer & (1 << kd));
			answer |= 1 << kd;
			lastMAX = kd;
			il = lhs;
			ir = rhs;
			// lhs < rhs - 1
		}
		if (il + 1 < ir)
			answer++; // we need one more day and we are done.

		// printf("%d\n", answer);
		printf("%d ", answer);

		// now DPMAX[kd][0][ir] < DPMIN[kd][0][il] - 1
		// which means we need more days to fulfill this stuff.
	}
	printf("\n");

	return 0;
}