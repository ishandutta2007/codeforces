#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	int n, cur;
	cin >> n;
	vector<vector<int> > people(3);
	for (int i = 0; i < n; i++) {
		cin >> cur;
		people[cur - 1].push_back(i + 1);
	}

	int res = 1000000000;
	for (int i = 0; i < 3; i++)
		res = min(res, (int)people[i].size());
	cout << res << '\n';
	for (int i = 0; i < res; i++)
		for (int j = 0; j < 3; j++)
			cout << people[j][i] << (j == 2 ? '\n' : ' ');

	return 0;
}