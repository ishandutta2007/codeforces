#include<bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ans = 1e9;
    for(int i = 0; i < m; i++)
    {
    	int l, r;
    	cin >> l >> r;
    	ans = min(ans, r - l + 1);
    }
    cout << ans << "\n";
    for(int i = 0; i < n; i++)
    {
    	cout << i % ans << " ";
    }
	return 0;
}