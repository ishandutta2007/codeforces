#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int CNTQ = 0;

const int N = 15005;
const int M = 350;
struct Node {
	int l, r, val;

	Node() : l(), r(), val(-1) {}
	Node(int _l, int _r) : l(_l), r(_r), val(-1) {}
};
Node tree[(1 << 15) + 7];
int L;
void build(int n) {
	L = max(2, n);
	while(L & (L - 1)) L++;
	for (int i = 0; i < L; i++)
		tree[L + i] = Node(i, i + 1);
	for (int i = L - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void setVal(int v, int x) {
	v += L;
	tree[v].val = x;
	while(v > 1) {
		v >>= 1;
		tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
	}
}
int getMax(int v, int l, int r) {
	/*
	if (v == 1) {
		CNTQ++;
	}
	*/
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return -1;
	return max(getMax(2 * v, l, r), getMax(2 * v + 1, l, r));
}

int n;
int a[N];
int ra[N];
int dp[N][M][2];
int cc[N];
int sz;

void read() {
	/*
	n = 15000;
	for (int i = 0; i < n; i++)
		a[i] = i;
	shuffle(a, a + n, rng);
	for (int i = 0; i < n; i++)
		ra[a[i]] = i;
	*/
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		ra[a[i]] = i;
	}
	
}

int solve2() {
	build(n);
	for (int i = 0; i < n; i++)
		setVal(a[i], i);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		setVal(a[i], -1);
		sz = 0;
		int l = -1;
		while(true) {
			int p = getMax(1, l + 1, a[i]);
			if (p == -1) break;
			cc[sz++] = p;
			l = a[p];
		}
		for (int w = 1; w < M; w++) {
			if (dp[i][w][0] < N) {
				ans = max(ans, w);
				for (int it = 0; it < sz; it++) {
					int p = cc[it];
					dp[p][w + 1][0] = min(dp[p][w + 1][0], dp[i][w][0]);
				}
			}
		}
		sz = 0;
		int r = n;
		while(true) {
			int p = getMax(1, a[i] + 1, r);
			if (p == -1) break;
			cc[sz++] = p;
			r = a[p];
		}
		for (int w = 1; w < M; w++) {
			if (dp[i][w][1] > -1) {
				ans = max(ans, w);
				for (int it = 0; it < sz; it++) {
					int p = cc[it];
					dp[p][w + 1][1] = max(dp[p][w + 1][1], dp[i][w][1]);
				}
			}
		}
		for (int w = 1; w <= i && w <= ans; w++) {
			if (dp[i][w][0] < N) {
				int r = n;
				while(true) {
					int p = getMax(1, dp[i][w][0] + 1, r);
					if (p == -1) break;
					dp[p][w + 1][1] = max(dp[p][w + 1][1], a[i]);
					r = a[p];
				}
			}
			if (dp[i][w][1] > -1) {
				int l = -1;
				while(true) {
					int p = getMax(1, l + 1, dp[i][w][1]);
					if (p == -1) break;
					dp[p][w + 1][0] = min(dp[p][w + 1][0], a[i]);
					l = a[p];
				}
			}
			setVal(a[i - w], -1);
		}
		for (int w = 1; w <= i && w <= ans; w++) {
			setVal(a[i - w], i - w);
		}
	}
	return ans;
}

void solve() {
	read();
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int x = 0; x < M; x++) {
			dp[i][x][0] = N;
			dp[i][x][1] = -1;
		}
	dp[n - 1][1][0] = dp[n - 1][1][1] = a[n - 1];
	ans = max(ans, solve2());
	for (int i = 0; i < n; i++)
		for (int x = 0; x < M; x++) {
			dp[i][x][0] = N;
			dp[i][x][1] = -1;
		}
	for (int i = 0; i < n - 1; i++) {
		dp[i][2][0] = dp[i][2][1] = a[i];
	}
	ans = max(ans, solve2() - 1);
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

//	eprintf("CNTQ = %d\n", CNTQ);

	return 0;
}