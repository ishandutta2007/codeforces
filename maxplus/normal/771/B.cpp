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

vector<vector<int> > v;
vector<bool> was;
int q = true;

int dfs(int ver, int val) {
	if (was[ver])
		return 0;
	if (v[ver].size() != val)
		q = false;
	was[ver] = true;
	int res = 1;
	for (auto x : v[ver])
		res += dfs(x, val);
	return res;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n - k + 1);
	vector<string> res(n);
	for (int i = 0; i < n - k + 1; i++) {
		string s;
		cin >> s;
		arr[i] = (s == "NO" ? 0 : 1);
	}
	int ind = 0;
	for (int i = 0; i < n - k + 1; i++) {
		if (arr[i] == 0)
			if (res[i] == "")
				res[i + k - 1] = res[i] = string(1, 'A' + ind++);
			else
				res[i + k - 1] = res[i];
	}
	for (int i = 0; i < n; i++) {
		if (res[i] == "") {
			res[i] = string(1, 'A' + i / 26) + string(1, 'a' + i % 26);
		}
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
}