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
		int n, r;
		cin >> n >> r;
		int c = 0;
		if(n <= r)
		{
			c++;
		}
		n = min(n - 1, r);
		cout << c + n * (n + 1) / 2 << "\n";
	}
    return 0;
}