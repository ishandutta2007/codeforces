#include <iostream>
#include <vector>
using namespace std;

// Just resubmitting to see if there's now a test that breaks this

const int N = 15;
pair<int, pair<int, int>> pre[N+1][1<<N];
int dist[N+1][1<<N];

void brute(int n) {
	int mm = 1<<n;
	for (int i = 0; i < mm; ++i) pre[n][i] = {-2, {-1, -1}};
	pre[n][0] = {0, {-1, -1}};
	dist[n][0] = 0;
	
	vector<pair<int, pair<int, int>>> masks;
	for (int a = 0; a < n; ++a) {
		for (int d = 1; a + 2 * d < n; ++d) {
			int mask = 0;
			mask |= 1<<a;
			mask |= 1<<(a+d);
			mask |= 1<<(a+2*d);
			masks.push_back({mask, {a, d}});
		}
	}
	
	vector<int> que;
	que.push_back(0);

	for (int j = 0; j < que.size(); ++j) {
		int ms = que[j];
		for (auto pr : masks) {
			int mask = pr.first;
			int t = ms ^ mask;
			if (pre[n][t].first == -2) {
				que.push_back(t);
				pre[n][t] = {ms, pr.second};
				dist[n][t] = dist[n][ms] + 1;
			}
		}
	}
}

void apply(vector<int>& vals, vector<pair<int, int>>& ans, int a, int d) {
	vals[a] ^= 1;
	vals[a-d] ^= 1;
	vals[a-2*d] ^= 1;
	ans.push_back({a-2*d, d});
}

int main() {
	// The number of allowed operations is very small
	// Almost all queries must flip three zeroes
	// For larger n, it is always possible (starting from 8)
	// flip all high bits, and brute the small ones
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
	}

	vector<pair<int, int>> ans;

	// Reduce size of the problem
	while(n > 13) {
		if (vals.back() == 0) {
			--n;
			vals.pop_back();
		} else {
			if (vals[n-1] == 1 && vals[n-2] == 1 && vals[n-3] == 0) {
				// 000 011
				vector<int> zc;
				for (int j = n-4; j >= n-6; --j) {
					if (vals[j]) zc.push_back(j);
				}

				if (zc.size() == 0) {
					apply(vals, ans, n-1, 1);
				} else if (zc.size() == 1) {
					apply(vals, ans, n-1, n-1 - zc[0]);
				} else if (zc.size() == 2) {
					apply(vals, ans, n-1, n-1 - zc[0]);
					apply(vals, ans, n-2, n-2 - zc[1]);
				} else {
					// 111 011
					apply(vals, ans, n-2, 2);
					// 010 001
					apply(vals, ans, n-1, 4);
				}
			} else {
				int d = 1;
				for (; d < 3; ++d) {
					if (vals[n-1-d]) break;
				}
				apply(vals, ans, n-1, d);
			}
		}
	}


	int rem = 0;
	for (int j = 0; j < n; ++j) {
		if (vals[j]) rem |= (1<<j);
	}

	brute(n);
	if (pre[n][rem].first == -2) {
		cout << "NO\n";
	} else {
		while(rem != 0) {
			ans.push_back(pre[n][rem].second);
			rem = pre[n][rem].first;
		}

		cout << "YES\n";
		cout << ans.size() << '\n';
		for (auto pr : ans) {
			++pr.first;
			cout << pr.first << ' ' << pr.first + pr.second << ' ' << pr.first + 2 * pr.second << '\n';
		}
	}
}