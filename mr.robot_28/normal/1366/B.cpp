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
		int n, x, m;
		cin >> n >> x >> m;
		x--;
		int left = x, right = x;
		for(int i = 0; i < m; i++)
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			if(l <= right && r >= left)
			{
				left = min(l, left);
				right = max(r, right);
			}
		}
		cout << right - left + 1 <<"\n";
	}
    return 0;
}