#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
const int inf = 2147483647;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> wall(n - 1);
	int cur, prev;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (i > 0)
			wall[i - 1] = cur - prev;
		prev = cur;
	}
	
	vector<int> elephant(m);
	for (int i = 0; i < m; i++) {
		cin >> cur;
		if (i > 0)
			elephant[i - 1] = cur - prev;
		prev = cur;
	}
	elephant[m - 1] = inf;
	
	if (m == 1) {
		cout << n;
		return 0;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}

	vector<int> prefix(m);
	prefix[0] = 0;
	for (int i = 1; i < m; i++) {
		int j = prefix[i - 1];
		while ((j > 0) && (elephant[i] != elephant[j]))
			j = prefix[j - 1];
		if (elephant[i] == elephant[j])
			j++;
		prefix[i] = j;
	}

	int curp = prefix[m - 1], count = 0;
	for (int i = 0; i < n - 1; i++) {
		while((curp > 0) && (wall[i] != elephant[curp]))
			curp = prefix[curp - 1];
		if (wall[i] == elephant[curp])
			curp++;
		if (curp == m - 1)
			count++;
		//cout << curp << ' ';
	}

	cout << count;
}