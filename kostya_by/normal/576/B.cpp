#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 100100;

int n;
int p[MAX_N];
bool visited[MAX_N];

bool cmp(const vector<int> &a, const vector<int> &b) {
	return a.size() < b.size();
}

void solve() {
	scanf("%d", &n);

	int x = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);

		if (p[i] == i) {
			x = i;
		}
	}

	if (x != -1) {
		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			if (i != x) {
				cout << x << " " << i << "\n";
			}
		}
		return;
	}
	vector<vector<int> > cycles;

	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			continue;
		}

		int v = i;
		cycles.push_back(vector<int>());
		while (!visited[v]) {
			visited[v] = true;
			cycles.back().push_back(v);
			v = p[v];
		}
	}

	sort(cycles.begin(), cycles.end(), cmp);

	if (cycles[0].size() != 2) {
		cout << "NO\n";
		return;
	}
	vector<pair<int, int> > answer;
	answer.push_back(make_pair(cycles[0][0], cycles[0][1]));
	for (int i = 1; i < cycles.size(); i++) {
		if (cycles[i].size() % 2) {
			cout << "NO\n";
			return;
		}
		for (int v : cycles[i]) {
			answer.push_back(make_pair(cycles[0][0], v));
			swap(cycles[0][0], cycles[0][1]);
		}
	}

	cout << "YES\n";
	for (pair<int, int> a : answer) {
		cout << a.first << " " << a.second << "\n";
	}
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}