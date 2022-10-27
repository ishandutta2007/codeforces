#include<bits/stdc++.h>
using namespace std;

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
		int a = abs(x1 - x2) + abs(y1 - y2);
		if(x1 != x2 && y1 != y2)
		{
			a += 2;
		}
		cout << a << "\n";
	}
	return 0;
}