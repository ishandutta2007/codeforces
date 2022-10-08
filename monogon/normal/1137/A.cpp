
#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>

using namespace std;

int n, m, a[1000][1000];
set<int> cols[1000], rows[1000];
vector<int> vcols[1000], vrows[1000];

int search(vector<int> const& v, int val) {
	int l = 0;
	int r = v.size() - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		if(v[m] == val) {
			return m;
		}else if(v[m] < val) {
			l = m + 1;
		}else {
			r = m - 1;
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];

			vrows[i].push_back(a[i][j]);
			vcols[j].push_back(a[i][j]);
//			rows[i].insert(a[i][j]);
//			cols[j].insert(a[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		sort(vrows[i].begin(), vrows[i].end());
		vrows[i].erase(unique(vrows[i].begin(), vrows[i].end()), vrows[i].end());
	}
	for(int j = 0; j < m; j++) {
		sort(vcols[j].begin(), vcols[j].end());
		vcols[j].erase(unique(vcols[j].begin(), vcols[j].end()), vcols[j].end());
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int l = search(vrows[i], a[i][j]);
			int r = search(vcols[j], a[i][j]);
			cout << (max(l, r) + max(vrows[i].size() - l, vcols[j].size() - r)) << " ";
		}
		cout << endl;
	}
}