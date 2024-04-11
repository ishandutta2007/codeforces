#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << "YES\n";
	for(int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << ((12 + 2 * (x1 % 2) + (y1 % 2)) % 4) + 1 << "\n";
	}
	return 0;
}