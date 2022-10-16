#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

pair<int, int> operator +(const pair<int, int> &p1, const pair<int, int> &p2) {
	return{ p1.first + p2.first, p1.second + p2.second };
}

bool check_inside(pair<int, int> p, int n, int m) {
	return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	pair<int, int> start;
	cin >> n >> m >> k;
	vector<vector<char> > a(n, vector<char>(m));
	vector<vector<int> > dp(n, vector<int>(m, -1));
	vector<pair<int, int> > moves{ {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
	string arr = "DLRU";
	string res = "";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j], start = a[i][j] == 'X' ? pair<int, int>{ i, j } : start;
	deque<pair<int, int> > d;
	d.push_back(start);
	dp[start.first][start.second] = 0;
	while (!d.empty()) {
		pair<int ,int> el = d[0];
		d.pop_front();
		for (int i = 0; i < 4; i++) {
			pair<int, int> cur_p = el + moves[i];
			if (check_inside(cur_p, n, m) && a[cur_p.first][cur_p.second] == '.' && dp[cur_p.first][cur_p.second] == -1) {
				dp[cur_p.first][cur_p.second] = dp[el.first][el.second] + 1;
				d.push_back(cur_p);
			}
		}
	}
	int old_k = k;
	for (int i = 0; i < old_k; i++) {
		for (int j = 0; j < 4; j++) {
			pair<int, int> cur_p = start + moves[j];
			if (check_inside(cur_p, n, m) && dp[cur_p.first][cur_p.second] >= 0 && dp[cur_p.first][cur_p.second] <= k - 1) {
				start = cur_p;
				res += arr[j];
				k--;
				break;
			}
			if (j == 3) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	if (res.size() < old_k || (old_k & 1)) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << res << endl;
	return 0;
}