
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m[300000], p;
vector<int> v[300000];

int dfs(int x) {
	if(v[x].size() == 0) {
		return 1;
	}
	int M = 0;
	int t = m[x] ? INT_MAX : 0;
	for(unsigned int i = 0; i < v[x].size(); i++) {
		M = dfs(v[x][i]);
		if(m[x]) {
			t = min(t, M);
		}else {
			t += M;
		}
	}
	return t;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> m[i];
	}
	for(int i = 1; i < n; i++) {
		cin >> p;
		v[p - 1].push_back(i);
	}
	int k = 0;
	for(int i = 0; i < n; i++) {
		if(v[i].size() == 0) {
			k++;
		}
	}
	cout << (k - dfs(0) + 1) << endl;
}