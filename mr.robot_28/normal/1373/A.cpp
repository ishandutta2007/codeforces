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
		int a, b, c;
		cin >> a >> b >> c;
		if(c <= a)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << 1 << " ";
		}
		if(a * b > c)
		{
			cout << b << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
    return 0;
}