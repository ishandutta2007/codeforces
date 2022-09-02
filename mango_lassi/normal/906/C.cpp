#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = (int)1e9 + 7;
const int N = 22;
pair<int, pair<int, int>> dp[1<<N];
int conns[N];

template<class T>
void applyMin(T& a, T b) {
	a = min(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a] |= 1 << b;
		conns[b] |= 1 << a;
	}

	// Is it optimal to always pick someone who has been in a query picked so far?
	// When does the order of queries matter?

	// Q[a], Q[b] -> edge between x and y, if
	//	1. edge originally existed
	//	2. both x and y are neighbours of a
	//	3. both x and y are neighbours of b
	//	4. a, b are neighbours, x is a neighbour of a and y is a neighbour of b, or vice versa
	// -> Order of queries does not matter

	// If at the end some vertex has not appeared as the neighbour of some query, the graph cannot have all edges,
	// as it is then not connected to the last vertex we queried.
	// -> We are done once every vertex has appeared in a query

	// Since the order of operations doesn't matter, we may assume that we always make an operation on a vertex that has appeared in a query
	
	if (m == n*(n-1)/2) {
		cout << 0 << '\n';
		cout << '\n';
	} else {
		for (int i = 1; i < (1 << n); ++i) dp[i] = {INF, {-1, -1}};
		for (int i = 0; i < n; ++i) dp[1 << i] = {0, {-1, -1}};
		dp[0] = {0, {-1, -1}};

		for (int i = 1; i < (1 << n); ++i) {
			for (int j = 0; j < n; ++j) {
				if (i & (1 << j)) applyMin(dp[i | conns[j]], {dp[i].first + 1, {j, i}});
			}
		}

		int cur = (1 << n) - 1;
		cout << dp[cur].first << '\n';
		while(__builtin_popcount(cur) > 1) {
			cout << dp[cur].second.first + 1 << ' ';
			cur = dp[cur].second.second;
		}
		cout << '\n';
	}
}