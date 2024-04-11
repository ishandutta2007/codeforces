#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 2 * (ll)1e18;

const int N = 1000;
const int M = 1000;
const int C = 26;
ll dp[N+1][2];
ll sum[N+1][2];
int r[N];

ll calc(int n, int m) {
	// DP[a][k+1] = \sum_{b = r[a]}^{n} DP[b][k]
	for (int j = 0; j <= m; ++j) {
		sum[n][j & 1] = (j == 0);
		dp[n][j & 1] = (j == 0);
		for (int i = n-1; i >= 0; --i) {
			if (r[i] != -1 && j > 0) {
				dp[i][j & 1] = sum[r[i]][1 ^ (j & 1)];
			} else {
				dp[i][j & 1] = 0;
			}
			sum[i][j & 1] = min(INF, sum[i+1][j & 1] + dp[i][j & 1]);
		}
	}
	return dp[0][m & 1];
}

int check(int n, int m, ll k, const string& str, const string& tar) {
	for (int i = 0; i < n; ++i) {
		r[i] = i;
		for (int j = 0; j < tar.size(); ++j) {
			++r[i];
			if (str[i+j] != tar[j] || (i+j+1 == n && j+1 < tar.size())) {
				if (str[i+j] <= tar[j]) r[i] = -1;
				break;
			}
		}
	}

	ll res = calc(n, m);

	if (res < k) return 1; // too large
	else return 0;
}

void order(int i, vector<pair<int, int>>& prs, vector<pair<int, int>>& res, const string& str) {
	if (prs.empty()) return;

	vector<pair<int, int>> buckets[C];
	for (int j = 0; j < prs.size(); ++j) {
		int ind = (str[prs[j].first + i] - 'a');
		buckets[ind].push_back(prs[j]);
	}
	prs.clear();
	prs.shrink_to_fit();
	
	for (int c = 0; c < C; ++c) {
		for (int j = 0; j < buckets[c].size(); ++j) {
			int len = buckets[c][j].second - buckets[c][j].first + 1;
			if (len <= i+1) {
				res.push_back(buckets[c][j]);
				buckets[c][j] = buckets[c].back();
				buckets[c].pop_back();
				--j;
			}
		}
		order(i+1, buckets[c], res, str);
	}
}

string getSubs(pair<int, int> pr, const string& str) {
	string tar;
	for (int j = pr.first; j <= pr.second; ++j) tar.push_back(str[j]);
	return tar;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	ll k;
	cin >> n >> m >> k;

	string str;
	cin >> str;

	vector<pair<int, int>> prs, ord;
	for (int a = 0; a < n; ++a) {
		for (int b = a; b < n; ++b) {
			prs.push_back({a, b});
		}
	}
	order(0, prs, ord, str);

	int low = 0;
	int high = (int)ord.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		string tar = getSubs(ord[mid], str);
		int comp = check(n, m, k, str, tar);
		if (comp == 1) high = mid - 1;
		else low = mid;
	}

	string res = getSubs(ord[low], str);
	cout << res << '\n';
}