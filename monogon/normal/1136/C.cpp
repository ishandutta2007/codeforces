
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a;

vector<int> v1[1000], v2[1000];

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a;
			v1[i + j].push_back(a);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a;
			v2[i + j].push_back(a);
		}
	}
	for(int i = 0; i < n + m - 1; i++) {
		sort(v1[i].begin(), v1[i].end());
		sort(v2[i].begin(), v2[i].end());
		if(v1[i] != v2[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}