#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector<int> tp(n - 1);
	vector<bool> acc(n, false);
	acc[0] = true;
	for (int i = 0; i < n - 1; i++)
		cin >> tp[i];
	for (int i = 0; i < n - 1; i++)
		if (acc[i])
			acc[i + tp[i]] = true;
	cout << (acc[t - 1] ? "YES" : "NO");
	return 0;
}