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
		int a, b, n, m;
		cin >> a >> b >> n >> m;
		if(min(a, b) < m || a + b < n + m)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
	}
    return 0;
}