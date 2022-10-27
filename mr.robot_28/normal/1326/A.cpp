
#include <iostream>
#include<vector>
#include<map>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << 2;
			for (int i = 1; i < n; i++) {
				cout << 3;
			}
			cout << "\n";
		}
	}
	return 0;
}