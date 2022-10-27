#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n = abs(x2 - x1 + 1);
		int m = abs(y2 - y1 + 1);
		cout << (n - 1) * (m - 1) + 1 << "\n";
	}
    return 0;
}