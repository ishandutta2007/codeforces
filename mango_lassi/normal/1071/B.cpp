#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
const int INF = 1e9;

const int N = 2000;
char arr[N][N];
int dp[N][N];
pair<int, int> pre[N][N];
int n;

void offer(pair<int, int> t, pair <int, int> p) {
	int x = t.first;
	int y = t.second;
	if (x >= n || y >= n) return;
	int off = dp[p.first][p.second] + (arr[x][y] != 'a');
	if (off < dp[x][y]) {
		dp[x][y] = off;
		pre[x][y] = p;
	}
}

void helper(pair<int, int> t, pair<int, int> p, vector<pair<int, int>>& next_offs, char best) {
	int x = t.first;
	int y = t.second;
	if (x >= n || y >= n) return;
	if (dp[x][y] == -1) return;
	if (arr[x][y] != best) return;
	dp[x][y] = -1;
	pre[x][y] = p;
	next_offs.push_back(t);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> n >> k;
	for (int y = 0; y < n; ++y) {
		string row;
		cin >> row;
		for (int x = 0; x < n; ++x) arr[x][y] = row[x];
	}

	// 1. Find longest path with at most k non-a's
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			dp[x][y] = INF;
		}
	}

	int max_sum = 0;
	dp[0][0] = (arr[0][0] != 'a');
	pre[0][0] = {-1, -1};
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if (dp[x][y] <= k) max_sum = max(max_sum, x + y);
			offer({x+1, y}, {x, y});
			offer({x, y+1}, {x, y});
		}
	}

	// 2. Find rest of the path
	vector<pair<int, int>> offs;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if (dp[x][y] <= k && x+y == max_sum) offs.push_back({x, y});
		}
	}
	if (offs.empty()) offs.push_back({0, 0});

	for (; max_sum < 2 * (n-1); ++max_sum) {
		char best = 'z';
		for (auto pr : offs) {
			int x = pr.first;
			int y = pr.second;
			if (x+1 < n) best = min(best, arr[x+1][y]);
			if (y+1 < n) best = min(best, arr[x][y+1]);
		}
		vector<pair<int, int>> next_offs;
		for (auto pr : offs) {
			int x = pr.first;
			int y = pr.second;
			helper({x+1, y}, {x, y}, next_offs, best);
			helper({x, y+1}, {x, y}, next_offs, best);
		}
		offs = next_offs;
	}

	// 3. Produce answer
	string res(2*n - 1, 'z');
	pair<int, int> curr = {n-1, n-1};
	while(max_sum >= 0) {
		res[max_sum] = arr[curr.first][curr.second];
		curr = pre[curr.first][curr.second];
		--max_sum;
	}

	for (int i = 0; i < (int)res.size(); ++i) {
		if (res[i] != 'a' && k > 0) {
			res[i] = 'a';
			--k;
		}
	}

	cout << res << '\n';
}